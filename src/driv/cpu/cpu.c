// © 2011. Ravi Teja Gudapati. All rights reserved.

///
/// OScillator 0 is run by EXTAL external clock source.
/// Use EXTAL as source to OSCCLK
/// Select external clock (OSCCLK/FRDIV) as clock source to FLL
/// Select PLL as source to MCGOUTCLK
///
/// Oscillator:
/// XTAL_CLK = EXTAL = 8MHz
/// OSCCLK = EXTAL
/// OSCERCLK = OSCCLK/1 = 8MHz
///
/// MCG_FLL:
/// FRDIV = 32
/// FLL = OSCCLK/FRDIV = 250000
///
/// MCG_PLL:
/// VDIV = 24
/// PRDIV = 1
/// PLL = (OSCCLK * VDIV)/(PRDIV * 2) = 96000000
///
/// MCG_MCGOUTCLK:
/// MCGOUTCLK = PLL
///
/// SIM:
/// CoreCLK = MCGOUTCLK/OUTDIV1 = MCGOUTCLK/2 = 48000000
/// BusFlashCLK = CoreCLK/OUTDIV4 = CoreCLK/2 = 24000000
///

#include "driv/cpu/cpu.h"
#include "hw/sim.h"
#include "hw/osc.h"

static uint8_t priv_get_oscRangeFromFreq(uint32_t const freq) {
	uint8_t range;

	if (freq <= 39063U) {
		range = 0U;
	} else if (freq <= 8000000U) {
		range = 1U;
	} else {
		range = 2U;
	}

	return range;
}

/// Initializes oscillator, OSCCLK and OSCERCLK
///
/// OSCERCLK powers several on-chip peripherals (non-fast peripherals) on MKL26..
/// It continues to work in low power mode.
///
/// Sets capacitor load to 0 pF
/// Enables OSCERCLK
/// Selects external oscillator as source to OSCCLK
static inline void priv_init_osc(void) {
	// Sets the capacitor load configuration to 0pF
	hw_osc0->CR &= ~(OSC_CR_SC2P_Mask | OSC_CR_SC4P_Mask | OSC_CR_SC8P_Mask
			| OSC_CR_SC16P_Mask);
	hw_osc0->CR &= ~OSC_CR_EREFSTEN_Mask;

	// Enable OSCERCLK
	hw_osc0->CR |= OSC_CR_ERCLKEN_Mask;

	// Select crystal oscillator frequency range
	const uint8_t range = priv_get_oscRangeFromFreq(System_XTAL_CLK_Freq);
	hw_mcg->C2 &= ~MCG_C2_RANGE_Mask;
	hw_mcg->C2 |= range << MCG_C2_RANGE_Shift;

	// Select source of OSCCLK
	// External oscillator is selected as source to OSCCLK
	hw_mcg->C2 |= MCG_C2_EREFS0_extOsc;

	// Wait for Oscillator to stabilize
	while (!(hw_mcg->S & MCG_S_OSCINIT0_Mask))
		;
}

/// Initialize FLL
static inline void priv_init_fll(void) {
	/// FRDIV = 0; FLL = 8000000/32 = 250000Hz
	hw_mcg->C1 &= ~MCG_C1_FRDIV_Mask;

	// Set PEE mode
	// Disable low power
	hw_mcg->C2 &= ~MCG_C2_LP_Mask;

	// Select OSCCLK/FRDIV as source clock to FFL
	hw_mcg->C1 &= ~MCG_C1_IREFS_Mask;

	// Wait for changes to commit
	while ((hw_mcg->S & MCG_S_IREFST_Mask) != 0)
		;
}

static inline void priv_init_pll(void) {
	// Temporarily, use external reference clock as MCGOUTCLK
	hw_mcg->C1 &= ~MCG_C1_CLKS_Mask;
	hw_mcg->C1 |= MCG_C1_CLKS_External;
	// Wait for changes to commit
	while ((hw_mcg->S & MCG_S_CLKST_Mask) != MCG_S_CLKST_External)
		;

	// Temporarily, switch PLLS to FLL
	hw_mcg->C6 &= ~MCG_C6_PLLS_Mask;
	// Wait for changes to commit
	while ((hw_mcg->S & MCG_S_PLLST_Mask) != 0)
		;

	// Configure PLL
	{
		// PRDIV = 0x1; PLLCLKEN = 0;
		hw_mcg->C5 = 0x1;
		hw_mcg->C6 &= ~MCG_C6_VDIV0_Mask;
		// VDIV = 0x0
		hw_mcg->C6 |= 0x0;
		// Enable PLL
		hw_mcg->C5 |= MCG_C5_PLLCLKEN0_Mask;

		// Wait for PLL to lock
		while ((hw_mcg->S & MCG_S_LOCK0_Mask) != MCG_S_LOCK0_Mask)
			;
	}

	// Switch PPLS to PLL
	hw_mcg->C6 |= MCG_C6_PLLS_Mask;
	// Wait for MCGOUTCLK to change to PLL
	while ((hw_mcg->S & MCG_S_PLLST_Mask) == 0)
		;

	/// Select FLL/PLL as source of MCGOUTCLK
	hw_mcg->C1 &= ~MCG_C1_CLKS_Mask;
	hw_mcg->C1 |= MCG_C1_CLKS_xLL;

	// Wait for changes to commit
	while ((hw_mcg->S & MCG_S_CLKST_Mask) != MCG_S_CLKST_PLL)
		;
}

/// Configure the Internal reference clock (MCGIRCLK)
static void priv_setup_internalRefClk(void) {
	// FCRDIV = 0
	hw_mcg->SC &= ~(MCG_SC_ATMF_Mask | MCG_SC_FCRDIV_Mask | MCG_SC_LOCS0_Mask);

	// Select slow internal clock as source to MCGIRCLK
	hw_mcg->C2 &= ~MCG_C2_IRCS_Mask;

	// Disable MCGIRCLK
	hw_mcg->C1 &= ~MCG_C1_IRCLKEN_Mask;

	// Wait for changes to commit
	while ((hw_mcg->S & MCG_S_IRCST_Mask) != MCG_S_IRCST_slow)
		;
}

/// Configure clock dividers and peripheral clock selectors in SIM
static inline void priv_init_sim(void) {
	// OUTDIV1: /1; OUTDIV4: /1
	hw_sim->CLKDIV1 = 0x10010000;

	// Select PLL as clock source for ethernet module
	hw_sim->SOPT2 &= ~SIM_SOPT2_PLLFLLSEL_Mask;
	hw_sim->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MCGPLLCLK;

	// Select LPO as clock for LPTMR
	hw_sim->SOPT1 &= ~SIM_SOPT1_OSC32KSEL_Mask;
	hw_sim->SOPT1 |= SIM_SOPT1_OSC32KSEL_LPO;
}

/// Sets up system clock
static void priv_setup_clocks(void) {
	// Set the system clock dividers in SIM to safe value
	hw_sim->CLKDIV1 = 0x10030000U;

	// Initializes OSC0 according to board configuration
	priv_init_osc();
	priv_init_fll();
	priv_init_pll();
	// Setup internal reference clock
	priv_setup_internalRefClk();
	priv_init_sim();
}

void cpu_init(void) {
	priv_setup_clocks();
}

void cpu_preinit(void) {
	// Disable watchdog
	// SIM_COPC: COPT=0,COPCLKS=0,COPW=0
	hw_sim->COPC = (uint32_t) 0x00u;
}

void cpu_reset(void) {
	// TODO
}
