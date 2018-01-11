/*
 * Copyright (C) 2017, Vincenzo Bove <vincenzo.bove@prodrive-technologies.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/* PCI Interrupt Routing */
Method(_PRT)
{
	/*
	 * PICM comes from _PIC, which returns the following:
	 * 0 - PIC mode
	 * 1 - APIC mode
	 * 2 - SAPIC mode
	 */
	If (PICM) {
		Return (Package() {
			#undef PIC_MODE
			#include "irq_helper.h"
			PCI_DEV_PIRQ_ROUTES
		})
	} Else {
		Return (Package() {
			#define PIC_MODE
			#include "irq_helper.h"
			PCI_DEV_PIRQ_ROUTES
		})
	}
}
