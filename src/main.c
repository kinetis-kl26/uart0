// © 2011. Ravi Teja Gudapati. All rights reserved.

#include "driv/cpu/cpu.h"
#include "driv/uart0/uart0.h"

int main(void) {
	// Initialize CPU
	cpu_init();

	// Initialize UART0
	uart0_init(Uart_Baudrate_4800);

	while(1) {
		// Repeatedly print '5's to annoy the user :D
		uart0_putc('5');
	}

	return 0;
}
