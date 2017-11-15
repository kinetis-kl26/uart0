// © 2011. Ravi Teja Gudapati. All rights reserved.

#ifndef INCLUDE_HW_PORT_H_
#define INCLUDE_HW_PORT_H_

#include "hw/common.h"
#include "types.h"

/// PORT - Register Layout Typedef
typedef struct {
  __IO uint32_t PCR[32];                           /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8_t RESERVED_0[24];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
} hw_port_t;

typedef enum _port_mux {
	Port_PinDisabledOrAnalog = 0U, /*!< Corresponding pin is disabled, but is used as an analog pin. */
	Port_MuxAsGpio = 1U, /*!< Corresponding pin is configured as GPIO. */
	Port_MuxAlt2 = 2U, /*!< Chip-specific */
	Port_MuxAlt3 = 3U, /*!< Chip-specific */
	Port_MuxAlt4 = 4U, /*!< Chip-specific */
	Port_MuxAlt5 = 5U, /*!< Chip-specific */
	Port_MuxAlt6 = 6U, /*!< Chip-specific */
	Port_MuxAlt7 = 7U, /*!< Chip-specific */
} port_mux_t;

enum {
	PORT_PCR_PE_Shift = 1U,
	PORT_PCR_PE_Mask = 1 << PORT_PCR_PE_Shift,

	PORT_PCR_PS_Mask = 1,
	PORT_PCR_PS_Down = 0,
	PORT_PCR_PS_Up = 1,

	PORT_PCR_MUX_Shift = 8,
	PORT_PCR_MUX_Mask = 0x7 << PORT_PCR_MUX_Shift,

	PORT_PCR_IRQC_Shift = 16,
	PORT_PCR_IRQC_Mask = 0xF << PORT_PCR_IRQC_Shift,
} hw_port_dummy_enums_t;

volatile hw_port_t * const volatile hw_portA = (hw_port_t *) Memmap_PORTA_Addr;

volatile hw_port_t * const volatile hw_portB = (hw_port_t *) Memmap_PORTB_Addr;

volatile hw_port_t * const volatile hw_portC = (hw_port_t *) Memmap_PORTC_Addr;

volatile hw_port_t * const volatile hw_portD = (hw_port_t *) Memmap_PORTD_Addr;

volatile hw_port_t * const volatile hw_portE = (hw_port_t *) Memmap_PORTE_Addr;

#endif /* INCLUDE_HW_PORT_H_ */
