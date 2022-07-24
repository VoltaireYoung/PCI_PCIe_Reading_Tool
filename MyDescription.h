/*
typedef struct{
	UINTN* Base_Class = {
		20,
		0x00,0x01,0x02,0x03,0x04,
		0x05,0x06,0x07,0x08,0x09,
		0x0A,0x0B,0x0C,0x0D,0x0E,
		0x0F,0x10,0x11,0x12,0x13
	};

	UINT** Sub_Class = {
		// BC:0x00
		{
			2,
			0x00,0x01
		},
		// BC:0x01
		{
			11,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x80
		},
		// BC:0x02
		{
			10,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x80
		},
		// BC:0x03
		{
			4,
			0x00,0x01,0x02,0x80
		},
		// BC:0x04
		{
			5,
			0x00,0x01,0x02,0x03,0x80
		},
		// BC:0x05
		{
			3,
			0x00,0x01,0x80
		},
		// BC:0x06
		{
			13,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x0A,0x0B,0x80
		},
		// BC:0x07
		{
			7,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x80
		},
		// BC:0x08
		{
			9,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x80
		},
		// BC:0x09
		{
			6,
			0x00,0x01,0x02,0x03,0x04,
			0x80
		},
		// BC:0x0A
		{
			2,
			0x00,0x80
		},
		// BC:0x0B
		{
			8,
			0x00,0x01,0x02,
			0x10,0x20,0x30,0x40,0x80
		},
		// BC:0x0C
		{
			12,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x0A,0x80
		},
		// BC:0x0D
		{
			10,
			0x00,0x01,
			0x10,0x11,0x12,
			0x20,0x21,
			0x40,0x41,
			0x80
		},
		// BC:0x0E
		{
			1,
			0x00
		},
		// BC:0x0F
		{
			5,
			0x01,0x02,0x03,0x04,0x80
		},
		// BC:0x10
		{
			3,
			0x00,0x01,0x80
		},
		// BC:0x11
		{
			5,
			0x00,0x01,
			0x10,0x20,0x80
		},
		// BC:0x12
		{
			1,
			0x00
		},
		// BC:0x13
		{
			1,
			0x00
		}
	};

	UINTN*** Programming_Interface = {
		// BC:0x00
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			}
		},
		// BC:0x01
		{
			// SC:0x00
			{
				5,
				0x00,0x11,0x12,0x13,0x21
			},
			// SC:0x01
			{
				1,
				0xFF
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				2,
				0x20,0x30
			},
			// SC:0x06
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x07
			{
				2,
				0x00,0x01
			},
			// SC:0x08
			{
				4,
				0x00,0x01,0x02,0x03
			},
			// SC:0x09
			{
				2,
				0x00,0x01
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x02
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0xFF
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x08
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x03
		{
			// SC:0x00
			{
				2,
				0x00,0x01
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x04
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				2,
				0x00,0x80
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x05
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x06
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				2,
				0x00,0x01
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x08
			{
				1,
				0xFF
			},
			// SC:0x09
			{
				2,
				0x40,0x80
			},
			// SC:0x0A
			{
				1,
				0x00
			},
			// SC:0x0B
			{
				2,
				0x00,0x01
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x07
		{
			// SC:0x00
			{
				7,
				0x00,0x01,0x02,0x03,0x04,
				0x05,0x06
			},
			// SC:0x01
			{
				5,
				0x00,0x01,0x02,0x03,0xFE
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				5,
				0x00,0x01,0x02,0x03,0x04
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x08
		{
			// SC:0x00
			{
				5,
				0x00,0x01,0x02,0x10,0x20
			},
			// SC:0x01
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x02
			{
				4,
				0x00,0x01,0x02,0x03
			},
			// SC:0x03
			{
				2,
				0x00,0x01
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x09
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				2,
				0x00,0x10
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0A
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0B
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x30
			{
				1,
				0x00
			},
			// SC:0x40
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0C
		{
			// SC:0x00
			{
				2,
				0x00,0x10
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				6,
				0x00,
				0x10,0x20,0x30,0x80,0xFE
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x08
			{
				1,
				0x00
			},
			// SC:0x09
			{
				1,
				0x00
			},
			// SC:0x0A
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0D
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				2,
				0x00,0x10
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x11
			{
				1,
				0x00
			},
			// SC:0x12
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x21
			{
				1,
				0x00
			},
			// SC:0x40
			{
				1,
				0x00
			},
			// SC:0x41
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0E
		{
			// SC:0x00
			{
				2,
				0x00,0xFF
			}
		},
		// BC:0x0F
		{
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x10
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x11
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x12
		{
			// SC:0x00
			{
				1,
				0x00
			}
		},
		// BC:0x13
		{
			// SC:0x00
			{
				1,
				0x00
			}
		}
	};

	CHAR8*** Description = {
		// BC:0x00
		{
			// SC:0x00
			{
				// PI:0x00
				{
					"All devices except VGA-compatible devices"
				}
			},
			// SC:0x01
			{
				// PI:0x00
				{
					"VGA-compatible device"
				}
			}
		},
		// BC:0x01
		{
			// SC:0x00
			{
				"SCSI controller - vendor-specific interface",
				"SCSI storage device",
				"SCSI controller - SOP target port using PQI",
				"SCSI storage device and SCSI controller - SOP target port using PQI",
				"SCSI storage device - SOP target port using NVM Express interface"
			},
			// SC:0x01
			{
				"IDE Controller"
			},
			// SC:0x02
			{
				"Floppy disk controller"
			},
			// SC:0x03
			{
				"IPI bus controller"
			},
			// SC:0x04
			{
				"RAID controller - vendor-specific interface"
			},
			// SC:0x05
			{
				"ATA controller with ADMA interface - single stepping",
				"ATA controller with ADMa interface - continuous operatrion"
			},
			// SC:0x06
			{
				"Serial ATA controller - vendor-specific interface",
				"Serial ATA controller - AHCI interaface",
				"Serial Storage Bus Interface"
			},
			// SC:0x07
			{
				"Serail Attached SCSI (SAS) controller - vendor-specific interface",
				"Obsolete"
			},
			// SC:0x08
			{
				"Non-volatile memory subsystem - vendor-specific interface",
				"Non-volatile memory subsystem - NVMHCI interface",
				"NVM Express (NVMe) I/O controller",
				"NVM Express (NVMe) administrative controller"
			},
			// SC:0x09
			{
				"Universal Flash Storage (UFS) controller - vendor-specific interface",
				"Universal Flash Storage (UFS) controller - Universal Flash Storage Host Controller Interface (UFSHCI)"
			},
			// SC:0x80
			{
				"Other mass storage controller - vendor-specific interface"
			}
		},
		// BC:0x02
		{
			//SC:0x00
			{
				"Ethernet controller"
			},
			// SC:0x01
			{
				"Token Ring controller"
			},
			// SC:0x02
			{
				"FDDI controller"
			},
			// SC:0x03
			{
				"ATM controller"
			},
			// SC:0x04
			{
				"ISDN controller"
			},
			// SC:0x05
			{
				"WorldFip controller"
			},
			// SC:0x06
			{
				"PICMG 2.14 Multi Computing"
			},
			// SC:0x07
			{
				"InfiniBand* Controller"
			},
			// SC:0x08
			{
				"Host fabric controller - vendor-specific"
			},
			// SC:0x80
			{
				"Other network controller"
			}
		},
		// BC:0x03
		{
			// SC:0x00
			{
				"VGA-compatible controller",
				"8514-compatible controller"
			},
			// SC:0x01
			{
				"XGA controller"
			},
			// SC:0x02
			{
				"3D controller"
			},
			// SC:0x80
			{
				"Other display controller"
			}
		},
		// BC:0x04
		{
			//SC:0x00
			{
				"Video device - vendor-specific interface"
			},
			// SC:0x01
			{
				"Audio device - vendor-specific interface"
			},
			// SC:0x02
			{
				"Computer telephony device - vendor-specific interface"
			},
			// SC:0x03
			{
				"High Definition Audio (HD-A) 1.0 compatible",
				"High Definition Audio (HD-A) 1.0 compatible with additional vendor specific extensions"
			},
			// SC:0x80
			{
				"Other multimedia device - vendor-specific interface"
			}
		},
		// BC:0x05
		{
			// SC:0x00
			{
				"RAM"
			},
			// SC:0x01
			{
				"Flash"
			},
			// SC:0x80
			{
				"Other memory controller"
			}
		},
		// BC:0x06
		{
			// SC:0x00
			{
				"Host bridge"
			},
			// SC:0x01
			{
				"ISA bridge"
			},
			// SC:0x02
			{
				"EISA bridge"
			},
			// SC:0x03
			{
				"MCA bridge"
			},
			// SC:0x04
			{
				"PCI-to-PCI brdge",
				"Subtractive Decode PCI-to-PCI bridge"
			},
			// SC:0x05
			{
				"PCMCIA bridge"
			},
			// SC:0x06
			{
				"NuBus bridge"
			},
			// SC:0x07
			{
				"CardBus bridge"
			},
			// SC:0x08
			{
				"RACEway bridge"
			},
			// SC:0x09
			{
				"Semi-transparent PCI-to-PCI bridge with the primary PCI bus side",
				"Semi-transparent PCI-to-PCI bridge with the secondary PCI bus side"
			},
			// SC:0x0A
			{
				"InfiniBand-to-PCI host bridge"
			},
			// SC:0x0B
			{
				"Advanced Switching to PCI host bridge - Custiom Interface",
				"Advanced Switching to PCI host bridge - ASI-SIG Defined Portal Interface"
			},
			// SC:0x80
			{
				"Other bridge device"
			}
		},
		// BC:0x07
		{
			// SC:0x00
			{
				"Generic XT-compatible serial controller",
				"16450-compatible serial controller",
				"16550-compatible serial controller",
				"16650-compatible serial controller",
				"16750-compatible serial controller",
				"16850-compatible serial controller",
				"16950-compatible serial controller"
			},
			// SC:0x01
			{
				"Parallel port",
				"Bi-directional parallel port",
				"ECP 1.X compliant parallel port",
				"IEEE 1284 controller",
				"IEEE 1284 target device"
			},
			// SC:0x02
			{
				"Multiport serial controller"
			},
			// SC:0x03
			{
				"Generic modern",
				"Hayes compatible modern, 16450-compatible interface",
				"Hayes compatible modern, 16550-compatible interface",
				"Hayes compatible modern, 16650-compatible interface",
				"Hayes compatible modern, 16750-compatible interface"
			},
			// SC:0x04
			{
				"GPIB (IEEE 488.1/2) controller"
			},
			// SC:0x05
			{
				"Smart Card"
			},
			// SC:0x80
			{
				"Other communications device"
			}
		},
		// BC:0x08
		{
			// SC:0x00
			{
				"Generic 8259 PIC",
				"ISA PIC",
				"EISA PIC",
				"I/O APIC interrput controller",
				"I/O APIC interrupt controller"
			},
			// SC:0x01
			{
				"Generic 8237 DMA controller",
				"ISA DMA controller",
				"EISA DMA controller"
			},
			// SC:0x02
			{
				"Generic 8254 system timer",
				"ISA system timer",
				"EISA system timers",
				"High Performance Event Timer"
			},
			// SC:0x03
			{
				"Generic RTC controller",
				"ISA RTC controller"
			},
			// SC:0x04
			{
				"Generic PCI Hot-Plug controller"
			},
			// SC:0x05
			{
				"SD Host controller"
			},
			// SC:0x06
			{
				"IOMMU"
			},
			// SC:0x07
			{
				"Root Complex Event Collector"
			},
			// SC:0x80
			{
				"Other system peripheral"
			}
		},
		// BC:0x09
		{
			// SC:0x00
			{
				"Keyboard controller"
			},
			// SC:0x01
			{
				"Digitizer (pen)"
			},
			// SC:0x02
			{
				"Mouse controller"
			},
			// SC:0x03
			{
				"Scanner controller"
			},
			// SC:0x04
			{
				"Gameport controller",
				"Gameprot controller"
			},
			// SC:0x80
			{
				"Other input controller"
			}
		},
		// BC:0x0A
		{
			// SC:0x00
			{
				"Generic docking station"
			},
			// SC:0x80
			{
				"Other type of docking station"
			}
		},
		// BC:0x0B
		{
			// SC:0x00
			{
				"386"
			},
			// SC:0x01
			{
				"486"
			},
			// SC:0x02
			{
				"Pentium"
			},
			// SC:0x10
			{
				"Alpha"
			},
			// SC:0x20
			{
				"PowerPC"
			},
			// SC:0x30
			{
				"MIPS"
			},
			// SC:0x40
			{
				"Co-processor"
			},
			// SC:0x80
			{
				"Other processors"
			}
		},
		// BC:0x0C
		{
			// SC:0x00
			{
				"IEEE 1394",
				"IEEE 1394 following the 1394 OpenHCI specification"
			},
			// SC:0x01
			{
				"ACCESS.bus"
			},
			// SC:0x02
			{
				"SSA"
			},
			// SC:0x03
			{
				"Universal Serial Bus (USB) following the Universial Host Controller Specification",
				"Universal Serial Bus (USB) following the Open Host Controller Specification",
				"USB 2 host controller following the Intel Enhanced Host Controller Interface Specification",
				"Universal Serial Bus (USB) Host Controller following the Intel xHCI Specification",
				"Universal Serial Bus with no specific Programming Interface",
				"USB device"
			},
			// SC:0x04
			{
				"Fibre Channel"
			},
			// SC:0x05
			{
				"System Management Bus (SMBus)"
			},
			// SC:0x06
			{
				"InfiniBand"
			},
			// SC:0x07
			{
				"IPMI SMIC Interface",
				"IPMI Keyboard Controller Style Interface",
				"IPMI Block Transfer Interface"
			},
			// SC:0x08
			{
				"SERCOS Interface Standard (IEC 61491)"
			},
			// SC:0x09
			{
				"CANbus"
			},
			// SC:0x0A
			{
				"MIPI I3C Host Controller Interface"
			},
			// SC:0x80
			{
				"Other Serial Bus Controllers"
			}
		},
		// BC:0x0D
		{
			// SC:0x00
			{
				"iRDA compatible controller"
			},
			// SC:0x01
			{
				"Consumer IR controller",
				"UWB Radio controller"
			},
			// SC:0x10
			{
				"RF controller"
			},
			// SC:0x11
			{
				"Bluetooth"
			},
			// SC:0x12
			{
				"Broadband"
			},
			// SC:0x20
			{
				"Ethernet (802.11a - 5 GHz)"
			},
			// SC:0x21
			{
				"Ethernet (802.11b - 2.4 GHz)"
			},
			// SC:0x40
			{
				"Cellular controller/modern"
			},
			// SC:0x41
			{
				"Cellular controller/modern plus Ethernet (802.11)"
			},
			// SC:0x80
			{
				"Other type of wireless controller"
			}
		},
		// BC:0x0E
		{
			// SC:0x00
			{
				"Message FIFO at offset 040h",
				"Intelligent I/O (I20) Architecture Specification 1.0"
			}
		},
		// BC:0x0F
		{
			// SC:0x01
			{
				"TV"
			},
			// SC:0x02
			{
				"Audio"
			},
			// SC:0x03
			{
				"Voice"
			},
			// SC:0x04
			{
				"Data"
			},
			// SC:0x80
			{
				"Other satellite communication controller"
			}
		},
		// BC:0x10
		{
			// SC:0x00
			{
				"Network and computing encryption and decryption controller"
			},
			// SC:0x01
			{
				"Entertainment encryption and decryption controller"
			},
			// SC: 0x80
			{
				"Other encryption and decryption controller"
			}
		},
		// BC:0x11
		{
			// SC:0x00
			{
				"DPIO modules"
			},
			// SC:0x01
			{
				"Performance counters"
			},
			// SC:0x10
			{
				"Communications synchronization plus time and frequency test/measurement"
			},
			// SC:0x20
			{
				"Management card"
			},
			// SC:0x80
			{
				"Other data acquisition/signal processing controllers"
			}
		},
		// BC:0x12
		{
			// SC:0x00
			{
				"Processing Accelerator - vendor-specific interface"
			}
		},
		// BC:0x13
		{
			// SC:0x00
			{
				"Non-Essential Instrumentation Function - vendor-specific interface"
			}
		}
	};

} PCI_Device_Description;
*/

#ifndef _CLASS_CODE_TABLE_
#define _CLASS_CODE_TABLE_

UINTN Base_Class[21] = {
		20,
		0x00,0x01,0x02,0x03,0x04,
		0x05,0x06,0x07,0x08,0x09,
		0x0A,0x0B,0x0C,0x0D,0x0E,
		0x0F,0x10,0x11,0x12,0x13
};

UINTN Sub_Class[21][14] = {
		// BC:0x00
		{
			2,
			0x00,0x01
		},
		// BC:0x01
		{
			11,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x80
		},
		// BC:0x02
		{
			10,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x80
		},
		// BC:0x03
		{
			4,
			0x00,0x01,0x02,0x80
		},
		// BC:0x04
		{
			5,
			0x00,0x01,0x02,0x03,0x80
		},
		// BC:0x05
		{
			3,
			0x00,0x01,0x80
		},
		// BC:0x06
		{
			13,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x0A,0x0B,0x80
		},
		// BC:0x07
		{
			7,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x80
		},
		// BC:0x08
		{
			9,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x80
		},
		// BC:0x09
		{
			6,
			0x00,0x01,0x02,0x03,0x04,
			0x80
		},
		// BC:0x0A
		{
			2,
			0x00,0x80
		},
		// BC:0x0B
		{
			8,
			0x00,0x01,0x02,
			0x10,0x20,0x30,0x40,0x80
		},
		// BC:0x0C
		{
			12,
			0x00,0x01,0x02,0x03,0x04,
			0x05,0x06,0x07,0x08,0x09,
			0x0A,0x80
		},
		// BC:0x0D
		{
			10,
			0x00,0x01,
			0x10,0x11,0x12,
			0x20,0x21,
			0x40,0x41,
			0x80
		},
		// BC:0x0E
		{
			1,
			0x00
		},
		// BC:0x0F
		{
			5,
			0x01,0x02,0x03,0x04,0x80
		},
		// BC:0x10
		{
			3,
			0x00,0x01,0x80
		},
		// BC:0x11
		{
			5,
			0x00,0x01,
			0x10,0x20,0x80
		},
		// BC:0x12
		{
			1,
			0x00
		},
		// BC:0x13
		{
			1,
			0x00
		}
};

UINTN Programming_Interface[21][13][8] = {
		// BC:0x00
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			}
		},
		// BC:0x01
		{
			// SC:0x00
			{
				5,
				0x00,0x11,0x12,0x13,0x21
			},
			// SC:0x01
			{
				1,
				0xFF
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				2,
				0x20,0x30
			},
			// SC:0x06
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x07
			{
				2,
				0x00,0x01
			},
			// SC:0x08
			{
				4,
				0x00,0x01,0x02,0x03
			},
			// SC:0x09
			{
				2,
				0x00,0x01
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x02
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0xFF
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x08
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x03
		{
			// SC:0x00
			{
				2,
				0x00,0x01
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x04
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				2,
				0x00,0x80
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x05
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x06
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				2,
				0x00,0x01
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x08
			{
				1,
				0xFF
			},
			// SC:0x09
			{
				2,
				0x40,0x80
			},
			// SC:0x0A
			{
				1,
				0x00
			},
			// SC:0x0B
			{
				2,
				0x00,0x01
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x07
		{
			// SC:0x00
			{
				7,
				0x00,0x01,0x02,0x03,0x04,
				0x05,0x06
			},
			// SC:0x01
			{
				5,
				0x00,0x01,0x02,0x03,0xFE
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				5,
				0x00,0x01,0x02,0x03,0x04
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x08
		{
			// SC:0x00
			{
				5,
				0x00,0x01,0x02,0x10,0x20
			},
			// SC:0x01
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x02
			{
				4,
				0x00,0x01,0x02,0x03
			},
			// SC:0x03
			{
				2,
				0x00,0x01
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x09
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				2,
				0x00,0x10
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0A
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0B
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x30
			{
				1,
				0x00
			},
			// SC:0x40
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0C
		{
			// SC:0x00
			{
				2,
				0x00,0x10
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				6,
				0x00,
				0x10,0x20,0x30,0x80,0xFE
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x05
			{
				1,
				0x00
			},
			// SC:0x06
			{
				1,
				0x00
			},
			// SC:0x07
			{
				3,
				0x00,0x01,0x02
			},
			// SC:0x08
			{
				1,
				0x00
			},
			// SC:0x09
			{
				1,
				0x00
			},
			// SC:0x0A
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0D
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				2,
				0x00,0x10
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x11
			{
				1,
				0x00
			},
			// SC:0x12
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x21
			{
				1,
				0x00
			},
			// SC:0x40
			{
				1,
				0x00
			},
			// SC:0x41
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x0E
		{
			// SC:0x00
			{
				2,
				0x00,0xFF
			}
		},
		// BC:0x0F
		{
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x02
			{
				1,
				0x00
			},
			// SC:0x03
			{
				1,
				0x00
			},
			// SC:0x04
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x10
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x11
		{
			// SC:0x00
			{
				1,
				0x00
			},
			// SC:0x01
			{
				1,
				0x00
			},
			// SC:0x10
			{
				1,
				0x00
			},
			// SC:0x20
			{
				1,
				0x00
			},
			// SC:0x80
			{
				1,
				0x00
			}
		},
		// BC:0x12
		{
			// SC:0x00
			{
				1,
				0x00
			}
		},
		// BC:0x13
		{
			// SC:0x00
			{
				1,
				0x00
			}
		}
};

CHAR8* Description[21][13][8] = {
		// BC:0x00
		{
			// SC:0x00
			{
				// PI:0x00
				{
					"All devices except VGA-compatible devices"
				}
			},
			// SC:0x01
			{
				// PI:0x00
				{
					"VGA-compatible device"
				}
			}
		},
		// BC:0x01
		{
			// SC:0x00
			{
				"SCSI controller - vendor-specific interface",
				"SCSI storage device",
				"SCSI controller - SOP target port using PQI",
				"SCSI storage device and SCSI controller - SOP target port using PQI",
				"SCSI storage device - SOP target port using NVM Express interface"
			},
			// SC:0x01
			{
				"IDE Controller"
			},
			// SC:0x02
			{
				"Floppy disk controller"
			},
			// SC:0x03
			{
				"IPI bus controller"
			},
			// SC:0x04
			{
				"RAID controller - vendor-specific interface"
			},
			// SC:0x05
			{
				"ATA controller with ADMA interface - single stepping",
				"ATA controller with ADMa interface - continuous operatrion"
			},
			// SC:0x06
			{
				"Serial ATA controller - vendor-specific interface",
				"Serial ATA controller - AHCI interaface",
				"Serial Storage Bus Interface"
			},
			// SC:0x07
			{
				"Serail Attached SCSI (SAS) controller - vendor-specific interface",
				"Obsolete"
			},
			// SC:0x08
			{
				"Non-volatile memory subsystem - vendor-specific interface",
				"Non-volatile memory subsystem - NVMHCI interface",
				"NVM Express (NVMe) I/O controller",
				"NVM Express (NVMe) administrative controller"
			},
			// SC:0x09
			{
				"Universal Flash Storage (UFS) controller - vendor-specific interface",
				"Universal Flash Storage (UFS) controller - Universal Flash Storage Host Controller Interface (UFSHCI)"
			},
			// SC:0x80
			{
				"Other mass storage controller - vendor-specific interface"
			}
		},
		// BC:0x02
		{
			//SC:0x00
			{
				"Ethernet controller"
			},
			// SC:0x01
			{
				"Token Ring controller"
			},
			// SC:0x02
			{
				"FDDI controller"
			},
			// SC:0x03
			{
				"ATM controller"
			},
			// SC:0x04
			{
				"ISDN controller"
			},
			// SC:0x05
			{
				"WorldFip controller"
			},
			// SC:0x06
			{
				"PICMG 2.14 Multi Computing"
			},
			// SC:0x07
			{
				"InfiniBand* Controller"
			},
			// SC:0x08
			{
				"Host fabric controller - vendor-specific"
			},
			// SC:0x80
			{
				"Other network controller"
			}
		},
		// BC:0x03
		{
			// SC:0x00
			{
				"VGA-compatible controller",
				"8514-compatible controller"
			},
			// SC:0x01
			{
				"XGA controller"
			},
			// SC:0x02
			{
				"3D controller"
			},
			// SC:0x80
			{
				"Other display controller"
			}
		},
		// BC:0x04
		{
			//SC:0x00
			{
				"Video device - vendor-specific interface"
			},
			// SC:0x01
			{
				"Audio device - vendor-specific interface"
			},
			// SC:0x02
			{
				"Computer telephony device - vendor-specific interface"
			},
			// SC:0x03
			{
				"High Definition Audio (HD-A) 1.0 compatible",
				"High Definition Audio (HD-A) 1.0 compatible with additional vendor specific extensions"
			},
			// SC:0x80
			{
				"Other multimedia device - vendor-specific interface"
			}
		},
		// BC:0x05
		{
			// SC:0x00
			{
				"RAM"
			},
			// SC:0x01
			{
				"Flash"
			},
			// SC:0x80
			{
				"Other memory controller"
			}
		},
		// BC:0x06
		{
			// SC:0x00
			{
				"Host bridge"
			},
			// SC:0x01
			{
				"ISA bridge"
			},
			// SC:0x02
			{
				"EISA bridge"
			},
			// SC:0x03
			{
				"MCA bridge"
			},
			// SC:0x04
			{
				"PCI-to-PCI brdge",
				"Subtractive Decode PCI-to-PCI bridge"
			},
			// SC:0x05
			{
				"PCMCIA bridge"
			},
			// SC:0x06
			{
				"NuBus bridge"
			},
			// SC:0x07
			{
				"CardBus bridge"
			},
			// SC:0x08
			{
				"RACEway bridge"
			},
			// SC:0x09
			{
				"Semi-transparent PCI-to-PCI bridge with the primary PCI bus side",
				"Semi-transparent PCI-to-PCI bridge with the secondary PCI bus side"
			},
			// SC:0x0A
			{
				"InfiniBand-to-PCI host bridge"
			},
			// SC:0x0B
			{
				"Advanced Switching to PCI host bridge - Custiom Interface",
				"Advanced Switching to PCI host bridge - ASI-SIG Defined Portal Interface"
			},
			// SC:0x80
			{
				"Other bridge device"
			}
		},
		// BC:0x07
		{
			// SC:0x00
			{
				"Generic XT-compatible serial controller",
				"16450-compatible serial controller",
				"16550-compatible serial controller",
				"16650-compatible serial controller",
				"16750-compatible serial controller",
				"16850-compatible serial controller",
				"16950-compatible serial controller"
			},
			// SC:0x01
			{
				"Parallel port",
				"Bi-directional parallel port",
				"ECP 1.X compliant parallel port",
				"IEEE 1284 controller",
				"IEEE 1284 target device"
			},
			// SC:0x02
			{
				"Multiport serial controller"
			},
			// SC:0x03
			{
				"Generic modern",
				"Hayes compatible modern, 16450-compatible interface",
				"Hayes compatible modern, 16550-compatible interface",
				"Hayes compatible modern, 16650-compatible interface",
				"Hayes compatible modern, 16750-compatible interface"
			},
			// SC:0x04
			{
				"GPIB (IEEE 488.1/2) controller"
			},
			// SC:0x05
			{
				"Smart Card"
			},
			// SC:0x80
			{
				"Other communications device"
			}
		},
		// BC:0x08
		{
			// SC:0x00
			{
				"Generic 8259 PIC",
				"ISA PIC",
				"EISA PIC",
				"I/O APIC interrput controller",
				"I/O APIC interrupt controller"
			},
			// SC:0x01
			{
				"Generic 8237 DMA controller",
				"ISA DMA controller",
				"EISA DMA controller"
			},
			// SC:0x02
			{
				"Generic 8254 system timer",
				"ISA system timer",
				"EISA system timers",
				"High Performance Event Timer"
			},
			// SC:0x03
			{
				"Generic RTC controller",
				"ISA RTC controller"
			},
			// SC:0x04
			{
				"Generic PCI Hot-Plug controller"
			},
			// SC:0x05
			{
				"SD Host controller"
			},
			// SC:0x06
			{
				"IOMMU"
			},
			// SC:0x07
			{
				"Root Complex Event Collector"
			},
			// SC:0x80
			{
				"Other system peripheral"
			}
		},
		// BC:0x09
		{
			// SC:0x00
			{
				"Keyboard controller"
			},
			// SC:0x01
			{
				"Digitizer (pen)"
			},
			// SC:0x02
			{
				"Mouse controller"
			},
			// SC:0x03
			{
				"Scanner controller"
			},
			// SC:0x04
			{
				"Gameport controller",
				"Gameprot controller"
			},
			// SC:0x80
			{
				"Other input controller"
			}
		},
		// BC:0x0A
		{
			// SC:0x00
			{
				"Generic docking station"
			},
			// SC:0x80
			{
				"Other type of docking station"
			}
		},
		// BC:0x0B
		{
			// SC:0x00
			{
				"386"
			},
			// SC:0x01
			{
				"486"
			},
			// SC:0x02
			{
				"Pentium"
			},
			// SC:0x10
			{
				"Alpha"
			},
			// SC:0x20
			{
				"PowerPC"
			},
			// SC:0x30
			{
				"MIPS"
			},
			// SC:0x40
			{
				"Co-processor"
			},
			// SC:0x80
			{
				"Other processors"
			}
		},
		// BC:0x0C
		{
			// SC:0x00
			{
				"IEEE 1394",
				"IEEE 1394 following the 1394 OpenHCI specification"
			},
			// SC:0x01
			{
				"ACCESS.bus"
			},
			// SC:0x02
			{
				"SSA"
			},
			// SC:0x03
			{
				"Universal Serial Bus (USB) following the Universial Host Controller Specification",
				"Universal Serial Bus (USB) following the Open Host Controller Specification",
				"USB 2 host controller following the Intel Enhanced Host Controller Interface Specification",
				"Universal Serial Bus (USB) Host Controller following the Intel xHCI Specification",
				"Universal Serial Bus with no specific Programming Interface",
				"USB device"
			},
			// SC:0x04
			{
				"Fibre Channel"
			},
			// SC:0x05
			{
				"System Management Bus (SMBus)"
			},
			// SC:0x06
			{
				"InfiniBand"
			},
			// SC:0x07
			{
				"IPMI SMIC Interface",
				"IPMI Keyboard Controller Style Interface",
				"IPMI Block Transfer Interface"
			},
			// SC:0x08
			{
				"SERCOS Interface Standard (IEC 61491)"
			},
			// SC:0x09
			{
				"CANbus"
			},
			// SC:0x0A
			{
				"MIPI I3C Host Controller Interface"
			},
			// SC:0x80
			{
				"Other Serial Bus Controllers"
			}
		},
		// BC:0x0D
		{
			// SC:0x00
			{
				"iRDA compatible controller"
			},
			// SC:0x01
			{
				"Consumer IR controller",
				"UWB Radio controller"
			},
			// SC:0x10
			{
				"RF controller"
			},
			// SC:0x11
			{
				"Bluetooth"
			},
			// SC:0x12
			{
				"Broadband"
			},
			// SC:0x20
			{
				"Ethernet (802.11a - 5 GHz)"
			},
			// SC:0x21
			{
				"Ethernet (802.11b - 2.4 GHz)"
			},
			// SC:0x40
			{
				"Cellular controller/modern"
			},
			// SC:0x41
			{
				"Cellular controller/modern plus Ethernet (802.11)"
			},
			// SC:0x80
			{
				"Other type of wireless controller"
			}
		},
		// BC:0x0E
		{
			// SC:0x00
			{
				"Message FIFO at offset 040h",
				"Intelligent I/O (I20) Architecture Specification 1.0"
			}
		},
		// BC:0x0F
		{
			// SC:0x01
			{
				"TV"
			},
			// SC:0x02
			{
				"Audio"
			},
			// SC:0x03
			{
				"Voice"
			},
			// SC:0x04
			{
				"Data"
			},
			// SC:0x80
			{
				"Other satellite communication controller"
			}
		},
		// BC:0x10
		{
			// SC:0x00
			{
				"Network and computing encryption and decryption controller"
			},
			// SC:0x01
			{
				"Entertainment encryption and decryption controller"
			},
			// SC: 0x80
			{
				"Other encryption and decryption controller"
			}
		},
		// BC:0x11
		{
			// SC:0x00
			{
				"DPIO modules"
			},
			// SC:0x01
			{
				"Performance counters"
			},
			// SC:0x10
			{
				"Communications synchronization plus time and frequency test/measurement"
			},
			// SC:0x20
			{
				"Management card"
			},
			// SC:0x80
			{
				"Other data acquisition/signal processing controllers"
			}
		},
		// BC:0x12
		{
			// SC:0x00
			{
				"Processing Accelerator - vendor-specific interface"
			}
		},
		// BC:0x13
		{
			// SC:0x00
			{
				"Non-Essential Instrumentation Function - vendor-specific interface"
			}
		}
	};

#endif