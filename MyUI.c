#include "MyUI.h"

UINTN number_of_PCI_Devices;
UINTN base_address;
UINTN number_of_pages;
My_PCI_Device* PCI_Device;
EFI_INPUT_KEY* Key = NULL;

void Show_Layer_1(My_PCI_Device_List* PCI_Device_List){
	UINTN current_page;

	PCI_Device = PCI_Device_List->PCI_Device;

	UINTN current_device_index;
	UINTN current_showing_index;

	My_PCI_Device* temp;

	number_of_PCI_Devices = PCI_Device_List->Number_of_PCI_Device;
	base_address = PCI_Device_List->Base_Address;

	number_of_pages = number_of_PCI_Devices / L1_LIST_LENGTH;

	current_page = 0;

	current_device_index = 1;
	current_showing_index = 0;

	UINTN r , c;
	gST->ConOut->QueryMode(gST->ConOut , 1 , &r , &c);
	GUI_ShowCursor(FALSE);

	while(1){
		// Initialize Screen
		GUI_ScreenClean();

		// Show Title
		Show_Title(L1_TITLE_X , L1_TITLE_Y , L1_TITLE_COLOR);
		// Show Attributes Bar
		L1_Show_Arrtibutes_bar();
		// Show PCI Device List
		L1_Show_PCI_Device_List(current_page);
		GUI_SetPosition(0 , 23);
		GUI_SetColor(L1_PCI_DEVICE_LIGHT);
		Print(L"ESC : Quit ; PageUp/PageDown : -/+ Page ; Up/Down : Choose Device");

		GUI_WaitKey(Key);
		TEST:
		if(Key->ScanCode == 23){ // ESC
			return;
		}
		else if(Key->ScanCode == 9){ // PageUp
			if(current_page > number_of_pages || current_page < 0){
				Print(L"In Show_Layer_1 - PageUp\n");
				Print(L"Error : Current Page Out of Range\n");
				return;
			}
			else if(current_page == 0){
				current_page = number_of_pages;
			}
			else{ // current_page > 0
				current_page--;
			}

			current_device_index = current_page * L1_LIST_LENGTH + 1;
			current_showing_index = 0;
		}
		else if(Key->ScanCode == 10){ // PageDown
			if(current_page > number_of_pages || current_page < 0){
				Print(L"In Show_Layer_1 - PageDown\n");
				Print(L"Error : Current Page Out of Range\n");
				return;
			}
			else if(current_page == number_of_pages){
				current_page = 0;
			}
			else{
				current_page++;
			}

			current_device_index = current_page * L1_LIST_LENGTH + 1;
			current_showing_index = 0;
		}
		else if(Key->ScanCode == 1){ // Up
			if(current_showing_index == 0){
					if(current_page == 0){
							current_page = number_of_pages;
							L1_Show_PCI_Device_List(current_page);

							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							current_device_index = current_page * L1_LIST_LENGTH + 1;
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 0);

							current_showing_index = (number_of_PCI_Devices - 1) % L1_LIST_LENGTH;
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							current_device_index = number_of_PCI_Devices;
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
					}
					else if(current_page > 0){
							current_page--;
							L1_Show_PCI_Device_List(current_page);

							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							current_device_index = current_page * L1_LIST_LENGTH + 1;
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 0);

							current_showing_index = L1_LIST_LENGTH - 1;
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							current_device_index = (current_page + 1) * L1_LIST_LENGTH;
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
					}
			}
			else if(current_showing_index > 0){
					Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
					temp = &(PCI_Device[current_device_index - 1]);
					Show_PCI_Device(temp , current_device_index , current_showing_index , 0);

					current_showing_index--;
					current_device_index--;
					Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
					temp = &(PCI_Device[current_device_index - 1]);
					Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
			}

			GUI_WaitKey(Key);
			goto TEST;
		}
		else if(Key->ScanCode == 2){ // Down
			if(current_page ==  number_of_pages){
					if(current_showing_index == (number_of_PCI_Devices % L1_LIST_LENGTH - 1)){
							current_page = 0;
							L1_Show_PCI_Device_List(current_page);

							current_showing_index = 0;
							current_device_index = 1;
					}
					else if(current_showing_index >= 0){
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 0);

							current_showing_index++;
							current_device_index++;
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
					}
			}
			else if(current_page >= 0){
					if(current_showing_index == L1_LIST_LENGTH - 1){
							current_page++;
							L1_Show_PCI_Device_List(current_page);

							current_showing_index = 0;
							current_device_index++;
					}
					else if(current_showing_index >= 0){
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 0);

							current_showing_index++;
							current_device_index++;
							Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
							temp = &(PCI_Device[current_device_index - 1]);
							Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
					}
			}
			GUI_WaitKey(Key);
			goto TEST;
		}
		else if(Key->UnicodeChar == 13){ // Enter
			temp = &(PCI_Device[current_device_index - 1]);
			Show_Layer_2(temp);

			GUI_ScreenClean();
			Show_Title(L1_TITLE_X , L1_TITLE_Y , L1_TITLE_COLOR);
			L1_Show_Arrtibutes_bar();
			L1_Show_PCI_Device_List(current_page);
			Clean_Certain_Line(L1_LIST_START_X , L1_LIST_SERIAL_Y);
			temp = &(PCI_Device[current_page * L1_LIST_LENGTH]);
			Show_PCI_Device(temp , current_page * L1_LIST_LENGTH + 1 , 0 , 0);

			Clean_Certain_Line(L1_LIST_START_X + current_showing_index , L1_LIST_SERIAL_Y);
			temp = &(PCI_Device[current_device_index - 1]);
			Show_PCI_Device(temp , current_device_index , current_showing_index , 1);
			GUI_SetPosition(0 , 23);
			GUI_SetColor(L1_PCI_DEVICE_LIGHT);
			Print(L"ESC : Quit | PageUp/PageDown : -/+ Page | Up/Down : Choose Device");

			GUI_WaitKey(Key);
			goto TEST;
		}
		else{
				GUI_WaitKey(Key);
				goto TEST;
		}
	}
}

void L1_Show_Arrtibutes_bar(){
	// Print Attribute Description
	GUI_SetColor(L1_ATTRIBUTE_BAR_COLOR);
	GUI_SetPosition(L1_ATTRIBUTE_DESCRIPTION_Y , L1_ATTRIBUTE_DESCRIPTION_X);
	Print(L"%a\n" , L1_ATTRIBUTE_DESCRIPTION);

	// Print Attribute Bus
	GUI_SetPosition(L1_ATTRIBUTE_BUS_Y , L1_ATTRIBUTE_BUS_X);
	Print(L"%a" , L1_ATTRIBUTE_BUS);

	// Print Attribute Device
	GUI_SetPosition(L1_ATTRIBUTE_DEVICE_Y , L1_ATTRIBUTE_DEVICE_X);
	Print(L"%a" , L1_ATTRIBUTE_DEVICE);

	// Print Attribute Programming Interface
	GUI_SetPosition(L1_ATTRIBUTE_PROGRAMMING_INTERFACE_Y , L1_ATTRIBUTE_PROGRAMMING_INTERFACE_X);
	Print(L"%a" , L1_ATTRIBUTE_PROGRAMMING_INTERFACE);

	return;
}

void L1_Show_PCI_Device_List(UINTN current_page){
	UINTN showing_length;

	My_PCI_Device* current_device;

	UINTN current_device_index;
	UINTN showing_index;

	for(showing_index = 0 ; showing_index < L1_LIST_LENGTH ; showing_index++){
			Clean_Certain_Line(L1_LIST_START_X + showing_index , L1_LIST_SERIAL_Y);
	}

	showing_length = (current_page == number_of_pages) ? (number_of_PCI_Devices - number_of_pages * L1_LIST_LENGTH) : L1_LIST_LENGTH;

	current_device_index = current_page * L1_LIST_LENGTH + 1;
	current_device = &(PCI_Device[current_device_index - 1]);
	showing_index = 0;

	Show_PCI_Device(current_device , current_device_index , showing_index , 1);
	current_device++;
	current_device_index++;
	showing_index++;

	while(showing_index < showing_length){
		Show_PCI_Device(current_device , current_device_index , showing_index , 0);
		current_device++;
		current_device_index++;
		showing_index++;
	}
}

void Show_PCI_Device(My_PCI_Device* current_device , UINTN device_index , UINTN index , UINTN isLight){
	UINTN current_x;

	current_x = L1_LIST_START_X + index;

	if(isLight == 1){
		GUI_SetColor(L1_PCI_DEVICE_LIGHT);
	}
	else{
		GUI_SetColor(L1_PCI_DEVICE_LIST_COLOR);
	}

	// Show Serial Number
	GUI_SetPosition(L1_LIST_SERIAL_Y , current_x);
	Print(L"[%02d]" , device_index);

	// Get and Show Description
	CHAR8* current_description;
	current_description = Get_Description_V2(base_address , current_device->Bus , current_device->Device , current_device->Function);
	GUI_SetPosition(L1_LIST_DESCRIPTION_Y , current_x);
	Print(L"%a" , current_description);

	GUI_SetPosition(L1_LIST_BUS_Y , current_x);
	Print(L"0x%02x" , current_device->Bus);

	GUI_SetPosition(L1_LIST_DEVICE_Y , current_x);
	Print(L"0x%02x" , current_device->Device);

	GUI_SetPosition(L1_LIST_PROGRAMMING_INTERFACE , current_x);
	Print(L"0x%02x" , current_device->Function);
}


// L2 Showing
void Show_Layer_2(My_PCI_Device* target_device){
	//EFI_INPUT_KEY* Key = NULL;

	UINTN** data;

	UINTN bus;
	UINTN device;
	UINTN function;
	CHAR8* description;

	//UINT8 isPCIE;

	//UINTN Capabilities_Pointer;
	UINTN current_page;
	UINT8 isPCIE;

	data = Get_2D_Array(READ_PCI_ROW_RANGE , READ_PCI_COLUMN_RANGE);

	bus = target_device->Bus;
	device = target_device->Device;
	function = target_device->Function;
	description = Get_Description_V2(base_address , target_device->Bus , target_device->Device , target_device->Function);

	current_page = 1;
	isPCIE = Check_PCIE(PCI_PCIE_ADDRESS(base_address , bus , device , function));
	//Capabilities_Pointer = MmioRead8(PCI_PCIE_ADDRESS(base_address , bus , device, function) + 52);
	//if(Capabilities_Pointer > 0){
	//	isPCIE = 1;
	//}
	//else{
	//	isPCIE = 0;
	//}

	UINTN r , c;
	gST->ConOut->QueryMode(gST->ConOut , 1 , &r , &c);
	GUI_ShowCursor(FALSE);
	GUI_ScreenClean();

	Show_Title(L2_TITLE_COLUMN , L2_TITLE_ROW , L2_TITLE_COLOR);
	// Show Description...etc Information
	GUI_SetPosition(L2_DESCRIPTION_COLUMN , L2_DESCRIPTION_ROW);
	GUI_SetColor(L2_DESCRIPTION_COLOR);
	Print(L"Device Description : %a" , description);
	GUI_SetPosition(L2_DESCRIPTION_COLUMN , L2_DESCRIPTION_ROW + 1);
	if(isPCIE){
		Print(L"Type : PCI Express\n");
	}
	else{
		Print(L"Type : PCI\n");
	}
	Print(L"Bus : %x | Device : %x | Function : %x\n" , bus , device , function);
	GUI_SetPosition(0 , 22);
	Print(L"Base Address : %x" , PCI_PCIE_ADDRESS(base_address , bus , device , function));

	GUI_SetPosition(L2_DATA_COLUMN , L2_DATA_ROW);
	Read_PCI_Device(data , base_address , bus , device , function , 0);
	//Print_2D_Array(data , READ_PCI_ROW_RANGE , READ_PCI_COLUMN_RANGE);
	L2_Print_Data(data , READ_PCI_ROW_RANGE , READ_PCI_COLUMN_RANGE , current_page - 1);
	GUI_SetPosition(0 , 23);
	GUI_SetColor(L1_PCI_DEVICE_LIGHT);
	Print(L"ESC : Back to Device List | PageUp/PageDown : -/+ Page");

	while(1){
		GUI_WaitKey(Key);

		if(Key->ScanCode == 23){ // ESC
			return;
		}
		else if(Key->ScanCode == 9){ // PageUp
			if(!isPCIE){
				continue;
			}

			if(current_page == 1){
				current_page = NUMBER_OF_PCIE_PAGES;
			}
			else{
				current_page--;
			}


		}
		else if(Key->ScanCode == 10){ // PageDown
			if(!isPCIE){
				continue;
			}

			if(current_page >= NUMBER_OF_PCIE_PAGES){
				current_page = 1;
			}
			else{
				current_page++;
			}
		}
		else{
			continue;
		}

		Clean_L2_Data();
		Read_PCI_Device(data , base_address , bus , device , function , current_page - 1);
		L2_Print_Data(data , READ_PCI_ROW_RANGE , READ_PCI_COLUMN_RANGE , current_page - 1);
	}
}

void L2_Print_Data(UINTN** data , UINTN row , UINTN column , UINTN current_page){
	UINTN current_row;
	UINTN current_column;

	GUI_SetPosition(L2_DATA_POSITION_HORIZONTAL_BAR_COLUMN + 2 , L2_DATA_POSITION_HORIZONTAL_BAR_ROW);
	for(current_column = 0 ; current_column < column ; current_column++){
		Print(L"%02x " , current_column);
	}

	GUI_SetPosition(L2_DATA_POSITION_HORIZONTAL_SEPERATE_COLUMN + 2, L2_DATA_POSITION_HORIZONTAL_SEPERATE_ROW);
	for(current_column = 0 ; current_column < column ; current_column++){
		Print(L"---" , current_column);
	}

	GUI_SetPosition(L2_DATA_POSITION_VERTICAL_BAR_COLUMN , L2_DATA_POSITION_VERTICAL_BAR_ROW);
	for(current_row = 0 ; current_row < row ; current_row++){
			Print(L"%04x|\n" , current_row * 0x10 + 0x100 * current_page);
	}

	for(current_row = 0 ; current_row < row ; current_row++){
		for(current_column = 0 ; current_column < column ; current_column++){
			GUI_SetPosition(L2_DATA_COLUMN + (current_column * (L2_DATA_WIDTH + 1)) , L2_DATA_ROW + current_row);
			Print(L"%02x" , data[current_row][current_column]);
		}
	}
}

void Clean_L2_Data(){
	UINTN current_row , current_column;

	for(current_row = 0 ; current_row < READ_PCI_ROW_RANGE ; current_row++){
		for(current_column = 0 ; current_column < READ_PCI_COLUMN_RANGE ; current_column++){
			GUI_SetPosition(L2_DATA_COLUMN + current_column , L2_DATA_ROW + current_row);
			Print(L"%2s" , " ");
		}
	}
}

// Base Component
void Show_Title(UINTN TITLE_X , UINTN TITLE_Y , UINTN TITLE_COLOR){
	GUI_SetPosition(TITLE_Y , TITLE_X);
	GUI_SetColor(TITLE_COLOR);
	Print(L"Utility Tool - Version : %a <By %a>\n" , VERSION , AUTHOR);
	return;
}

void Clean_Certain_Line(UINTN row , UINTN column){
	GUI_SetPosition(column , row);
	Print(L"%80s", " ");
}

UINT8 Check_PCIE(UINTN address){
	UINTN temp;

	// Check Status No.5 bit
	temp = MmioRead8(address + 0x06);
	temp &= 0x10;
	if(temp == 0){
		return 0;
	}

	// Check Capabilities Pointer
	UINT8 isPCIE;

	UINTN next_offset;

	isPCIE = 0;

	next_offset = MmioRead8(address + 0x34);
	temp = next_offset;
	while(temp != 0x00){
		temp = MmioRead8(address + next_offset);
		next_offset = MmioRead8(address + next_offset + 1);

		if(temp == 0x10){
			isPCIE = 1;
			break;
		}
	}

	return isPCIE;
}

// Componenet
//Clean All
void  GUI_ScreenClean(
)
{
	gST -> ConOut -> SetAttribute(gST -> ConOut, 0x0F);
	gST -> ConOut -> Reset(gST -> ConOut, 1);
  	return;
}

// Show Cursor
void  GUI_ShowCursor(BOOLEAN Flag)
{
	gST->ConOut->EnableCursor (gST->ConOut, Flag);
}

void  GUI_GetPosition(UINTN *x , UINTN *y)
{
    *x = gST->ConOut->Mode->CursorColumn;
    *y = gST->ConOut->Mode->CursorRow;
    return;
}

//Shift Position (ColumnsMAX:80 x RowsMAX:25)
void  GUI_SetPosition(UINTN x , UINTN y)
{
  gST -> ConOut -> SetCursorPosition(gST -> ConOut, x, y);
  return;
}

//SetAttribute (High 4 bits = background, low 4 bits = font)
void  GUI_SetColor(UINTN color)
{
	gST -> ConOut -> SetAttribute(gST -> ConOut, color);
	return;
}

//WaitKey
void  GUI_WaitKey(EFI_INPUT_KEY	*KeyValue)
{
	EFI_STATUS		Status;
	UINTN			Index;

	Status = gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &Index);
	if (EFI_ERROR(Status)) {
        //Print(L"WaitKey: WaitForEvent Error!\n");
	}
	Status = gST->ConIn->ReadKeyStroke (gST->ConIn, KeyValue);
	if (EFI_ERROR(Status)) {
        //Print(L"WaitKey: ReadKeyStroke Error!\n");
    }
	return;
}

//WaitKey Timer
int  GUI_WaitKeyDelay(EFI_INPUT_KEY	*KeyValue , UINTN Microsecond)
{
	EFI_STATUS		Status;
	UINTN			Index;
	EFI_EVENT		TimerEvent;
    EFI_EVENT		WaitList[2];
	
	Status = gBS->CreateEvent (EVT_TIMER, 0, NULL, NULL, &TimerEvent);
	// Set a timer event of 1 second expiration = 10000000
	Status = gBS->SetTimer (TimerEvent, TimerRelative, Microsecond);	
	
	WaitList[0] = gST->ConIn->WaitForKey;  
	WaitList[1] = TimerEvent;  
	
	//do 
	//{
	Status = gBS->WaitForEvent (2, WaitList, &Index);  
		
	if(Status == EFI_SUCCESS && Index == 0) {
		gBS->CloseEvent (TimerEvent); 
		gST->ConIn->ReadKeyStroke(gST->ConIn, KeyValue);
		return 1;
	}
	gBS->CloseEvent (TimerEvent); 
	return 0;
	//}while(EFI_ERROR (Status)); 
}

VOID  GUI_Delay(UINTN Microsecond)
{
	gBS->Stall(Microsecond);
	return;
}