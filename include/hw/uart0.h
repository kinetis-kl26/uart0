// © 2011. Ravi Teja Gudapati. All rights reserved.

#ifndef INCLUDE_HW_UART0_H_
#define INCLUDE_HW_UART0_H_

#include "types.h"
#include "hw/common.h"

/// UART0 - Register Layout Typedef
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __IO uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
  __IO uint8_t MA1;                                /**< UART Match Address Registers 1, offset: 0x8 */
  __IO uint8_t MA2;                                /**< UART Match Address Registers 2, offset: 0x9 */
  __IO uint8_t C4;                                 /**< UART Control Register 4, offset: 0xA */
  __IO uint8_t C5;                                 /**< UART Control Register 5, offset: 0xB */
} hw_uart0_t;

enum {
	Uart_BDH_SBNS_Shift = 5,
	Uart_BDH_SBNS_Mask = 1 << Uart_BDH_SBNS_Shift,

	Uart_BDH_SBR_Mask = 0x1F,

	Uart_C1_PT_Mask = 1,

	Uart_C1_PE_Shift = 1,
	Uart_C1_PE_Mask = 1 << Uart_C1_PE_Shift,

	Uart_C1_M_Shift = 4,
	Uart_C1_M_Mask = 1 << Uart_C1_M_Shift,

	Uart_C2_TIE_Shift = 7,
	Uart_C2_TIE_Mask = 1 << Uart_C2_TIE_Shift,

	Uart_C2_TCIE_Shift = 6,
	Uart_C2_TCIE_Mask = 1 << Uart_C2_TCIE_Shift,

	Uart_C2_RIE_Shift = 5,
	Uart_C2_RIE_Mask = 1 << Uart_C2_RIE_Shift,

	Uart_C2_TE_Shift = 3,
	Uart_C2_TE_Mask = 1 << Uart_C2_TE_Shift,

	Uart_C2_RE_Shift = 2,
	Uart_C2_RE_Mask = 1 << Uart_C2_RE_Shift,

	Uart_S1_TDRE_Shift = 7,
	Uart_S1_TDRE_Mask = 1 << Uart_S1_TDRE_Shift,

	Uart_S1_TC_Shift = 6,
	Uart_S1_TC_Mask = 1 << Uart_S1_TC_Shift,

	Uart_S1_RDRF_Shift = 5,
	Uart_S1_RDRF_Mask = 1 << Uart_S1_RDRF_Shift,

	Uart_S1_OR_Shift = 3,
	Uart_S1_OR_Mask = 1 << Uart_S1_OR_Shift,

	Uart_S1_FE_Shift = 1,
	Uart_S1_FE_Mask = 1 << Uart_S1_FE_Shift,

	Uart_S1_PF_Mask = 1,

	Uart_C3_ORIE_Shift = 3,
	Uart_C3_ORIE_Mask = 1 << Uart_C3_ORIE_Shift,

	Uart_C3_FEIE_Shift = 1,
	Uart_C3_FEIE_Mask = 1 << Uart_C3_FEIE_Shift,

	Uart_C3_PEIE_Mask = 1,

	Uart_C4_OSR_Mask = 0x1F,
} hw_uart0_fields_t;

volatile hw_uart0_t * const volatile hw_uart0 = (hw_uart0_t *) Memmap_UART0_Addr;

#endif /* INCLUDE_HW_UART0_H_ */
