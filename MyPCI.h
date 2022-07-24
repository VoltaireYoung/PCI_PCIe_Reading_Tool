#include <Uefi.h>
#include <Library/UefiLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <Library/MemoryAllocationLib.h>

#include "MyACPI_V4.h"
#include "MyDescription.h"

#ifndef _MY_PCI_
#define _MY_PCI_

// Read 
void Read_PCI_Device(UINTN**,UINTN,UINTN,UINTN,UINTN,UINTN);

// Get Array
UINTN** Get_2D_Array(UINTN,UINTN);
void Print_2D_Array(UINTN**,UINTN,UINTN);

// Get Description
CHAR8* Get_Description_V2(UINTN,UINTN,UINTN,UINTN);
#endif