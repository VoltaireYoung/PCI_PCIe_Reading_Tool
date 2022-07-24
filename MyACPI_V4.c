#include "MyACPI_V4.h"

// Scan Device
My_PCI_Device_List* Scan_All_Device(EFI_SYSTEM_TABLE* SystemTable){
    //My_PCI_Device* PCI_Device_List;
    My_PCI_Device_List* Result = (My_PCI_Device_List*)malloc(1 * sizeof(My_PCI_Device_List)); 

    //My_PCI_Device_List* Result = (My_PCI_Device_List*)AllocatePool(1 * sizeof(My_PCI_Device_List));

    UINTN number_of_PCI_Device;

    // PCI_Information[0] : Base Address
    // PCI_Information[1] : Bus Start
    // PCI_Information[2] : Bus End
    UINTN* PCI_Information;

    //cJSON* ClassCodeTable;

    UINTN bus = 0;
    UINTN device = 0;
    UINTN function = 0;
    UINTN base_address;
    UINTN address;
    My_PCI_Device* current_PCI_Device;
    UINTN PCI_Device_index;
    UINTN VendorID , DeviceID;
    UINTN BaseClass , SubClass , ProgrammingInterface;
    //char* Description;

    //PCI_Information = Get_PCI_Information(SystemTable);
    PCI_Information = Get_PCI_Information_V2();
    if(Check_PCI_Information(PCI_Information)){
        Print(L"In Scan_All_Device\n");
        Print(L"Error : Invalid PCI Information\n");
        return NULL;
    }

    number_of_PCI_Device = Get_Number_of_PCI_Device(PCI_Information);
    Print(L"Number of PCI Device : %d\n",number_of_PCI_Device);
    Result->Number_of_PCI_Device = number_of_PCI_Device;
    Result->Base_Address = PCI_Information[0];
    Result->PCI_Device = (My_PCI_Device*)malloc(number_of_PCI_Device * sizeof(My_PCI_Device*));
    //Result->PCI_Device = (My_PCI_Device*)AllocatePool(number_of_PCI_Device * sizeof(My_PCI_Device*));

    //ClassCodeTable = Read_Class_Code_JSON();
    Print(L"Base Address : %x\n" , PCI_Information[0]);
    Print(L"Bus Start    : %x\n" , PCI_Information[1]);
    Print(L"Bus End      : %x\n" , PCI_Information[2]);

    current_PCI_Device = Result->PCI_Device;
    PCI_Device_index = 1;

    base_address = PCI_Information[0];

    for(bus = PCI_Information[1] ; bus < PCI_Information[2] ; bus++){
        for(device = 0 ; device < DEVICE_LIMITATION ; device++){
            for(function = 0 ; function < FUNCTION_LIMITATION ; function++){
                address = PCI_PCIE_ADDRESS(base_address , bus , device , function);
                VendorID = MmioRead16(address);
                DeviceID = MmioRead16(address + 2);

                if(VendorID == 0xFFFF && DeviceID == 0xFFFF){
                    continue;
                }

                if(PCI_Device_index > number_of_PCI_Device){
                    continue;
                }

                BaseClass = MmioRead8(address + 11);
                SubClass = MmioRead8(address + 10);
                ProgrammingInterface = MmioRead8(address + 9);
                //Print(L"Current Index : %d\n" , PCI_Device_index);
                //Description = Get_Description(ClassCodeTable , BaseClass , SubClass , ProgrammingInterface);
                //Description = "12";
                Print(L"Index : %d\n" , PCI_Device_index);
                Print(L"Base Address : %x - %x ; Address %x \n",base_address , PCI_Information[0] , address);
                Print(L"Bus : %x ; Device : %x ; Function : %x\n",bus , device , function);
                //Print(L"VendorID : %x ; DeviceID : %x\n" , VendorID , DeviceID);
                //Print(L"Base Class : %x ; Sub Class : %x ; PI : %x\n",BaseClass , SubClass, ProgrammingInterface);

                current_PCI_Device->Bus = bus;
                current_PCI_Device->Device = device;
                current_PCI_Device->Function = function;
                //current_PCI_Device->VendorID = VendorID;
                //current_PCI_Device->DeviceID = DeviceID;
                //current_PCI_Device->BaseClass = BaseClass;
                //current_PCI_Device->SubClass = SubClass;
                //current_PCI_Device->ProgrammingInterface = ProgrammingInterface;
                //current_PCI_Device->Description = NULL;

                current_PCI_Device++;
                PCI_Device_index++;
            }
        }
    }

    //Print_PCI_Device_List(Result->PCI_Device , 15);
    return Result;
}

UINTN Get_Number_of_PCI_Device(UINTN* PCI_Information){
    if(Check_PCI_Information(PCI_Information)){
        Print(L"In Get_Number_of_PCI_Device\n");
        Print(L"Error : Bus out of limitation\n");
        return 0;
    }

    UINTN Number_of_PCI_Device;

    UINTN bus , device , function;
    UINTN address;
    UINTN VendorID , DeviceID;

    Number_of_PCI_Device = 0;

    for(bus = PCI_Information[1] ; bus <= PCI_Information[2] ; bus++){
        for(device = 0 ; device < DEVICE_LIMITATION ; device++){
            for(function = 0 ; function < FUNCTION_LIMITATION ; function++){
                address = PCI_PCIE_ADDRESS(PCI_Information[0] , bus , device , function);

                VendorID = MmioRead16(address);
                DeviceID = MmioRead16(address + 2);

                if(VendorID != 0xFFFF && DeviceID != 0xFFFF){
                    Number_of_PCI_Device++;
                }
            }
        } 
    }

    return Number_of_PCI_Device;
}

void Print_PCI_Device_List(My_PCI_Device* PCI_Device_List , UINTN number_of_PCI_Device){
    My_PCI_Device* current_PCI_Device = PCI_Device_List;
    UINTN index = 1;

    while(index <= number_of_PCI_Device){
        Print(L"No.%03d : \n" , index);
        Print(L"Bus : %03d -- Device : %03d -- Function : %03d \n" , current_PCI_Device->Bus , current_PCI_Device->Device , current_PCI_Device->Function);
        //Print(L"VendorID : %02X \n" , current_PCI_Device->VendorID);
        //Print(L"DeviceID : %02X \n" , current_PCI_Device->DeviceID);
        //Print(L"Base Class : %02X -- Sub Class : %02X -- Programming Interface : %02X\n" , current_PCI_Device->BaseClass , current_PCI_Device->SubClass , current_PCI_Device->ProgrammingInterface);
        //Print(L"Description : %a\n" , current_PCI_Device->Description);
        Print(L"\n");

        index++;
        current_PCI_Device++;
    }
}


// PCI Information
UINTN* Get_PCI_Information(EFI_SYSTEM_TABLE* SystemTable){
    UINTN* PCI_Information = (UINTN*)malloc(3 * sizeof(UINTN));
    //UINTN* PCI_Information = (UINTN*)AllocatePool(3 * sizeof(UINTN));

    EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER* RSDP = Get_RSDP(SystemTable);
    UINTN MCFG;

    RSDP = Get_RSDP(SystemTable);
    MCFG = Get_MCFG(RSDP);

    PCI_Information[0] = MmioRead64(MCFG + BASE_ADDRESS_OFFSET);
    PCI_Information[1] = MmioRead8(MCFG + BUS_START_OFFSET);
    PCI_Information[2] = MmioRead8(MCFG + BUS_END_OFFSET);

    return PCI_Information;
}

UINTN* Get_PCI_Information_V2(){
    //EFI_GUID gEfiAcpi20TableGuid = { 0x8868E871, 0xE4F1, 0x11D3, { 0xBC, 0x22, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81}};
    EFI_STATUS Status;

    EFI_ACPI_DESCRIPTION_HEADER                     *XSDT;
    EFI_ACPI_6_1_ROOT_SYSTEM_DESCRIPTION_POINTER    *RSDP;


    Status=EfiGetSystemConfigurationTable(&gEfiAcpi20TableGuid,(VOID**)&RSDP);
    if(EFI_ERROR(Status)) {
        Print(L"Can't find Acpi Table\n");
        return NULL;
    }

    XSDT=(EFI_ACPI_DESCRIPTION_HEADER*)RSDP->XsdtAddress;

    UINT32 number_of_entries;
    number_of_entries = (XSDT->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) / sizeof(UINT64);

    Print(L"Number of Entries : %d\n" , number_of_entries);

    UINT64* current_entry_pointer;
    UINTN current_entry;
    UINT32 current_entry_index;

    UINT8 isMatch;

    current_entry_pointer = (UINT64*)(XSDT + 1);
    current_entry_index = 0;
    current_entry = 0;
    isMatch = 0;

    UINT8           *p;

    while(current_entry_index < number_of_entries){
        current_entry = (UINTN)(*current_entry_pointer);
        p=(UINT8*)(*current_entry_pointer);
        Print(L" Signature [%c%c%c%c]\n",*p,*(p+1),*(p+2),*(p+3));

        isMatch = Compare_String(MCFG_SIGNATURE , (CHAR8*)(current_entry) , 4);

        if(isMatch){
            break;
        }


        current_entry_pointer++;
        current_entry_index++;
    }

    if(isMatch != 1){
        Print(L"MCFG Not Found\n");
        return NULL;
    }

    UINTN MCFG = current_entry;
    UINTN* PCI_Information = (UINTN*)malloc(3 * sizeof(UINTN));

    PCI_Information[0] = MmioRead64(MCFG + BASE_ADDRESS_OFFSET);
    PCI_Information[1] = MmioRead8(MCFG + BUS_START_OFFSET);
    PCI_Information[2] = MmioRead8(MCFG + BUS_END_OFFSET);

    return PCI_Information;
}

UINT8 Check_PCI_Information(UINTN* PCI_Information){
    UINT8 isValid;

    UINTN Bus_Start;
    UINTN Bus_End;

    isValid = 0;

    Bus_Start = PCI_Information[1];
    Bus_End = PCI_Information[2];

    if(Bus_Start > Bus_End){
        Print(L"In Check_PCI_Information\n");
        Print(L"Error : Bus Start Greater than Bus End\n");
        isValid = 1;
    }

    if(Bus_Start >= BUS_LIMITATION || Bus_Start < 0){
        Print(L"In Check_PCI_Information\n");
        Print(L"Error : Invalid Bus Start\n");
        isValid = 1;
    }

    if(Bus_End >= BUS_LIMITATION || Bus_End < 0){
        Print(L"In Check_PCI_Information\n");
        Print(L"Error : Invalid Bus End\n");
        isValid = 1;
    }

    return isValid;
}

EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER* 
Get_RSDP(EFI_SYSTEM_TABLE *SystemTable){
    if(SystemTable == NULL){
        Print(L"In Get_RSDP\n");
        Print(L"Error : Invalid System Table\n");
    }

    EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER *RSDP;

    UINTN number_of_system_table;
    UINTN current_system_table_index;
    EFI_CONFIGURATION_TABLE* current_system_table;
    CHAR8* current_system_table_signature;
    UINTN isMatch_Signature;
    UINTN isMatch_GUID;

    EFI_GUID Acpi2TableGuid = EFI_ACPI_20_TABLE_GUID;

    RSDP = NULL;

    current_system_table = SystemTable->ConfigurationTable;
    current_system_table_index = 0;
    number_of_system_table = SystemTable->NumberOfTableEntries;
    while(current_system_table_index < number_of_system_table){
        current_system_table_signature = (CHAR8*)(current_system_table->VendorTable);

        isMatch_Signature = Compare_String(RSDP_SIGNATURE , current_system_table_signature , 8);
        isMatch_GUID = CompareGuid(&(current_system_table->VendorGuid) , &Acpi2TableGuid);

        if(isMatch_Signature && isMatch_GUID){
            break;
        }

        current_system_table++;
        current_system_table_index++;
    }

    if(!isMatch_Signature || !isMatch_GUID){
        Print(L"RSDP Not Found\n");

        return NULL;
    }
    
    else{
        RSDP = (EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER*)(current_system_table->VendorTable);
    }

    return RSDP;
}

UINTN
Get_MCFG(EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER* RSDP){
    EFI_ACPI_SDT_HEADER *XSDT;

    UINT32 number_of_entries;
    UINT64* current_entry_pointer;
    UINTN current_entry;
    UINT32 current_entry_index;

    UINT8 isMatch;

    XSDT = (EFI_ACPI_SDT_HEADER*)(RSDP->XsdtAddress);

    number_of_entries = (XSDT->Length - sizeof(EFI_ACPI_SDT_HEADER)) / sizeof(UINT64);

    current_entry_pointer = (UINT64*)(XSDT + 1);
    current_entry_index = 0;
    current_entry = 0;
    isMatch = 0;
    while(current_entry_index < number_of_entries){
        current_entry = (UINTN)(*current_entry_pointer);

        isMatch = Compare_String(MCFG_SIGNATURE , (CHAR8*)(current_entry) , 4);

        if(isMatch){
            break;
        }


        current_entry_pointer++;
        current_entry_index++;
    }

    if(isMatch != 1){
        Print(L"MCFG Not Found\n");
        return 0;
    }

    return current_entry;
}

UINT8 
Compare_String(CHAR8* string_1 , CHAR8* string_2 , UINTN length){
    UINT8 isMatch;

    CHAR8* current_character_of_string_1;
    CHAR8* current_character_of_string_2;

    isMatch = 1;

    current_character_of_string_1 = string_1;
    current_character_of_string_2 = string_2;

    while(length > 0){
        if(*current_character_of_string_1 != *current_character_of_string_2){
            isMatch = 0;
            break;
        }

        current_character_of_string_1++;
        current_character_of_string_2++;
        length--;
    }

    return isMatch;
}

// Read JSON
cJSON* Read_Class_Code_JSON(){
    char* data;

    cJSON* root = NULL;

    data = Get_Data_From_File(CLASS_CODE_FILE_NAME);

    root = cJSON_Parse(data);

    return root;
}

char* Get_Data_From_File(char* source_file_name){
    char* data;

    FILE* source_file;
    long length_of_file;

    source_file = fopen(source_file_name , "rb");

    if(source_file == NULL){
        Print(L"In Get_Data_From_File\n");
        Print(L"Error : Read File Fail\n");
        return NULL;
    }

    length_of_file = Get_File_Length(source_file);

    data = malloc((length_of_file + 1) * sizeof(char*));

    fread(data , 1 , length_of_file , source_file);

    fclose(source_file);

    return data;
}

long Get_File_Length(FILE* source_file){
    if(source_file == NULL){
        Print(L"In Get_File_Length\n");
        Print(L"Error : Source File is NULL\n");
        return 0;
    }

    long length_of_file;

    fseek(source_file , 0 , SEEK_END);

    length_of_file = ftell(source_file);

    fseek(source_file , 0 , SEEK_SET);

    return length_of_file;
}

void Print_Data(char* data , long length_of_file){
    if(data == NULL){
        Print(L"In Print_Data\n");
        Print(L"Error : Data is NULL\n");
        return;
    }
    else if(length_of_file == -1){
        Print(L"In Print_Data\n");
        Print(L"Error : Length of File shorter than 0\n");
        return;
    }

    printf("%s\n" , data );

    /*
    char* current_data = data;

    while(length_of_file > 0){
        printf("%c" , *current_data);

        current_data++;
        length_of_file--;
    }
    */
}

char* Get_Description(cJSON* Class_Code_Table , UINTN BaseClass , UINTN SubClass , UINTN ProgrammingInterface){
    cJSON* base_class_table;
    cJSON* sub_class_table;
    cJSON* programming_interface_table;
    cJSON* description_table;

    UINTN length_of_base_class_table;
    UINTN length_of_sub_class_table;
    UINTN length_of_programming_interface_table;
    UINTN length_of_description_table;

    cJSON* current_sub_class_item;
    cJSON* current_programming_interface_item;

    //CHAR8* current_base_class;
    //CHAR8* current_sub_class;
    //CHAR8* current_programming_interface;
    char* current_description;

    char* temp_checking;
    UINTN temp_index;
    UINT8 isMatch;

    // Check Number of Base Class and Sub Class
    base_class_table = cJSON_GetObjectItem(Class_Code_Table , "Base Class Table");
    length_of_base_class_table = cJSON_GetArraySize(base_class_table);

    sub_class_table = cJSON_GetObjectItem(Class_Code_Table , "Sub-Class Table");
    length_of_sub_class_table = cJSON_GetArraySize(sub_class_table);

    if(length_of_base_class_table != length_of_sub_class_table){
        //Print(L"In Get_Description\n");
        //Print(L"Error : Number of Base Class and Sub Class Not Match\n");
        return NULL;
    }

    // Check input Base Class valid or not
    if(BaseClass > length_of_base_class_table){
        Print(L"In Get_Description\n");
        Print(L"Error : Input Base Class Over The Range\n");
        return NULL;
    }
    else if(BaseClass < 0){
        Print(L"In Get_Description\n");
        Print(L"Error : Input Base Class Under The Range\n");
        return NULL;
    }

    // Get certain Sub Class according to the input Base Class
    current_sub_class_item = cJSON_GetArrayItem(sub_class_table , (int)BaseClass);

    // Check Number of Sub Class & Programming Interface
    sub_class_table = cJSON_GetObjectItem(current_sub_class_item , "Sub-Class");
    length_of_sub_class_table = cJSON_GetArraySize(sub_class_table);

    programming_interface_table = cJSON_GetObjectItem(current_sub_class_item , "Programming Interface Table");
    length_of_programming_interface_table = cJSON_GetArraySize(programming_interface_table);

    if(length_of_sub_class_table != length_of_programming_interface_table){
        Print(L"In Get_Description\n");
        Print(L"Error : Number of Sub Class and Programming Interface Not Match\n");
        return NULL;
    }

    // Check Sub Class
    for(temp_index = 0 , isMatch = 0 ; temp_index < length_of_sub_class_table ; temp_index++){
        temp_checking = cJSON_GetArrayItem(sub_class_table , (int)temp_index)->valuestring;

        if(SubClass == strtoul(temp_checking , NULL , 16)){
            isMatch = 1;
            break;
        }
    }

    if(isMatch != 1){
        Print(L"In Get_Description\n");
        Print(L"Error : No Such Sub Class\n");
        return NULL;
    }

    // Get certain Programming Interface according to the input Sub Class
    current_programming_interface_item = cJSON_GetArrayItem(programming_interface_table , (int)temp_index);

    // Check Number of Programming Interface & Description
    programming_interface_table = cJSON_GetObjectItem(current_programming_interface_item , "Programming Interface");
    length_of_programming_interface_table = cJSON_GetArraySize(programming_interface_table);

    description_table = cJSON_GetObjectItem(current_programming_interface_item , "Description");
    length_of_description_table =  cJSON_GetArraySize(description_table);

    if(length_of_programming_interface_table != length_of_description_table){
        Print(L"In Get_Description\n");
        Print(L"Error : Number of Programming Interface and Description Not Match\n");
        return NULL;
    }

    // Check Programming Interface
    for(temp_index = 0 , isMatch = 0 ; temp_index < length_of_programming_interface_table ; temp_index++){
        temp_checking = cJSON_GetArrayItem(programming_interface_table , (int)temp_index)->valuestring;

        if(strcmp(temp_checking,"0xxx")){
            isMatch = 1;
            break;
        }

        if(ProgrammingInterface == strtoul(temp_checking , NULL , 16)){
            isMatch = 1;
            break;
        }
    }

    if(isMatch != 1){
        Print(L"In Get_Description\n");
        Print(L"Error : No Such Programming Interface\n");
        return NULL;
    }

    // Get target description
    current_description = (cJSON_GetArrayItem(description_table , (int)temp_index)->valuestring);

    return current_description;
}


// For testing
/*
EFI_STATUS
main (EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *SystemTable)
{
    // Get PCI Information Testing 
    //Print(L"20220627 - 0300\n");
    //UINTN* PCI_Information = Get_PCI_Information(SystemTable);
    //Print(L"Base Address : %x\n" , PCI_Information[0]);
    //Print(L"Bus Start    : %x\n" , PCI_Information[1]);
    //Print(L"Bus End      : %x\n" , PCI_Information[2]);
    
    // Scan all device Testing
    Print(L"Scan all device Testing\n");
    Scan_All_Device(SystemTable);

    // Read JSON Testing
    //Print(L"Reasd Class Code Table json Test\n");
    //Read_Class_Code_JSON();

    // Get_Description Testing
    //char* result;
    //cJSON* root = Read_Class_Code_JSON();
    //Print(L"Get Description Testing\n");
    //result = Get_Description(root , 0x02 , 0x03 , 0x00);
    //Print(L"Result : %a\n" , result);

    return 0;
}
*/