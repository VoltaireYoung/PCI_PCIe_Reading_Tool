#include  <Library/UefiBootServicesTableLib.h>	//gST and gBS

extern EFI_SYSTEM_TABLE          *gST;

//clean all
VOID  GUI_ScreenClean(
)
{
	gST -> ConOut -> SetAttribute(gST -> ConOut, 0x0F);
	gST -> ConOut -> Reset(gST -> ConOut, 1);
  return;
}

// Show Cursor
VOID  GUI_ShowCursor(
	IN	BOOLEAN	Flag
)
{
	gST->ConOut->EnableCursor (gST->ConOut, Flag);
}

VOID  GUI_GetPosition(
    IN  UINTN   *x,
    IN  UINTN   *y
)
{
    *x = gST->ConOut->Mode->CursorColumn;
    *y = gST->ConOut->Mode->CursorRow;
    return;
}

//Shift Position (ColumnsMAX:80 x RowsMAX:25)
VOID  GUI_SetPosition(
    IN  UINTN   x,
    IN  UINTN   y
)
{
  gST -> ConOut -> SetCursorPosition(gST -> ConOut, x, y);
  return;
}

//SetAttribute (High 4 bits = background, low 4 bits = font)
VOID  GUI_SetColor(
    IN  UINTN   color
)
{
	gST -> ConOut -> SetAttribute(gST -> ConOut, color);
	return;
}

//WaitKey
VOID  GUI_WaitKey(
    IN	EFI_INPUT_KEY	*KeyValue
)
{
	EFI_STATUS		Status;
	UINTN			Index;

	Status = gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &Index);
	if (EFI_ERROR(Status)) {
        Print(L"WaitKey: WaitForEvent Error!\n");
	}
	Status = gST->ConIn->ReadKeyStroke (gST->ConIn, KeyValue);
	if (EFI_ERROR(Status)) {
        Print(L"WaitKey: ReadKeyStroke Error!\n");
    }
	return;
}

//WaitKey Timer
int  GUI_WaitKeyDelay(
    IN	EFI_INPUT_KEY	*KeyValue,
	IN	UINTN			Microsecond
)
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

//Not complete
char*  GUI_TypeString(
)
{
	EFI_STATUS			Status;
	UINTN				Index;
	EFI_INPUT_KEY		*Key;
	char				str[20];
	char				empty = '\0';
	int					p = 0;
	
	str[p] = '\0';
	while(1)
	{
		GUI_WaitKey(Key);
		if(Key->ScanCode == 23)	return empty;
		if(Key->ScanCode == 0 && Key->UnicodeChar == 0){
			str[p] = '\0';
			return str;
		}
		str[p] = Key->UnicodeChar;
		p++;
		
		Print(L"%s", str);
	}
		//if(KeyValue->UnicodeChar == 0) return str;
	return empty;
}


VOID  GUI_Delay(
	IN  UINTN	Microsecond
)
{
	gBS->Stall(Microsecond);
	return;
}