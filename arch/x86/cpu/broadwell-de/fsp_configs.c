/*
 * Copyright (C) 2017, Vincenzo Bove <vincenzo.bove@prodrive-technologies.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <fdtdec.h>
#include <asm/fsp/fsp_support.h>

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

	fsp_upd->mem_ecc_support = fdtdec_get_int(blob, node, "fsp,mem-ecc-support", MEM_ECC_SUPPORT_AUTO);
	fsp_upd->mem_ddr_memory_type = fdtdec_get_int(blob, node, "fsp,mem-ddr-memory-type", MEM_DDR_MEMORY_TYPE_UDIMM_AND_RDIMM);	
	fsp_upd->mem_rank_multiplication = fdtdec_get_int(blob, node, "fsp,mem-rank-multiplication", MEM_RANK_MULTIPLICATION_AUTO);
	fsp_upd->mem_rank_margin_tool = fdtdec_get_int(blob, node, "fsp,mem-rank-margin-tool", MEM_RANK_MARGIN_TOOL_AUTO);
	fsp_upd->mem_scrambling = fdtdec_get_int(blob, node, "fsp,mem-scrambling", MEM_SCRAMBLING_AUTO);
	fsp_upd->mem_refresh_mode = fdtdec_get_int(blob, node, "fsp,mem-refresh-mode", MEM_REFRESH_MODE_ACC_SELF_REFRESH);
	fsp_upd->mem_mc0dt_override = fdtdec_get_int(blob, node, "fsp,mem-mc0dt-override", MEM_MC0DT_OVERRIDE_AUTO);
	fsp_upd->mem_ca_parity = fdtdec_get_int(blob, node, "fsp,mem-ca-parity", MEM_CA_PARITY_AUTO);
	fsp_upd->mem_thermal_throttling = fdtdec_get_int(blob, node, "fsp,mem-thermal-throttling", MEM_THERMAL_THROTTLING_CLOSEDLOOP);
	fsp_upd->mem_power_savings_mode = fdtdec_get_int(blob, node, "fsp,mem-power-savings-mode", MEM_POWER_SAVINGS_MODE_AUTO);
	fsp_upd->mem_electrical_throttling = fdtdec_get_int(blob, node, "fsp,mem-electrical-throttling", MEM_ELECTRICAL_THROTTLING_DISABLED);
	fsp_upd->mem_page_policy = fdtdec_get_int(blob, node, "fsp,mem-page-policy", MEM_PAGE_POLICY_AUTO);
	fsp_upd->mem_socket_interleave_below_4g = fdtdec_get_int(blob, node, "fsp,mem-socket-interleave-below-4g", MEM_SOCKET_INTERLEAVE_BELOW_4G_DISABLED);
	fsp_upd->mem_channel_interleave = fdtdec_get_int(blob, node, "fsp,mem-channel-interleave", MEM_CHANNEL_INTERLEAVE_AUTO);
	fsp_upd->mem_rank_interleave = fdtdec_get_int(blob, node, "fsp,mem-rank-interleave", MEM_RANK_INTERLEAVE_AUTO);
	fsp_upd->mem_down_enable = fdtdec_get_int(blob, node, "fsp,mem-down-enable", MEM_DOWN_ENABLE_NO);
	fsp_upd->mem_down_ch0_dimm0_spd_ptr = fdtdec_get_int(blob, node, "fsp,mem-down-ch0-dimm0-spd-ptr", 0x0);
	fsp_upd->mem_down_ch0_dimm1_spd_ptr = fdtdec_get_int(blob, node, "fsp,mem-down-ch0-dimm1-spd-ptr", 0x0);
	fsp_upd->mem_down_ch1_dimm0_spd_ptr = fdtdec_get_int(blob, node, "fsp,mem-down-ch1-dimm0-spd-ptr", 0x0);
	fsp_upd->mem_down_ch1_dimm1_spd_ptr = fdtdec_get_int(blob, node, "fsp,mem-down-ch1-dimm1-spd-ptr", 0x0);
	fsp_upd->mem_fast_boot = fdtdec_get_int(blob, node, "fsp,mem-fast-boot", MEM_FAST_BOOT_YES);
	fsp_upd->pam0_hienable = fdtdec_get_int(blob, node, "fsp,pam0-hienable", PAM0_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam1_loenable = fdtdec_get_int(blob, node, "fsp,pam1-loenable", PAM1_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam1_hienable = fdtdec_get_int(blob, node, "fsp,pam1-hienable", PAM1_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam2_loenable = fdtdec_get_int(blob, node, "fsp,pam2-loenable", PAM2_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam2_hienable = fdtdec_get_int(blob, node, "fsp,pam2-hienable", PAM2_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam3_loenable = fdtdec_get_int(blob, node, "fsp,pam3-loenable", PAM3_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam3_hienable = fdtdec_get_int(blob, node, "fsp,pam3-hienable", PAM3_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam4_loenable = fdtdec_get_int(blob, node, "fsp,pam4-loenable", PAM4_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam4_hienable = fdtdec_get_int(blob, node, "fsp,pam4-hienable", PAM4_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam5_loenable = fdtdec_get_int(blob, node, "fsp,pam5-loenable", PAM5_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam5_hienable = fdtdec_get_int(blob, node, "fsp,pam5-hienable", PAM5_HIENABLE_RW_DRAM_ONLY);
	fsp_upd->pam6_loenable = fdtdec_get_int(blob, node, "fsp,pam6-loenable", PAM6_LOENABLE_RW_DRAM_ONLY);
	fsp_upd->pam6_hienable = fdtdec_get_int(blob, node, "fsp,pam6-hienable", PAM6_HIENABLE_RW_DRAM_ONLY);             					
	fsp_upd->mem_adr = fdtdec_get_int(blob, node, "fsp,mem-adr", MEM_ADR_DISABLED);
	fsp_upd->mem_block_sc_traffic_on_adr = fdtdec_get_int(blob, node, "fsp,mem-block-sc-traffic-on-adr", MEM_BLOCKS_TRAFFIC_ON_ADR_DISABLED);
	fsp_upd->mem_platform_release_adr_clamps_port = fdtdec_get_int(blob, node, "fsp,mem-platform-release-adr-clamps-port", 0x0);
	fsp_upd->mem_platform_release_adr_clamps_and = fdtdec_get_int(blob, node, "fsp,mem-platform-release-adr-clamps-and", 0xffffffff);
	fsp_upd->mem_platform_release_adr_clamps_or = fdtdec_get_int(blob, node, "fsp,mem-platform-release-adr-clamps-or", 0x0);
	fsp_upd->serial_port_type = fdtdec_get_int(blob, node, "fsp,serial-port-type", SERIAL_PORT_TYPE_IO);
	fsp_upd->serial_port_address = fdtdec_get_int(blob, node, "fsp,serial-port-address", 0x3f8);
	fsp_upd->serial_port_configure = fdtdec_get_int(blob, node, "fsp,serial-port-configure", SERIAL_PORT_CONFIGURE_YES);
	fsp_upd->serial_port_baudrate = fdtdec_get_int(blob, node, "fsp,serial-port-baudrate", SERIAL_PORT_BAUDRATE_115200);
	fsp_upd->serial_port_controller_init0 = fdtdec_get_int(blob, node, "fsp,serial-port-controller-init0", SERIAL_PORT_CONTROLLER_INIT0_YES);
	fsp_upd->serial_port_controller_init1 = fdtdec_get_int(blob, node, "fsp,serial-port-controller-init1", SERIAL_PORT_CONTROLLER_INIT1_YES);
	fsp_upd->config_iou1_pci_port3 = fdtdec_get_int(blob, node, "fsp,config-iou1-pci-port3", CONFIG_IOU1_PCI_PORT3_X4X4X4X4);
	fsp_upd->config_iou2_pci_port1 = fdtdec_get_int(blob, node, "fsp,config-iou2-pci-port1", CONFIG_IOU2_PCI_PORT1_XXX8);
	fsp_upd->power_state_after_g3 = fdtdec_get_int(blob, node, "fsp,power-state-after-g3", POWER_STATE_AFTER_G3_S0);
	fsp_upd->pch_pci_port1 = fdtdec_get_int(blob, node, "fsp,pch-pci-port1", PCH_PCI_PORT1_ENABLE);
	fsp_upd->pch_pci_port2 = fdtdec_get_int(blob, node, "fsp,pch-pci-port2", PCH_PCI_PORT2_ENABLE);
	fsp_upd->pch_pci_port3 = fdtdec_get_int(blob, node, "fsp,pch-pci-port3", PCH_PCI_PORT3_ENABLE);
	fsp_upd->pch_pci_port4 = fdtdec_get_int(blob, node, "fsp,pch-pci-port4", PCH_PCI_PORT4_ENABLE);
	fsp_upd->pch_pci_port5 = fdtdec_get_int(blob, node, "fsp,pch-pci-port5", PCH_PCI_PORT5_ENABLE);
	fsp_upd->pch_pci_port6 = fdtdec_get_int(blob, node, "fsp,pch-pci-port6", PCH_PCI_PORT6_ENABLE);
	fsp_upd->pch_pci_port7 = fdtdec_get_int(blob, node, "fsp,pch-pci-port7", PCH_PCI_PORT7_ENABLE);
	fsp_upd->pch_pci_port8 = fdtdec_get_int(blob, node, "fsp,pch-pci-port8", PCH_PCI_PORT8_ENABLE);
	fsp_upd->hot_plug_pch_pci_port1 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port1", HOTPLUG_PCH_PCI_PORT1_DISABLE);
	fsp_upd->hot_plug_pch_pci_port2 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port2", HOTPLUG_PCH_PCI_PORT2_DISABLE);
	fsp_upd->hot_plug_pch_pci_port3 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port3", HOTPLUG_PCH_PCI_PORT3_DISABLE);
	fsp_upd->hot_plug_pch_pci_port4 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port4", HOTPLUG_PCH_PCI_PORT4_DISABLE);
	fsp_upd->hot_plug_pch_pci_port5 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port5", HOTPLUG_PCH_PCI_PORT5_DISABLE);
	fsp_upd->hot_plug_pch_pci_port6 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port6", HOTPLUG_PCH_PCI_PORT6_DISABLE);
	fsp_upd->hot_plug_pch_pci_port7 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port7", HOTPLUG_PCH_PCI_PORT7_DISABLE);
	fsp_upd->hot_plug_pch_pci_port8 = fdtdec_get_int(blob, node, "fsp,hot-plug-pch-pci-port8", HOTPLUG_PCH_PCI_PORT8_DISABLE);
	fsp_upd->ehci1_enable = fdtdec_get_int(blob, node, "fsp,ehci1-enable", EHCI_1ENABLE_ENABLE);
	fsp_upd->ehci2_enable = fdtdec_get_int(blob, node, "fsp,ehci2-enable", EHCI_2ENABLE_DISABLE);
	fsp_upd->hyper_threading = fdtdec_get_int(blob, node, "fsp,hyper-threading", HYPER_THREADING_ENABLE);
	fsp_upd->debug_output_level = fdtdec_get_int(blob, node, "fsp,debug-output-level", DEBUG_OUTPUT_LEVEL_NORMAL);
	fsp_upd->tco_timer_halt_lock = fdtdec_get_int(blob, node, "fsp,tco-timer-halt-lock", TCO_TIMER_HALT_LOCK_YES);
	fsp_upd->turbo_mode = fdtdec_get_int(blob, node, "fsp,turbo-mode", TURBO_MODE_ENABLE);
	fsp_upd->boot_perf_mode = fdtdec_get_int(blob, node, "fsp,boot-perf-mode", BOOT_PERF_MODE_MAX_PERFORMANCE);
	fsp_upd->pcie_port1a_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port1a-aspm", PCIE_PORT1A_ASPM_DISABLED);
	fsp_upd->pcie_port1b_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port1b-aspm", PCIE_PORT1B_ASPM_DISABLED);
	fsp_upd->pcie_port3a_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port3a-aspm", PCIE_PORT3A_ASPM_DISABLED);
	fsp_upd->pcie_port3b_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port3b-aspm", PCIE_PORT3B_ASPM_DISABLED);
	fsp_upd->pcie_port3c_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port3c-aspm", PCIE_PORT3C_ASPM_DISABLED);
	fsp_upd->pcie_port3d_aspm = fdtdec_get_int(blob, node, "fsp,pcie-port3d-aspm", PCIE_PORT3D_ASPM_DISABLED);
	fsp_upd->pch_pcie_port1_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port1-aspm", PCH_PCI_PORT1_ASPM_DISABLED);
	fsp_upd->pch_pcie_port2_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port2-aspm", PCH_PCI_PORT2_ASPM_DISABLED);
	fsp_upd->pch_pcie_port3_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port3-aspm", PCH_PCI_PORT3_ASPM_DISABLED);
	fsp_upd->pch_pcie_port4_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port4-aspm", PCH_PCI_PORT4_ASPM_DISABLED);
	fsp_upd->pch_pcie_port5_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port5-aspm", PCH_PCI_PORT5_ASPM_DISABLED);
	fsp_upd->pch_pcie_port6_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port6-aspm", PCH_PCI_PORT6_ASPM_DISABLED);
	fsp_upd->pch_pcie_port7_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port7-aspm", PCH_PCI_PORT7_ASPM_DISABLED);
	fsp_upd->pch_pcie_port8_aspm = fdtdec_get_int(blob, node, "fsp,pch-pcie-port8-aspm", PCH_PCI_PORT8_ASPM_DISABLED);
	fsp_upd->dfx_enable = fdtdec_get_int(blob, node, "fsp,dfx-enable", DFX_ENABLE_DISABLED);
	fsp_upd->thermal_device_enable = fdtdec_get_int(blob, node, "fsp,thermal-device-enable", THERMAL_DEVICE_ENABLE_ENABLED);
}
