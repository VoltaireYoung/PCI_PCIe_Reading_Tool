#include "MyPCI.h"
#include "MyUI.h"

// Read Certain PCI Device
void Read_PCI_Device(UINTN** array , UINTN base_address , UINTN bus , UINTN device , UINTN function , UINTN current_page){
	UINTN current_address;

	UINTN row , column;

	current_address = PCI_PCIE_ADDRESS(base_address , bus , device , function);
	current_address += (current_page * (READ_PCI_ROW_RANGE * READ_PCI_COLUMN_RANGE));

	for(row = 0 ; row < READ_PCI_ROW_RANGE ; row++){
		for(column = 0 ; column < READ_PCI_COLUMN_RANGE ; column++){
			array[row][column] = MmioRead8(current_address);

			current_address++;
		}
	}
}

// Get Array
UINTN** Get_2D_Array(UINTN row , UINTN column){
	UINTN** array;

	UINTN current_row;

	//array = (UINTN**)malloc(row * sizeof(UINTN*));
	array = (UINTN**)AllocatePool(row * sizeof(UINTN*));

	for(current_row = 0 ; current_row < row ; current_row++){
		//array[current_row] = (UINTN*)calloc(column , sizeof(UINTN));
		array[current_row] = (UINTN*)AllocatePool(column * sizeof(UINTN));
	}

	return array;
}

void Print_2D_Array(UINTN** array , UINTN row , UINTN column){
	UINTN current_row , current_column;

	Print(L"    ");
	for(current_column = 0 ; current_column < column ; current_column++){
		Print(L"%02x " , current_column);
	}
	Print(L"\n");
	Print(L"    ");
	for(current_column = 0 ; current_column < column ; current_column++){
		Print(L"---");
	}
	Print(L"\n");


	for(current_row = 0 ; current_row < row ; current_row++){
		Print(L"%02x| " , current_row);
		for(current_column = 0 ; current_column < column ; current_column++){
			Print(L"%02x " , array[current_row][current_column]);
		}
		Print(L"\n");
	}
}

// Get Description
CHAR8* Get_Description_V2(UINTN base , UINTN bus , UINTN device , UINTN function){
	UINTN address;

	UINTN base_class;
	UINTN sub_class;
	UINTN programming_interface;

	UINTN number_of_base_class;
	UINTN number_of_sub_class;
	UINTN number_of_programming_interface;

	UINTN* current_sub_class_table;
	UINTN* current_programming_interface_table;
	CHAR8** current_description_table;
	UINTN current_sub_class_index;
	UINTN current_programming_interface_index;

	CHAR8* description;

	UINTN temp;

	UINT8 isFound;

	address = PCI_PCIE_ADDRESS(base , bus , device , function);

	base_class = MmioRead8(address + BASE_CLASS_OFFSET);
	sub_class = MmioRead8(address + SUB_CLASS_OFFSET);
	programming_interface = MmioRead8(address + PI_OFFSET);

	number_of_base_class = Base_Class[0];
	if(base_class > number_of_base_class){
		return NULL;
	}

	current_sub_class_table = Sub_Class[base_class];
	number_of_sub_class = current_sub_class_table[0];
	isFound = 0;
	for(current_sub_class_index = 1 ; current_sub_class_index <= number_of_sub_class ; current_sub_class_index++){
		temp = current_sub_class_table[current_sub_class_index];

		if(sub_class == temp){
			isFound = 1;
			break;
		}
	}
	if(!isFound){
		return NULL;
	}

	current_programming_interface_table = Programming_Interface[base_class][current_sub_class_index - 1];
	number_of_programming_interface = current_programming_interface_table[0];
	isFound = 0;
	for(current_programming_interface_index = 1 ; current_programming_interface_index <= number_of_programming_interface ; current_programming_interface_index++){
		temp = current_sub_class_table[current_programming_interface_index];
		if(temp == 0xFF){
			isFound = 1;
			break;
		}
		if(programming_interface == temp){
			isFound = 1;
			break;
		}
	}
	if(!isFound){
		return NULL;
	}

	current_description_table = Description[base_class][current_sub_class_index - 1];

	description = current_description_table[current_programming_interface_index - 1];

	return description;
}