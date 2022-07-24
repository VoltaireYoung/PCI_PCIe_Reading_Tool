#include "MyACPI_V4.h"
#include "MyPCI.h"
#include "MyUI.h"

void Test();

EFI_STATUS
main (EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_SYSTEM_TABLE* temp_system_table = SystemTable;

	// Layer 1 Testing
	EFI_INPUT_KEY* Key = NULL;

	//My_PCI_Device_List* PCI_Device_List = NULL;
	My_PCI_Device_List* PCI_Device_List = Scan_All_Device(temp_system_table);
	while(1){
		Show_Layer_1(PCI_Device_List);
		GUI_WaitKey(Key);
		if(Key->ScanCode == 23){
			GUI_ScreenClean();
			GUI_SetPosition(0,0);
			GUI_ShowCursor(TRUE);
			break;
		}
	}
}