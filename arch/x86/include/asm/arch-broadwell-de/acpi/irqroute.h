/*
 * Copyright (C) 2017, WarOfDevil <warofdevil@linux.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/arch/device.h>

#define PCI_DEV_PIRQ_ROUTES \
		PCI_DEV_PIRQ_ROUTE(XHCI_DEV,  A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(ME_DEV,    A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(GBE_DEV,   A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(HDA_DEV,   A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(PCIE_DEV,  A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(EHCI1_DEV, A, B, C, D), \
		PCI_DEV_PIRQ_ROUTE(SATA_DEV,  A, B, C, D)

/*
* Route each PIRQ[A-H] to a PIC IRQ[0-15]
* Reserved: 0, 1, 2, 8, 13
* ACPI/SCI: 9
*/
#define PIRQ_PIC_ROUTES \
		PIRQ_PIC(A,  5), \
		PIRQ_PIC(B,  6), \
		PIRQ_PIC(C,  7), \
		PIRQ_PIC(D, 10), \
		PIRQ_PIC(E, 11), \
		PIRQ_PIC(F, 12), \
		PIRQ_PIC(G, 14), \
		PIRQ_PIC(H, 15)
