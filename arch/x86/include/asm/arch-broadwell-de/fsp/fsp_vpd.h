/*
 * Copyright (C) 2017, WarOfDevil <warofdevil@linux.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __FSP_VPD_H
#define __FSP_VPD_H

struct __packed upd_region {
  uint64_t     signature;                	  /**Offset 0x0000 **/     
  uint64_t     reserved;                      /**Offset 0x0008 **/   
  uint8_t      unusedUpdSpace0[16];           /**Offset 0x0010 **/
  uint8_t      serialPortType;                /**Offset 0x0020  **/
  uint32_t     serialPortAddress;             /**Offset 0x0021  **/
  uint8_t      serialPortConfigure;           /**Offset 0x0025  **/
  uint8_t      serialPortBaudRate;            /**Offset 0x0026  **/
  uint8_t      serialPortControllerInit0;     /**Offset 0x0027  **/
  uint8_t      serialPortControllerInit1;     /**Offset 0x0028  **/
  uint8_t      configIOU1_PciPort3;           /**Offset 0x0029  **/
  uint8_t      configIOU2_PciPort1;           /**Offset 0x002A **/
  uint8_t      powerStateAfterG3;             /**Offset 0x002B  **/
  uint8_t      pchPciPort1;                   /**Offset 0x002C **/
  uint8_t      pchPciPort2;                   /**Offset 0x002D  **/
  uint8_t      pchPciPort3;                   /**Offset 0x002E  **/
  uint8_t      pchPciPort4;                   /**Offset 0x002F **/
  uint8_t      pchPciPort5;                   /**Offset 0x0030  **/
  uint8_t      pchPciPort6;       			  /**Offset 0x0031 **/
  uint8_t      pchPciPort7;                   /**Offset 0x0032 **/
  uint8_t      pchPciPort8;				 	  /**Offset 0x0033 **/
  uint8_t      hotPlug_PchPciPort1;           /**Offset 0x0034 **/
  uint8_t      hotPlug_PchPciPort2;       	  /**Offset 0x0035 **/
  uint8_t      hotPlug_PchPciPort3;           /**Offset 0x0036 **/
  uint8_t      hotPlug_PchPciPort4;           /**Offset 0x0037 **/
  uint8_t      hotPlug_PchPciPort5;           /**Offset 0x0038 **/
  uint8_t      hotPlug_PchPciPort6;           /**Offset 0x0039 **/
  uint8_t      hotPlug_PchPciPort7;           /**Offset 0x003A **/
  uint8_t      hotPlug_PchPciPort8;           /**Offset 0x003B **/
  uint8_t      ehci1Enable;                   /**Offset 0x003C **/
  uint8_t      ehci2Enable;                   /**Offset 0x003D **/
  uint8_t      hyperThreading;                /**Offset 0x003E **/
  uint8_t      debugOutputLevel;              /**Offset 0x003F **/
  uint8_t      tcoTimerHaltLock;              /**Offset 0x0040 **/
  uint8_t      turboMode;                     /**Offset 0x0041 **/
  uint8_t      bootPerfMode;                  /**Offset 0x0042 **/
  uint8_t      pciePort1aAspm;                /**Offset 0x0043 **/
  uint8_t      pciePort1bAspm;                /**Offset 0x0044 **/
  uint8_t      pciePort3aAspm;                /**Offset 0x0045 **/
  uint8_t      pciePort3bAspm;                /**Offset 0x0046 **/
  uint8_t      pciePort3cAspm;                /**Offset 0x0047 **/
  uint8_t      pciePort3dAspm;                /**Offset 0x0048 **/
  uint8_t      pchPciePort1Aspm;              /**Offset 0x0049 **/
  uint8_t      pchPciePort2Aspm;              /**Offset 0x004A **/
  uint8_t      pchPciePort3Aspm;              /**Offset 0x004B **/
  uint8_t      pchPciePort4Aspm;              /**Offset 0x004C **/
  uint8_t      pchPciePort5Aspm;              /**Offset 0x004D **/
  uint8_t      pchPciePort6Aspm;              /**Offset 0x004E **/
  uint8_t      pchPciePort7Aspm;              /**Offset 0x004F **/
  uint8_t      pchPciePort8Aspm;              /**Offset 0x0050 **/
  uint8_t      dFXEnable;                     /**Offset 0x0051 **/
  uint8_t      thermalDeviceEnable;           /**Offset 0x0052 **/
  uint8_t      unusedUpdSpace1[88];           /**Offset 0x0053 **/
  uint8_t      memEccSupport;                 /**Offset 0x00AB **/
  uint8_t      memDdrMemoryType;              /**Offset 0x00AC **/
  uint8_t      memRankMultiplication;         /**Offset 0x00AD **/
  uint8_t      memRankMarginTool;             /**Offset 0x00AE **/
  uint8_t      memScrambling;                 /**Offset 0x00AF **/
  uint8_t      memRefreshMode;                /**Offset 0x00B0 **/
  uint8_t      memMcOdtOverride;              /**Offset 0x00B1 **/
  uint8_t      memCAParity;                   /**Offset 0x00B2 **/
  uint8_t      memThermalThrottling;          /**Offset 0x00B3 **/
  uint8_t      memPowerSavingsMode;           /**Offset 0x00B4 **/
  uint8_t      memElectricalThrottling;       /**Offset 0x00B5 **/
  uint8_t      memPagePolicy;                 /**Offset 0x00B6 **/
  uint8_t      memSocketInterleaveBelow4G;    /**Offset 0x00B7 **/
  uint8_t      memChannelInterleave;          /**Offset 0x00B8 **/
  uint8_t      memRankInterleave;             /**Offset 0x00B9 **/
  uint8_t      memDownEnable;                 /**Offset 0x00BA **/
  uint32_t     memDownCh0Dimm0SpdPtr;         /**Offset 0x00BB **/
  uint32_t     memDownCh0Dimm1SpdPtr;         /**Offset 0x00BF **/
  uint32_t     memDownCh1Dimm0SpdPtr;         /**Offset 0x00C3 **/
  uint32_t     memDownCh1Dimm1SpdPtr;         /**Offset 0x00C7 **/
  uint8_t      memFastBoot;                   /**Offset 0x00CB **/
  uint8_t      pam0_hienable;                 /**Offset 0x00CC **/
  uint8_t      pam1_loenable;                 /**Offset 0x00CD **/
  uint8_t      pam1_hienable;                 /**Offset 0x00CE **/
  uint8_t      pam2_loenable;                 /**Offset 0x00CF **/
  uint8_t      pam2_hienable;                 /**Offset 0x00D0 **/
  uint8_t      pam3_loenable;                 /**Offset 0x00D1 **/
  uint8_t      pam3_hienable;                 /**Offset 0x00D2 **/
  uint8_t      pam4_loenable;                 /**Offset 0x00D3 **/
  uint8_t      pam4_hienable;                 /**Offset 0x00D4 **/
  uint8_t      pam5_loenable;                 /**Offset 0x00D5 **/
  uint8_t      pam5_hienable;                 /**Offset 0x00D6 **/
  uint8_t      pam6_loenable;                 /**Offset 0x00D7 **/
  uint8_t      pam6_hienable;                 /**Offset 0x00D8 **/
  uint8_t      memAdr;                        /**Offset 0x00D9 **/
  uint8_t      memAdrResumePath;              /**Offset 0x00DA **/
  uint8_t      memBlockScTrafficOnAdr;        /**Offset 0x00DB **/
  uint16_t     memPlatformReleaseAdrClampsPort;/**Offset 0x00DC **/
  uint32_t     memPlatformReleaseAdrClampsAnd; /**Offset 0x00DE **/
  uint32_t     memPlatformReleaseAdrClampsOr; /**Offset 0x00E2 **/
  uint8_t      unusedUpdSpace2[24];           /**Offset 0x00E6 **/
  uint16_t	   terminator;					  /**Offset 0x00FE **/
};

#define VPD_IMAGE_ID		0x5F45442D5844425F	/* '_BDX-DE_' */

struct __packed vpd_region {
	uint64_t 	sign;						/* Offset 0x0000 */
	uint32_t	img_rev;					/* Offset 0x0008 */
	uint32_t 	upd_offset;					/* Offset 0x000c */
	uint8_t 	unused[16];					/* Offset 0x0010 */
	uint32_t 	fsp_res_memlen;				/* Offset 0x0020 */
};
#endif
