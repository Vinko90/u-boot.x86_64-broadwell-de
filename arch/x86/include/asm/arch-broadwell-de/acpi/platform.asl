/*
 * Copyright (C) 2016, Bin Meng <bmeng.cn@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/acpi/statdef.asl>
#include <asm/arch/iomap.h>
#include <asm/arch/irq.h>


/* The APM port can be used for generating software SMIs */

OperationRegion (APMP, SystemIO, 0xb2, 2)
Field (APMP, ByteAcc, NoLock, Preserve)
{
	APMC, 8,	// APM command
	APMS, 8		// APM status
}

/* Port 80 POST */

OperationRegion (POST, SystemIO, 0x80, 1)
Field (POST, ByteAcc, Lock, Preserve)
{
	DBG0, 8
}

Name(\APC1, Zero) // IIO IOAPIC

Name(\PICM, Zero) // IOAPIC/8259

Method(_PIC, 1)
{
	Store(Arg0, PICM)
}

/* The _PTS method (Prepare To Sleep) is called before the OS is
 * entering a sleep state. The sleep state number is passed in Arg0
 */

Method(_PTS,1)
{
}

/* The _WAK method is called on system wakeup */

Method(_WAK,1)
{
	Return(Package(){0,0})
}

/* ACPI global NVS */
//#include "irqlinks.asl"

Scope (\_SB)
{
	#include "southcluster.asl"

	#include "pcie1.asl"
}
