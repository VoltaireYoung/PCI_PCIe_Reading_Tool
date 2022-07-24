#include <Uefi.h>
#include <Library/UefiLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Library/MemLibInternals.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>

#include <cJSON/cJSON.h>

#ifndef _MY_ACPI_V4_H_
#define _MY_ACPI_V4_H_

typedef struct {
    CHAR8   Signature[4];
    UINT32  Length;
    UINT8   Revision;
    UINT8   Checksum;
    CHAR8   OemId[6];
    CHAR8   OemTableId[8];
    UINT32  OemRevision;
    UINT32  CreatorId;
    UINT32  CreatorRevision;
} EFI_ACPI_SDT_HEADER;

#define EFI_ACPI_20_TABLE_GUID \
    { 0x8868e871, 0xe4f1, 0x11d3, {0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 }}

/*
typedef struct{
    UINTN Bus;
    UINTN Device;
    UINTN Function;
    UINTN VendorID;
    UINTN DeviceID;
    UINTN BaseClass;
    UINTN SubClass;
    UINTN ProgrammingInterface;
    char* Description;
} My_PCI_Device;

typedef struct{
    UINTN Number_of_PCI_Device;
    UINTN Base_Address;
    My_PCI_Device* PCI_Device;
} My_PCI_Device_List;
*/

typedef struct{
    UINTN Bus;
    UINTN Device;
    UINTN Function;
    //char* Description;
} My_PCI_Device;

typedef struct{
    UINTN Number_of_PCI_Device;
    UINTN Base_Address;
    My_PCI_Device* PCI_Device;
} My_PCI_Device_List;


#define PCI_PCIE_ADDRESS(base , bus , device , function) \
        (UINTN) ( (UINTN)base | \
                  ((UINTN)bus << 20) | \
                  ((UINTN)device << 15) | \
                  ((UINTN)function << 12) )

// Scan Device
My_PCI_Device_List* Scan_All_Device(EFI_SYSTEM_TABLE*);
UINTN Get_Number_of_PCI_Device(UINTN*);
void Print_PCI_Device_List(My_PCI_Device*,UINTN);

// PCI Information
UINTN* Get_PCI_Information(EFI_SYSTEM_TABLE*);
UINTN* Get_PCI_Information_V2();
UINT8 Check_PCI_Information(UINTN*);
EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER* Get_RSDP(EFI_SYSTEM_TABLE*);
UINTN Get_MCFG(EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER*);
UINT8 Compare_String(CHAR8*,CHAR8*,UINTN);

// Read JSON
char* CLASS_CODE_FILE_NAME = "Class_Code_Table.json";
cJSON* Read_Class_Code_JSON();
char* Get_Data_From_File(char*);
long Get_File_Length(FILE*);
void Print_Data(char*,long);
char* Get_Description(cJSON*,UINTN,UINTN,UINTN);

char* RSDP_SIGNATURE = "RSD PTR ";
char* MCFG_SIGNATURE = "MCFG";

UINTN BASE_ADDRESS_OFFSET = 44;
UINTN BUS_START_OFFSET = 54;
UINTN BUS_END_OFFSET = 55;

UINTN BUS_LIMITATION = 256;
UINTN DEVICE_LIMITATION = 32;
UINTN FUNCTION_LIMITATION = 8;

UINTN BASE_CLASS_OFFSET = 11;
UINTN SUB_CLASS_OFFSET = 10;
UINTN PI_OFFSET = 9;

#endif