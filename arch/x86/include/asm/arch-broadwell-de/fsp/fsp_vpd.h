/*
 * Copyright (C) 2017, Vincenzo Bove <vincenzo.bove@prodrive-technologies.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __FSP_VPD_H
#define __FSP_VPD_H

struct __packed upd_region {
	uint64_t signature;							/* Offset 0x0000 */
	uint8_t  reserved0[24];						/* Offset 0x0008 */
	uint8_t  serial_port_type;    				/* Offset 0x0020*/
	uint32_t serial_port_address; 				/* Offset 0x0021*/
	uint8_t  serial_port_configure; 			/* Offset 0x0025*/
	uint8_t  serial_port_baudrate;  			/* Offset 0x0026*/
	uint8_t  serial_port_controller_init0; 		/* Offset 0x0027*/
	uint8_t  serial_port_controller_init1; 		/* Offset 0x0028*/
	uint8_t  config_iou1_pci_port3;   			/* Offset 0x0029*/     
	uint8_t  config_iou2_pci_port1;   			/* Offset 0x002a*/
	uint8_t  power_state_after_g3;    			/* Offset 0x002b*/
	uint8_t  pch_pci_port1;           			/* Offset 0x002c*/
	uint8_t  pch_pci_port2;          			/* Offset 0x002d*/ 
	uint8_t  pch_pci_port3;          		 	/* Offset 0x002e*/
	uint8_t  pch_pci_port4;           			/* Offset 0x002f*/
	uint8_t  pch_pci_port5;           			/* Offset 0x0030*/
	uint8_t  pch_pci_port6;           			/* Offset 0x0031*/
	uint8_t  pch_pci_port7;           			/* Offset 0x0032*/
	uint8_t  pch_pci_port8;           			/* Offset 0x0033*/
	uint8_t  hot_plug_pch_pci_port1;  			/* Offset 0x0034*/
	uint8_t  hot_plug_pch_pci_port2; 			/* Offset 0x0035*/
	uint8_t  hot_plug_pch_pci_port3;  			/* Offset 0x0036*/
	uint8_t  hot_plug_pch_pci_port4;  			/* Offset 0x0037*/
	uint8_t  hot_plug_pch_pci_port5;  			/* Offset 0x0038*/
	uint8_t  hot_plug_pch_pci_port6;  			/* Offset 0x0039*/
	uint8_t  hot_plug_pch_pci_port7;  			/* Offset 0x003a*/
	uint8_t  hot_plug_pch_pci_port8;  			/* Offset 0x003b*/
    uint8_t  ehci1_enable;						/* Offset 0x003c*/
	uint8_t  ehci2_enable;						/* Offset 0x003d*/
	uint8_t  hyper_threading;         			/* Offset 0x003e*/
	uint8_t  debug_output_level;     			/* Offset 0x003f*/
	uint8_t  tco_timer_halt_lock;     			/* Offset 0x0040*/
	uint8_t  turbo_mode;              			/* Offset 0x0041*/
	uint8_t  boot_perf_mode;          			/* Offset 0x0042*/
	uint8_t  pcie_port1a_aspm;        			/* Offset 0x0043*/
	uint8_t  pcie_port1b_aspm;        			/* Offset 0x0044*/
	uint8_t  pcie_port3a_aspm;        			/* Offset 0x0045*/
	uint8_t  pcie_port3b_aspm;        			/* Offset 0x0046*/
	uint8_t  pcie_port3c_aspm;        			/* Offset 0x0047*/
	uint8_t  pcie_port3d_aspm;        			/* Offset 0x0048*/
	uint8_t  pch_pcie_port1_aspm;        		/* Offset 0x0049*/
	uint8_t  pch_pcie_port2_aspm;        		/* Offset 0x004a*/
	uint8_t  pch_pcie_port3_aspm;        		/* Offset 0x004b*/
	uint8_t  pch_pcie_port4_aspm;        		/* Offset 0x004c*/
	uint8_t  pch_pcie_port5_aspm;        		/* Offset 0x004d*/
	uint8_t  pch_pcie_port6_aspm;        		/* Offset 0x004e*/
	uint8_t  pch_pcie_port7_aspm;        		/* Offset 0x004f*/
	uint8_t  pch_pcie_port8_aspm;        		/* Offset 0x0050*/
	uint8_t  dfx_enable;                 		/* Offset 0x0051*/
	uint8_t  thermal_device_enable;      		/* Offset 0x0052*/
	uint8_t  unused_upd_space[88];				/* Offset 0x0053 */
	uint8_t  mem_ecc_support;            		/* Offset 0x00AB */
	uint8_t  mem_ddr_memory_type;        		/* Offset 0x00AC */
	uint8_t  mem_rank_multiplication;    		/* Offset 0x00AD */
	uint8_t  mem_rank_margin_tool;       		/* Offset 0x00AE */
	uint8_t  mem_scrambling;             		/* Offset 0x00AF */
	uint8_t  mem_refresh_mode;           		/* Offset 0x00B0 */
	uint8_t  mem_mc0dt_override;         		/* Offset 0x00B1 */
	uint8_t  mem_ca_parity;              		/* Offset 0x00B2 */
	uint8_t  mem_thermal_throttling;     		/* Offset 0x00B3 */
	uint8_t  mem_power_savings_mode;     		/* Offset 0x00B4 */
	uint8_t  mem_electrical_throttling;  		/* Offset 0x00B5 */
	uint8_t  mem_page_policy;            		/* Offset 0x00B6 */
	uint8_t  mem_socket_interleave_below_4g; 	/* Offset 0x00B7 */
	uint8_t  mem_channel_interleave;     		/* Offset 0x00B8 */
	uint8_t  mem_rank_interleave;        		/* Offset 0x00B9 */
	uint8_t  mem_down_enable;            		/* Offset 0x00BA */
    uint32_t mem_down_ch0_dimm0_spd_ptr; 		/* Offset 0x00BB */
    uint32_t mem_down_ch0_dimm1_spd_ptr;  		/* Offset 0x00BF */       
    uint32_t mem_down_ch1_dimm0_spd_ptr;  		/* Offset 0x00C3 */       
    uint32_t mem_down_ch1_dimm1_spd_ptr;  		/* Offset 0x00C7 */       
    uint8_t  mem_fast_boot; 					/* Offset 0x00CB */                  
    uint8_t  pam0_hienable; 					/* Offset 0x00CC */                
    uint8_t  pam1_loenable; 					/* Offset 0x00CD */                
  	uint8_t  pam1_hienable; 					/* Offset 0x00CE */                
    uint8_t  pam2_loenable; 					/*Offset 0x00CF */                
    uint8_t  pam2_hienable; 					/* Offset 0x00D0 */                
    uint8_t  pam3_loenable; 					/* Offset 0x00D1 */                
  	uint8_t  pam3_hienable; 					/* Offset 0x00D2 */                
  	uint8_t  pam4_loenable;					  	/* Offset 0x00D3 */                
  	uint8_t  pam4_hienable; 					/* Offset 0x00D4 */                
  	uint8_t  pam5_loenable; 					/* Offset 0x00D5 */                
  	uint8_t  pam5_hienable; 					/* Offset 0x00D6 */                
  	uint8_t  pam6_loenable; 					/* Offset 0x00D7 */                
  	uint8_t  pam6_hienable; 					/* Offset 0x00D8 */                
  	uint8_t  mem_adr; 							/* Offset 0x00D9 */                       
  	uint8_t  mem_adr_resume_path; 				/* Offset 0x00DA */           
  	uint8_t  mem_block_sc_traffic_on_adr; 		/* Offset 0x00DB */   
  	uint16_t mem_platform_release_adr_clamps_port; /* Offset 0x00DC */
  	uint32_t mem_platform_release_adr_clamps_and; /* Offset 0x00DE */
  	uint32_t mem_platform_release_adr_clamps_or; /* Offset 0x00E2 */
  	uint8_t  unused_upd_space2[24]; 			/* Offset 0x00E6 */          
  	uint16_t terminator; 						/* Offset 0x00FE */          
};

#define VPD_IMAGE_ID		0x5F45442D5844425F	/* '_BDX-DE_' */

struct __packed vpd_region {
	uint64_t sign;				/* Offset 0x0000 */
	uint32_t img_rev;			/* Offset 0x0008 */
	uint32_t upd_offset;		/* Offset 0x000c */
	uint8_t unused[16];			/* Offset 0x0010 */
	uint32_t fsp_res_memlen;	/* Offset 0x0020 */
};
#endif
