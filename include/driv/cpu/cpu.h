// © 2011. Ravi Teja Gudapati. All rights reserved.

#ifndef INCLUDE_DRIV_CPU_CPU_H_
#define INCLUDE_DRIV_CPU_CPU_H_

#include "types.h"

/// Enables all interrupts
__attribute__( ( always_inline ) )
static inline void cpu_enable_interrupts(void) {
	asm volatile ("cpsie i" : : : "memory");
}

/// Disables all interrupts
__attribute__( ( always_inline ) )
static inline void cpu_disable_interrupts(void) {
	asm volatile ("cpsid i" : : : "memory");
}

/// Returns if the interrupts are disabled
///
/// \returns Status indicating if the interrupts are disabled
__attribute__( ( always_inline ) )
static inline bool_t cpu_are_interrupts_disabled(void) {
    uint32_t primask = 0;
    asm volatile("mrs %0, PRIMASK\n" : "=r" (primask) : : "memory");
    return primask & 1;
}

enum {
	/// Output frequency of oscillator
	System_XTAL_CLK_Freq = 8000000U,

	/// OSCCLK in Clocking diagram in RM Figure 6-1.
	System_OSCCLK_Freq = System_XTAL_CLK_Freq,

	System_OSCERCLK_Freq = System_XTAL_CLK_Freq,

	/// Core clock of 150MHz
	///
	/// System (CPU) clock in Clocking diagram in RM Figure 6-1.
	/// Equivalent to SystemCoreClock in CMSIS
	System_CoreCLK_Freq = 48000000U,

	System_BusFlashCLK_Freq = 24000000,
} System_values_t;

/// Pre initialization
extern void cpu_preinit(void);

/// Initializes CPU, PLL, clocks, cache, GPIO, timers, etc
///
/// Initializes clock, PLL, cache etc
extern void cpu_init(void);

/// \brief Resets the processor
extern void cpu_reset(void);

#endif /* INCLUDE_DRIV_CPU_CPU_H_ */
