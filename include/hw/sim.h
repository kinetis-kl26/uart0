// © 2011. Ravi Teja Gudapati. All rights reserved.

#ifndef INCLUDE_HW_SIM_H_
#define INCLUDE_HW_SIM_H_

#include "hw/common.h"

/// SIM - Register Layout Typedef
typedef struct {
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1CFG;                          /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t SOPT2;                             /**< System Options Register 2, offset: 0x1004 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SOPT4;                             /**< System Options Register 4, offset: 0x100C */
  __IO uint32_t SOPT5;                             /**< System Options Register 5, offset: 0x1010 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOPT7;                             /**< System Options Register 7, offset: 0x1018 */
       uint8_t RESERVED_3[8];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
       uint8_t RESERVED_6[4];
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
       uint8_t RESERVED_7[156];
  __IO uint32_t COPC;                              /**< COP Control Register, offset: 0x1100 */
  __O  uint32_t SRVCOP;                            /**< Service COP, offset: 0x1104 */
} hw_sim_t;

enum {
	SIM_SOPT1_OSC32KSEL_Shift = 18,
	SIM_SOPT1_OSC32KSEL_Mask = 3 << SIM_SOPT1_OSC32KSEL_Shift,
	SIM_SOPT1_OSC32KSEL_OSC32KCLK = 0 << SIM_SOPT1_OSC32KSEL_Shift,
	SIM_SOPT1_OSC32KSEL_LPO = 3 << SIM_SOPT1_OSC32KSEL_Shift,


	SIM_SOPT2_UART0SRC_Shift = 26,
	SIM_SOPT2_UART0SRC_Mask = 3 << SIM_SOPT2_UART0SRC_Shift,
	SIM_SOPT2_UART0SRC_disabled = 0 << SIM_SOPT2_UART0SRC_Shift,
	SIM_SOPT2_UART0SRC_MCGxLLCLK = 1 << SIM_SOPT2_UART0SRC_Shift,
	SIM_SOPT2_UART0SRC_OSERCLK = 2 << SIM_SOPT2_UART0SRC_Shift,
	SIM_SOPT2_UART0SRC_MCGIRCLK = 3 << SIM_SOPT2_UART0SRC_Shift,

	SIM_SOPT2_PLLFLLSEL_Shift = 16,
	SIM_SOPT2_PLLFLLSEL_Mask = 3 << SIM_SOPT2_PLLFLLSEL_Shift,
	SIM_SOPT2_PLLFLLSEL_MCGFLLCLK = 0 << SIM_SOPT2_PLLFLLSEL_Shift,
	SIM_SOPT2_PLLFLLSEL_MCGPLLCLK = 1 << SIM_SOPT2_PLLFLLSEL_Shift,

	SIM_SCGC4_Uart0_Shift = 10,
	SIM_SCGC4_Uart0_Mask = 1 << SIM_SCGC4_Uart0_Shift,
	SIM_SCGC4_Uart1_Shift = 11,
	SIM_SCGC4_Uart1_Mask = 1 << SIM_SCGC4_Uart1_Shift,
	SIM_SCGC4_Uart2_Shift = 12,
	SIM_SCGC4_Uart2_Mask = 1 << SIM_SCGC4_Uart2_Shift,

	SIM_SOPT5_UART0TXSR_Mask = 3,
	SIM_SOPT5_UART0RXSR_Shift = 2,
	SIM_SOPT5_UART0RXSR_Mask = 1 << SIM_SOPT5_UART0RXSR_Shift,
	SIM_SOPT5_UART1TXSR_Shift = 4,
	SIM_SOPT5_UART1TXSR_Mask = 3 << SIM_SOPT5_UART1TXSR_Shift,
	SIM_SOPT5_UART1RXSR_Shift = 6,
	SIM_SOPT5_UART1RXSR_Mask = 1 << SIM_SOPT5_UART1RXSR_Shift,

	// Ports
	SIM_SCGC5_PORTA_Shift = 9,
	SIM_SCGC5_PORTA_Mask = 1 << SIM_SCGC5_PORTA_Shift,
	SIM_SCGC5_PORTB_Shift = 10,
	SIM_SCGC5_PORTB_Mask = 1 << SIM_SCGC5_PORTB_Shift,
	SIM_SCGC5_PORTC_Shift = 11,
	SIM_SCGC5_PORTC_Mask = 1 << SIM_SCGC5_PORTC_Shift,
	SIM_SCGC5_PORTD_Shift = 12,
	SIM_SCGC5_PORTD_Mask = 1 << SIM_SCGC5_PORTD_Shift,
	SIM_SCGC5_PORTE_Shift = 13,
	SIM_SCGC5_PORTE_Mask = 1 << SIM_SCGC5_PORTE_Shift,

	SIM_CLKDIV1_OUTDIV1_Shift = 28,
	SIM_CLKDIV1_OUTDIV1_Mask = 0xF << SIM_CLKDIV1_OUTDIV1_Shift,
	SIM_CLKDIV1_OUTDIV4_Shift = 16,
	SIM_CLKDIV1_OUTDIV4_Mask = 0x7 << SIM_CLKDIV1_OUTDIV4_Shift,
} hm_sim_fields_t;

volatile hw_sim_t * const volatile hw_sim = (hw_sim_t *) Memmap_SIM_Addr;

#endif /* INCLUDE_HW_SIM_H_ */
