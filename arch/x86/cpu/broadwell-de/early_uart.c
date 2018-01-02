/*
 * Copyright (C) 2017, Vincenzo Bove <vincenzo.bove@prodrive-technologies.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/pci/pci.h>

#define UART_CONT		0x80
#define LPC_BUS			0
#define LPC_DEV		    0x1f 
#define LPC_FUNC		0

#define PORT 			0x3f8

/*
int is_transmit_empty() {
   return inb(PORT + 5) & 0x20;
}
 
void write_serial(char a) {
   while (is_transmit_empty() == 0);
 
   outb(PORT,a);
}

void printmessage(void)
{
   outb(PORT + 1, 0x00);    // Disable all interrupts
   outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outb(PORT + 0, 0x01);    // Set divisor to 1 (lo byte) 115200 baud
   outb(PORT + 1, 0x00);    //                  (hi byte)
   outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
 
   write_serial('t');
}
*/
void board_debug_uart_init(void)
{
	//UART ENABLE
	//PCIAddress *lpc = 0;
	//lpc->bus = LPC_BUS;
	//lpc->device = LPC_DEV;
	//lpc->function = LPC_FUNC;
    
    //IO_Out32(0xcf8, 2147547276);
    //IO_Out32(0xcfc, 1 << 4);

    //IO_Out32(0xcf8, 2147547278);
    //IO_Out32(0xcfc, 1 << 0);

	//printmessage();
}
