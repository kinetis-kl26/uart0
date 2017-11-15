// � 2011. Ravi Teja Gudapati. All rights reserved.

#ifndef INCLUDE_HW_OSC_H_
#define INCLUDE_HW_OSC_H_

#include "types.h"
#include "hw/common.h"

/// OSC - Register Layout Typedef
typedef struct {
	/// OSC Control Register
  __IO uint8_t CR;
} OSC_Type;

volatile OSC_Type * const volatile hw_osc0 = (OSC_Type *) Memmap_OSC0_Addr;

enum {
	OSC_CR_ERCLKEN_Shift = 7,
	OSC_CR_ERCLKEN_Mask = 1 << OSC_CR_ERCLKEN_Shift,

	OSC_CR_EREFSTEN_Shift = 5,
	OSC_CR_EREFSTEN_Mask = 1 << OSC_CR_EREFSTEN_Shift,

	OSC_CR_SC2P_Shift = 3,
	OSC_CR_SC2P_Mask = 1 << OSC_CR_SC2P_Shift,

	OSC_CR_SC4P_Shift = 2,
	OSC_CR_SC4P_Mask = 1 << OSC_CR_SC4P_Shift,

	OSC_CR_SC8P_Shift = 1,
	OSC_CR_SC8P_Mask = 1 << OSC_CR_SC8P_Shift,

	OSC_CR_SC16P_Mask = 1,
} osc_fields_t;

/// MCG - Register Layout Typedef
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control 1 Register, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control 2 Register, offset: 0x1 */
  __IO uint8_t C3;                                 /**< MCG Control 3 Register, offset: 0x2 */
  __IO uint8_t C4;                                 /**< MCG Control 4 Register, offset: 0x3 */
  __IO uint8_t C5;                                 /**< MCG Control 5 Register, offset: 0x4 */
  __IO uint8_t C6;                                 /**< MCG Control 6 Register, offset: 0x5 */
  __IO uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_0[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_1[1];
  __IO uint8_t ATCVH;                              /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  __IO uint8_t ATCVL;                              /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  __IO uint8_t C7;                                 /**< MCG Control 7 Register, offset: 0xC */
  __IO uint8_t C8;                                 /**< MCG Control 8 Register, offset: 0xD */
  __I  uint8_t C9;                                 /**< MCG Control 9 Register, offset: 0xE */
  __I  uint8_t C10;                                /**< MCG Control 10 Register, offset: 0xF */
} MCG_Type;

volatile MCG_Type * const volatile hw_mcg = (MCG_Type *) Memamp_MCG_Addr;

enum {
	MCG_C1_CLKS_Shift = 6,
	MCG_C1_CLKS_Mask = 3 << MCG_C1_CLKS_Shift,
	MCG_C1_CLKS_xLL = 0 << MCG_C1_CLKS_Shift,
	MCG_C1_CLKS_Internal = 1 << MCG_C1_CLKS_Shift,
	MCG_C1_CLKS_External = 2 << MCG_C1_CLKS_Shift,

	MCG_C1_FRDIV_Shift = 3,
	MCG_C1_FRDIV_Mask = 7 << MCG_C1_FRDIV_Shift,

	MCG_C1_IREFS_Shift = 2,
	MCG_C1_IREFS_Mask = 1 << MCG_C1_IREFS_Shift,

	MCG_C1_IRCLKEN_Shift = 1,
	MCG_C1_IRCLKEN_Mask = 1 << MCG_C1_IRCLKEN_Shift,

	MCG_C2_RANGE_Shift = 4,
	MCG_C2_RANGE_Mask = 3 << MCG_C2_RANGE_Shift,
	MCG_C2_RANGE_LowFreq = 0 << MCG_C2_RANGE_Shift,
	MCG_C2_RANGE_HighFreq = 1 << MCG_C2_RANGE_Shift,
	MCG_C2_RANGE_VeryHighFreq = 2 << MCG_C2_RANGE_Shift,

	MCG_C2_HGO_Shift = 3,
	MCG_C2_HGO_Mask = 1 << MCG_C2_HGO_Shift,

	MCG_C2_EREFS0_Shift = 2,
	MCG_C2_EREFS0_Mask = 1 << MCG_C2_EREFS0_Shift,
	MCG_C2_EREFS0_extClk = 0 << MCG_C2_EREFS0_Shift,
	MCG_C2_EREFS0_extOsc = 1 << MCG_C2_EREFS0_Shift,

	MCG_C2_LP_Shift = 1,
	MCG_C2_LP_Mask = 1 << MCG_C2_LP_Shift,

	MCG_C2_IRCS_Mask = 1,

	MCG_C5_PRDIV0_Mask = 0x1F,

	MCG_C5_PLLCLKEN0_Shift = 6,
	MCG_C5_PLLCLKEN0_Mask = 1 << MCG_C5_PLLCLKEN0_Shift,

	MCG_C6_PLLS_Shift = 6,
	MCG_C6_PLLS_Mask = 1 << MCG_C6_PLLS_Shift,

	MCG_C6_VDIV0_Mask = 0x1F,

	MCG_S_LOCK0_Shift = 6,
	MCG_S_LOCK0_Mask = 1 << MCG_S_LOCK0_Shift,

	MCG_S_PLLST_Shift = 5,
	MCG_S_PLLST_Mask = 1 << MCG_S_PLLST_Shift,

	MCG_S_IREFST_Shift = 4,
	MCG_S_IREFST_Mask = 1 << MCG_S_IREFST_Shift,

	MCG_S_CLKST_Shift = 2,
	MCG_S_CLKST_Mask = 3 << MCG_S_CLKST_Shift,
	MCG_S_CLKST_FLL = 0 << MCG_S_CLKST_Shift,
	MCG_S_CLKST_Internal = 1 << MCG_S_CLKST_Shift,
	MCG_S_CLKST_External = 2 << MCG_S_CLKST_Shift,
	MCG_S_CLKST_PLL = 3 << MCG_S_CLKST_Shift,
	MCG_S_OSCINIT0_Shift = 1,
	MCG_S_OSCINIT0_Mask = 1 << MCG_S_OSCINIT0_Shift,
	MCG_S_IRCST_Mask = 1,
	MCG_S_IRCST_slow = 0,
	MCG_S_IRCST_fast = 1,

	MCG_SC_LOCS0_Mask = 1,
	MCG_SC_FCRDIV_Shift = 1,
	MCG_SC_FCRDIV_Mask = 0x7 << MCG_SC_FCRDIV_Shift,
	MCG_SC_ATMF_Shift = 5,
	MCG_SC_ATMF_Mask = 1 << MCG_SC_ATMF_Shift,

	MCG_C7_OSCSEL_Mask = 1,
} mcg_fields_t;

#endif /* INCLUDE_HW_OSC_H_ */
