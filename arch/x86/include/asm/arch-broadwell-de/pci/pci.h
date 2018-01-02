/* pci.h - Simple PCI configuration interface. This implementation
 *         only supports type 1 accesses to configuration space,
 *         and it ignores the PCI BIOS.
 *
 * This file is part of Metalkit, a simple collection of modules for
 * writing software that runs on the bare metal. Get the latest code
 * at http://svn.navi.cx/misc/trunk/metalkit/
 *
 * Copyright (c) 2017 Vincenzo Bove
 */

#ifndef __PCI_H__
#define __PCI_H__

typedef long long int64;
typedef unsigned long long uint64;

typedef int int32;
typedef unsigned int uint32;

typedef short int16;
typedef unsigned short uint16;

typedef char int8;
typedef unsigned char uint8;

typedef uint8 Bool;

typedef struct {
   int x, y;
} IVec2;

#define NULL_P   ((void*)0)
#define TRUE   1
#define FALSE  0

#define offset_of(type, member)  ((uint32)(&((type*)NULL_P)->member))

typedef union PCIConfigSpace {
   uint32 words[16];
   struct {
      uint16 vendorId;
      uint16 deviceId;
      uint16 command;
      uint16 status;
      uint16 revisionId;
      uint8  subclass;
      uint8  classCode;
      uint8  cacheLineSize;
      uint8  latTimer;
      uint8  headerType;
      uint8  BIST;
      uint32 BAR[6];
      uint32 cardbusCIS;
      uint16 subsysVendorId;
      uint16 subsysId;
      uint32 expansionRomAddr;
      uint32 reserved0;
      uint32 reserved1;
      uint8  intrLine;
      uint8  intrPin;
      uint8  minGrant;
      uint8  maxLatency;
   };
} __attribute__ ((__packed__)) PCIConfigSpace;

typedef struct PCIAddress {
   uint8 bus, device, function;
} PCIAddress;

typedef struct PCIScanState {
   uint16     vendorId;
   uint16     deviceId;
   PCIAddress nextAddr;
   PCIAddress addr;
} PCIScanState;

// BAR bits
#define PCI_CONF_BAR_IO          0x01
#define PCI_CONF_BAR_64BIT       0x04
#define PCI_CONF_BAR_PREFETCH    0x08

uint32 PCI_ConfigRead32(const PCIAddress *addr, uint16 offset);
uint16 PCI_ConfigRead16(const PCIAddress *addr, uint16 offset);
uint8 PCI_ConfigRead8(const PCIAddress *addr, uint16 offset);
void PCI_ConfigWrite32(const PCIAddress *addr, uint16 offset, uint32 data);
void PCI_ConfigWrite16(const PCIAddress *addr, uint16 offset, uint16 data);
void PCI_ConfigWrite8(const PCIAddress *addr, uint16 offset, uint8 data);

Bool PCI_ScanBus(PCIScanState *state);
Bool PCI_FindDevice(uint16 vendorId, uint16 deviceId, PCIAddress *addrOut);
void PCI_SetBAR(const PCIAddress *addr, int index, uint32 value);
uint32 PCI_GetBARAddr(const PCIAddress *addr, int index);
void PCI_SetMemEnable(const PCIAddress *addr, Bool enable);

static __inline__ void
IO_Out8(uint16 port, uint8 value)
{
   __asm__ __volatile__ ("outb %0, %1" : :"a" (value), "d" (port));
}

static __inline__ void
IO_Out16(uint16 port, uint16 value)
{
   __asm__ __volatile__ ("outw %0, %1" : :"a" (value), "d" (port));
}

static __inline__ void
IO_Out32(uint16 port, uint32 value)
{
   __asm__ __volatile__ ("outl %0, %1" : :"a" (value), "d" (port));
}

static __inline__ uint8
IO_In8(uint16 port)
{
   uint8 value;
   __asm__ __volatile__ ("inb %1, %0" :"=a" (value) :"d" (port));
   return value;
}

static __inline__ uint16
IO_In16(uint16 port)
{
   uint16 value;
   __asm__ __volatile__ ("inw %1, %0" :"=a" (value) :"d" (port));
   return value;
}

static __inline__ uint32
IO_In32(uint16 port)
{
   uint32 value;
   __asm__ __volatile__ ("inl %1, %0" :"=a" (value) :"d" (port));
   return value;
}

#endif /* __PCI_H__ */
