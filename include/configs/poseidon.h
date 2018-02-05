/*
 * Copyright (C) 2017, WarOfDevil <warofdevil@linux.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/x86-common.h>

#define CONFIG_SYS_MONITOR_LEN		(1 << 20)

#define CONFIG_STD_DEVICES_SETTINGS	"stdin=serial,i8042-kbd\0" \
					"stdout=serial,vidconsole\0" \
					"stderr=serial,vidconsole\0"

#define CONFIG_USB_ETHER_ASIX88179

#define CONFIG_SCSI_AHCI
#define CONFIG_SCSI_DEV_LIST		\
	{PCI_VENDOR_ID_INTEL, 0x8c02}

#undef CONFIG_ENV_IS_IN_SPI_FLASH

#define DEBUG

#endif	/* __CONFIG_H */
