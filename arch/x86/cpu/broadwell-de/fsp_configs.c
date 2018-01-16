/*
 * Copyright (C) 2017, Vincenzo Bove <vincenzo.bove@prodrive-technologies.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <fdtdec.h>
#include <asm/fsp/fsp_support.h>
//#include <asm/arch/spd.h>

#define CONFIG_FSP_MEMORY_DOWN 1

DECLARE_GLOBAL_DATA_PTR;

/**
 * Override the FSP's configuration data.
 * If the device tree does not specify an integer setting, use the default
 * provided by Prodrive BroadwellDE.rom
 */
void update_fsp_configs(struct fsp_config_data *config,
			struct fspinit_rtbuf *rt_buf)
{
	struct upd_region *fsp_upd = &config->fsp_upd;
	const void *blob = gd->fdt_blob;
	int node;

	/* Initialize runtime buffer for fsp_init() */
	rt_buf->common.stack_top = config->common.stack_top - 32;
	rt_buf->common.boot_mode = config->common.boot_mode;
	rt_buf->common.upd_data = &config->fsp_upd;

	node = fdtdec_next_compatible(blob, 0, COMPAT_INTEL_BROADWELL_DE_FSP);
	if (node < 0) {
		debug("%s: Cannot find FSP node\n", __func__);
		return;
	}

  debug("%s: FSP node found!\n", __func__);

	fsp_upd->memEccSupport = fdtdec_get_int(blob, node, 
                      "fsp,memEccSupport",
                       MEM_ECC_SUPPORT_AUTO);

	fsp_upd->memDdrMemoryType = fdtdec_get_int(blob, node, 
                      "fsp,memDdrMemoryType",
                      MEM_DDR_MEMORY_TYPE_UDIMM_AND_RDIMM);	
	
  fsp_upd->memRankMultiplication = fdtdec_get_int(blob, node, 
                      "fsp,memRankMultiplication", 
                      MEM_RANK_MULTIPLICATION_AUTO);
	
  fsp_upd->memRankMarginTool = fdtdec_get_int(blob, node, 
                      "fsp,memRankMarginTool", 
                      MEM_RANK_MARGIN_TOOL_AUTO);
	
  fsp_upd->memScrambling = fdtdec_get_int(blob, node, 
                      "fsp,memScrambling", 
                      MEM_SCRAMBLING_AUTO);
	
  fsp_upd->memRefreshMode = fdtdec_get_int(blob, node, 
                      "fsp,memRefreshMode", 
                      MEM_REFRESH_MODE_ACC_SELF_REFRESH);
	
  fsp_upd->memMcOdtOverride = fdtdec_get_int(blob, node, 
                      "fsp,memMcOdtOverride", 
                      MEM_MC0DT_OVERRIDE_AUTO);
	
  fsp_upd->memCAParity = fdtdec_get_int(blob, node, 
                      "fsp,memCAParity", 
                      MEM_CA_PARITY_AUTO);
	
  fsp_upd->memThermalThrottling = fdtdec_get_int(blob, node, 
                      "fsp,memThermalThrottling", 
                      MEM_THERMAL_THROTTLING_CLOSEDLOOP);
	
  fsp_upd->memPowerSavingsMode = fdtdec_get_int(blob, node, 
                      "fsp,memPowerSavingsMode", 
                      MEM_POWER_SAVINGS_MODE_AUTO);
	
  fsp_upd->memElectricalThrottling = fdtdec_get_int(blob, node, 
                      "fsp,memElectricalThrottling", 
                      MEM_ELECTRICAL_THROTTLING_DISABLED);
	
  fsp_upd->memPagePolicy = fdtdec_get_int(blob, node, 
                      "fsp,memPagePolicy", 
                      MEM_PAGE_POLICY_AUTO);
	
  fsp_upd->memSocketInterleaveBelow4G = fdtdec_get_int(blob, node, 
                      "fsp,memSocketInterleaveBelow4G", 
                      MEM_SOCKET_INTERLEAVE_BELOW_4G_DISABLED);
	
  fsp_upd->memChannelInterleave = fdtdec_get_int(blob, node, 
                      "fsp,memChannelInterleave", 
                      MEM_CHANNEL_INTERLEAVE_AUTO);
	
  fsp_upd->memRankInterleave = fdtdec_get_int(blob, node, 
                      "fsp,memRankInterleave", 
                      MEM_RANK_INTERLEAVE_AUTO);
	

	if(CONFIG_FSP_MEMORY_DOWN){

		fsp_upd->memDownEnable = fdtdec_get_bool(blob, node, "fsp,memDownEnable");

		fsp_upd->memDownCh0Dimm0SpdPtr = fdtdec_get_int(blob, node, 
                      "fsp,memDownCh0Dimm0SpdPtr", 
                      CONFIG_SPD_ADDR);
		
    fsp_upd->memDownCh0Dimm1SpdPtr = fdtdec_get_int(blob, node, 
                      "fsp,memDownCh0Dimm1SpdPtr", 
                      0x0);
		
    fsp_upd->memDownCh1Dimm0SpdPtr = fdtdec_get_int(blob, node, 
                      "fsp,memDownCh1Dimm0SpdPtr", 
                      0x0);
		
    fsp_upd->memDownCh1Dimm1SpdPtr = fdtdec_get_int(blob, node, 
                      "fsp,memDownCh1Dimm1SpdPtr", 
                      0x0);
	} 

	#ifdef CONFIG_ENABLE_MRC_CACHE
		fsp_upd->memFastBoot = fdtdec_get_bool(blob, node, "fsp,mem-fast-boot");
	#endif

	fsp_upd->pam0_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam0-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam1_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam1-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam1_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam1-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam2_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam2-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam2_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam2-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam3_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam3-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam3_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam3-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam4_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam4-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam4_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam4-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam5_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam5-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam5_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam5-hienable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam6_loenable = fdtdec_get_int(blob, node, 
                      "fsp,pam6-loenable", 
                      PAM_RW_DRAM_ONLY);

	fsp_upd->pam6_hienable = fdtdec_get_int(blob, node, 
                      "fsp,pam6-hienable", 
                      PAM_RW_DRAM_ONLY);             					
	
  fsp_upd->memAdr = fdtdec_get_int(blob, node, 
                      "fsp,memAdr", 
                      MEM_ADR_DISABLED);
	  
	fsp_upd->serialPortType = fdtdec_get_int(blob, node, 
                      "fsp,serial-port-type", 
                      SERIAL_PORT_TYPE_IO);

  fsp_upd->serialPortAddress = fdtdec_get_int(blob, node, 
                      "fsp,serial-port-address", 
                      0x3f8);
	
  fsp_upd->serialPortConfigure = fdtdec_get_bool(blob, node, "fsp,serial-port-configure");
	
  fsp_upd->serialPortBaudRate = fdtdec_get_int(blob, node, 
                      "fsp,serial-port-baudrate", 
                      SERIAL_PORT_BAUDRATE_115200);
	
  fsp_upd->serialPortControllerInit0 = fdtdec_get_bool(blob, node, "fsp,serial-port-controller-init0");
	
  fsp_upd->serialPortControllerInit1 = fdtdec_get_bool(blob, node, "fsp,serial-port-controller-init1");
	
  fsp_upd->configIOU1_PciPort3 = fdtdec_get_int(blob, node, 
                      "fsp,config-iou1-pci-port3", 
                      CONFIG_IOU1_PCI_PORT3_X4X4X4X4);
	  
  fsp_upd->configIOU2_PciPort1 = fdtdec_get_int(blob, node, 
                      "fsp,config-iou2-pci-port1", 
                      CONFIG_IOU2_PCI_PORT1_XXX8);
	
  fsp_upd->pchPciPort1 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port1");
	
  fsp_upd->pchPciPort2 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port2");
	
  fsp_upd->pchPciPort3 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port3");
	
  fsp_upd->pchPciPort4 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port4");
	
  fsp_upd->pchPciPort5 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port5");
	
  fsp_upd->pchPciPort6 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port6");
	
  fsp_upd->pchPciPort7 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port7");
	
  fsp_upd->pchPciPort8 = fdtdec_get_bool(blob, node, "fsp,pch-pci-port8");
	
	fsp_upd->ehci1Enable = fdtdec_get_bool(blob, node, "fsp,ehci1-enable");
	
  fsp_upd->hyperThreading = fdtdec_get_bool(blob, node, "fsp,hyper-threading");
	
  fsp_upd->debugOutputLevel = fdtdec_get_int(blob, node, 
                        "fsp,debug-output-level", 
                        DEBUG_OUTPUT_LEVEL_NORMAL);
	
  fsp_upd->tcoTimerHaltLock = fdtdec_get_bool(blob, node, "fsp,tco-timer-halt-lock");
	
  fsp_upd->turboMode = fdtdec_get_bool(blob, node, "fsp,turbo-mode");
	
  fsp_upd->bootPerfMode = fdtdec_get_bool(blob, node, "fsp,boot-perf-mode");
	
  fsp_upd->pciePort1aAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port1a-aspm", 
                          PCIE_ASPM_DISABLED);
	
  fsp_upd->pciePort1bAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port1b-aspm", 
                          PCIE_ASPM_DISABLED);
	
  fsp_upd->pciePort3aAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port3a-aspm", 
                          PCIE_ASPM_DISABLED);

	fsp_upd->pciePort3bAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port3b-aspm", 
                          PCIE_ASPM_DISABLED);

	fsp_upd->pciePort3cAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port3c-aspm", 
                          PCIE_ASPM_DISABLED);

	fsp_upd->pciePort3dAspm = fdtdec_get_int(blob, node, 
                          "fsp,pcie-port3d-aspm", 
                          PCIE_ASPM_DISABLED);
	
  fsp_upd->pchPciePort1Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port1-aspm", 
                          PCH_PCI_ASPM_DISABLED);
	
  fsp_upd->pchPciePort2Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port2-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort3Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port3-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort4Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port4-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort5Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port5-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort6Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port6-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort7Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port7-aspm", 
                          PCH_PCI_ASPM_DISABLED);

	fsp_upd->pchPciePort8Aspm = fdtdec_get_int(blob, node, 
                          "fsp,pch-pcie-port8-aspm", 
                          PCH_PCI_ASPM_DISABLED);
	
  fsp_upd->thermalDeviceEnable = fdtdec_get_bool(blob, node, "fsp,thermal-device-enable");
}
