#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h> 
#include <conio.h>
#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


#define BLOCK_SIZE 256
#define DELIMITER "|"
// Record structure
typedef struct {
    int key;
    char First_Name[20];
    char Last_Name[20];
    char Description[100];
    bool Eraser;
} Record;

// Block structure
typedef struct {
    char data[BLOCK_SIZE];
  
    int Byte_Used;
    int Number_of_records;
} Block;

// Header structure
typedef struct {
    int Number_of_Blocks;
    int Number_of_Records;
} Header;

// File structure 
typedef struct {
    FILE *file;
    Header header;
} File;



void welcome (){
    system("cls");
    printf("\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("     %c .88d88b.  .d88888b    dP   %c     KAHLOUCHE YOUCEF   %c\n",186,186,186);
    printf("     %c 88.  `88  88.    \"'        %c    boubechal kawther   %c\n",186,186,186);
    printf("     %c 888d888;  ~Y88888b.   88   %c     GROUPE  : 02       %c\n",186,186,186);
    printf("     %c 88.             `8b   88   %c     TP N:2             %c\n",186,186,186);
    printf("     %c  Y88888    Y88888P    dP   %c     EX14               %c\n",186,186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("     %c   HIGHER   SCHOOL   OF   COMPUTER   SIENCE          %c\n",186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("        THANKS FOR CHOSING OUR APPLICATION! ");
    printf(" \n\n        press ENTER to continue ! ");
    getchar();

}
//-------------------------------------------------------------------------------------------------------------------------------------------------

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    setColor(7);
}

void printCentered(const char *text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int textLength = strlen(text);
    int space = (consoleWidth - textLength) / 2;

    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}

void display_TnOVS_Menu(int choice) {
    system("cls");
    printf("\033[32m");
    printCentered(" ____________________________________________ ");
    printCentered("|                                            |");
    printCentered("|                    MENU                    |");
    printCentered("|____________________________________________|");
    printf("\033[0m");
    printf("\n\n");
    const char *options[5] = {
        "1: Give an initial load",
        "2: Fradgement File",
        "9: Display the Whole File_tnovs",
        "10: Back",
        "0: Exit"
        
    };

    for (int i = 0; i < 5; i++) {
        if (i == choice) {
            setColor(4); // Yellow for highlighted option
            printCentered(options[i]);
            resetColor();
        } else {
            printCentered(options[i]);
        }
    }
}
void display_TOVS_Menu(int choice) {
    system("cls");
    printf("\033[32m");
    printCentered(" ____________________________________________ ");
    printCentered("|                                            |");
    printCentered("|                    MENU                    |");
    printCentered("|____________________________________________|");
    printf("\033[0m");
    printf("\n\n");
       const char *options[5] = {
        "1: Give an initial load",
        "2: Fradgement File",
        "9: Display the Whole File_tnovs",
        "10: Back",
        "0: Exit"
        
    };

    for (int i = 0; i < 5; i++) {
        if (i == choice) {
            setColor(4); // Yellow for highlighted option
            printCentered(options[i]);
            resetColor();
        } else {
            printCentered(options[i]);
        }
    }
}
void display_Main_Menu (int choice) {
    printf("\033[31m");
    printCentered(" ____________________________________________ ");
    printCentered("|                                            |");
    printCentered("|               MAIN MENU                    |");
    printCentered("|____________________________________________|");
    printf("\033[0m");
    printf("\n\n");
    const char *options[3] = {
        "1: TOVS",
        "2: TNOVS",
        "0: Exit"
    };

    for (int i = 0; i < 3; i++) {
        if (i == choice) {
            setColor(6); // Yellow for highlighted option
            printCentered(options[i]);
            resetColor();
        } else {
            printCentered(options[i]);
        }
    }
}

void Before_tnovs(char *File_tnovsname) {
    printf("\033[31m");
    printCentered("______________________________________________________________");
    printCentered("|                                                             |");
    printCentered("|                                                             |");
    printCentered("|        BEFORE WE START YOU SHOULD ENTER THE File_tnovs NAME       |");
    printCentered("|                                                             |");
    printCentered("|                                                             |");
    printCentered("|_____________________________________________________________|\n");
    printf("\033[0m");

    printf("\033[3A\033[50C");  

    scanf("%19s", File_tnovsname);  

    printf("\n\n\n");
}
void Before_tovs(char *File_tovsname) {
    printf("\033[31m");
    printCentered("______________________________________________________________");
    printCentered("|                                                             |");
    printCentered("|                                                             |");
    printCentered("|        BEFORE WE START YOU SHOULD ENTER THE File_tovs NAME        |");
    printCentered("|                                                             |");
    printCentered("|                                                             |");
    printCentered("|_____________________________________________________________|\n");
    printf("\033[0m");

    printf("\033[3A\033[50C");  
  
    scanf("%19s", File_tovsname);  

    printf("\n\n\n");
}


//     ABSTRACT MACHIN FUNCTIONS : 

Block *AllocBlock(File *file) {
    Block *block = (Block*)malloc(sizeof(Block));
    if (!block) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    memset(block->data, 0, BLOCK_SIZE);
    block->Number_of_records = 0;
    block->Byte_Used = 0;
    file->header.Number_of_Blocks++;
    return block;
}


int readBlock(FILE *file, int blockNumber, Block *block) {
    fseek(file, sizeof(Header) + blockNumber * sizeof(Block), SEEK_SET);
    return fread(block, sizeof(Block), 1, file);
}


void writeBlock(FILE *file, int blockNumber, Block *block) {
    fseek(file, sizeof(Header) + blockNumber * sizeof(Block), SEEK_SET);
    fwrite(block, sizeof(Block), 1, file);
}


void setHeader(FILE *file, Header *header) {
    fseek(file, 0, SEEK_SET);
    fwrite(header, sizeof(Header), 1, file);
}


Header getHeader(FILE *file) {
    Header header;
    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(Header), 1, file);
    return header;
}



void Record_to_String(Record rec, char *s) {
    sprintf(s, "%d,%s,%s,%s,%d%s",
            rec.key, rec.First_Name, rec.Last_Name, rec.Description,
            rec.Eraser ? 1 : 0, DELIMITER);
   
}



void String_to_Record(const char *s, Record *rec) {
    sscanf(s, "%d,%20[^,],%20[^,],%100[^,],%d", 
           &rec->key, rec->First_Name, rec->Last_Name,
           rec->Description, (int*)&rec->Eraser);
}




File *Open(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file && mode[0] == 'r') {
        file = fopen(filename, "wb+");
        if (file) {
            Header header = {0, 0};
            setHeader(file, &header);
            printCentered("File Created Successfully");
        }
        if(!file){
            printCentered("File was not created");
        }
    }
    File *FIle = (File*)malloc(sizeof(File));
    FIle->file = file;
    FIle->header = getHeader(file);
    printCentered("File is open");
    return FIle;
}


void Close(File *file) {
    setHeader(file->file, &file->header);  
    if (file->file) fclose(file->file);
    free(file);
}


int countRecordsInBlock(const char *data) {
    int count = 0;
    char tempData[BLOCK_SIZE];
    strcpy(tempData, data);

    char *token = strtok(tempData, DELIMITER);
    while (token != NULL) {
        count++;
        token = strtok(NULL, DELIMITER);
    }
    return count;
}


//   TnOVS functions : 
void insertRecord_TnOVS(File *file, Record rec) {
    char recordStr[BLOCK_SIZE * 2]; // Buffer for serialized record.
    Record_to_String(rec, recordStr); // Convert record to string.
    int recordLen = strlen(recordStr); // Length of the serialized record.

    if (recordLen > BLOCK_SIZE) {
        printf("Error: Record size exceeds block size.\n");
        return;
    }

    Block block;
    bool isDuplicate = false;

    // Check for duplicate records by scanning all blocks.
    for (int blockNumber = 0; blockNumber < file->header.Number_of_Blocks; blockNumber++) {
        readBlock(file->file, blockNumber, &block);

        char *token = strtok(block.data, DELIMITER);
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord);

            // If a matching key is found, mark as duplicate.
            if (!existingRecord.Eraser && existingRecord.key == rec.key) {
                isDuplicate = true;
                break;
            }

            token = strtok(NULL, DELIMITER);
        }
        if (isDuplicate) break;
    }

    if (isDuplicate) {
        printf("Duplicate record with key %d found. Insertion skipped.\n", rec.key);
        return;
    }

    // Find the block to insert the record, or create a new one.
    int blockNumber = file->header.Number_of_Blocks > 0 ? file->header.Number_of_Blocks - 1 : 0;
    readBlock(file->file, blockNumber, &block);

    // If the block is full, prepare a new block for the record.
    if (block.Byte_Used >= BLOCK_SIZE || file->header.Number_of_Blocks == 0) {
        blockNumber = file->header.Number_of_Blocks;
        memset(&block, 0, sizeof(Block));
    }

    int remainingBytes = recordLen;
    char *recordPointer = recordStr;

    // Insert the record across blocks if necessary.
    while (remainingBytes > 0) {
        int availableSpace = BLOCK_SIZE - block.Byte_Used;

        if (remainingBytes > availableSpace) {
            // Fill the current block to its capacity.
            strncat(block.data, recordPointer, availableSpace);
            block.Byte_Used += availableSpace;
            block.Number_of_records++;
            writeBlock(file->file, blockNumber++, &block);

            // Move to the next block and reset it.
            memset(&block, 0, sizeof(Block));
            recordPointer += availableSpace;
            remainingBytes -= availableSpace;
        } else {
            // Insert the remaining part of the record.
            strcat(block.data, recordPointer);
            block.Byte_Used += remainingBytes;
            block.Number_of_records++;
            remainingBytes = 0;
        }
    }

    writeBlock(file->file, blockNumber, &block);
    printf ("Record with key %d is inserted \n",rec.key);
    // Update header metadata.
    file->header.Number_of_Blocks = blockNumber + 1;
    file->header.Number_of_Records++;
    setHeader(file->file, &file->header);
}


void initialLoad_TnOVS(File *file, int rate) {

    for (int i = 1; i <= rate; i++) {
        Record rec;
        rec.key = i;
        snprintf(rec.First_Name, sizeof(rec.First_Name), "First%d", i);
        snprintf(rec.Last_Name, sizeof(rec.Last_Name), "Last%d", i);
        snprintf(rec.Description, sizeof(rec.Description), "Record number %d", i);
        rec.Eraser = false;

        insertRecord_TnOVS(file, rec);
    }
    printf("Initial load is completed with %d records.\n", rate);
}


void Display_Header_TnOVS(File *file) {
    printf("The number of blocks here is  : %d \n", file->header.Number_of_Blocks);
    printf("The number of records here is  : %d \n", file->header.Number_of_Records);
}

void display_File_TnOVS(File *file) {
    Display_Header_TnOVS(file);
    Block block;
    for (int i = 0; i < file->header.Number_of_Blocks; i++) {
        readBlock(file->file, i, &block);
        char *token = strtok(block.data, DELIMITER);
        
        printf("Block %d:\n", i);
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord);

            if (!existingRecord.Eraser) {
                printf("  %s\n", token);
            }
            token = strtok(NULL, DELIMITER);
        }
    }
}

bool search_TnOVS(File *file, int key) {
    Block block;
    bool found = 0; // Flag to track if the record was found

    // Iterate through all blocks to search for the record
    for (int i = 0; i < file->header.Number_of_Blocks; i++) {
        readBlock(file->file, i, &block); // Read the block from the file
        char *token = strtok(block.data, DELIMITER); // Tokenize the block data

        int pos = 0; // Position counter within the block
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord); // Convert the token into a record

            // If the record is found and not erased, display its information
            if (!existingRecord.Eraser && existingRecord.key == key) {
                found = 1;
                return 1 ;
            }

            token = strtok(NULL, DELIMITER); // Move to the next token
            pos++;
        }
    }

    // If the record was not found, display a message
    if (!found) {
       return 0 ;
    }
}
bool getRecord_TnOVS(File *file, int key, Record *record) {
    Block block;

    // Iterate through all blocks in the file
    for (int blockNumber = 0; blockNumber < file->header.Number_of_Blocks; blockNumber++) {
        readBlock(file->file, blockNumber, &block);

        // Create a temporary copy of block data for tokenization
        char blockDataCopy[BLOCK_SIZE];
        strncpy(blockDataCopy, block.data, BLOCK_SIZE);
        blockDataCopy[BLOCK_SIZE - 1] = '\0'; // Ensure null termination

        char *token = strtok(blockDataCopy, DELIMITER);

        // Tokenize the block data to retrieve records
        while (token != NULL) {
            Record tempRecord;
            String_to_Record(token, &tempRecord);

            // Check if the record matches the key and is not marked as erased
            if (!tempRecord.Eraser && tempRecord.key == key) {
                *record = tempRecord; // Copy the found record to the output parameter
                return true;
            }

            token = strtok(NULL, DELIMITER);
        }
    }

    // Record not found
    return false;
}

void FragmentFile_TnOVS(File *file, File *F1, File *F2, File *F3, int C1, int C2) {
    Block block;
    Record rec;

    // Process records with keys less than C1
    for (int i = 0; i < C1; i++) {
        rec.key = i;
        if (search_TnOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TnOVS(file, rec.key, &rec)) {
                insertRecord_TnOVS(F1, rec);
            }
        }
    }

    // Process records with keys between C1 and C2
    for (int i = C1; i < C2; i++) {
        rec.key = i;
        if (search_TnOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TnOVS(file, rec.key, &rec)) {
                insertRecord_TnOVS(F2, rec);
            }
        }
    }

    // Process records with keys greater than or equal to C2
    for (int i = C2; i <= file->header.Number_of_Records; i++) {
        rec.key = i;
        if (search_TnOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TnOVS(file, rec.key, &rec)) {
                insertRecord_TnOVS(F3, rec);
            }
        }
    }
}


void TnOVS(){
    int key   ;
    int choice = 0; 
    char filename[24];  
    Before_tnovs(filename);

    strcat(filename, ".tnovs");

    File *tnovsFile = Open(filename, "rb+");
    File *F1 = Open("F1.tnovs", "rb+");
    File *F2 = Open("F2.tnovs", "rb+");
    File *F3 = Open("F3.tnovs", "rb+");
    
    while (1) {
        display_TnOVS_Menu(choice);

        key = getch();

        if (key == 224) {
            key = getch();
            switch (key) {
                case 72: 
                    choice = (choice - 1 + 5) % 5; 
                    break;
                case 80: 
                    choice = (choice + 1) % 5; 
                    break;
            }
        } else if (key == 13) { 


            switch (choice) {
                                    
                case 0:
                    system("cls");
                    int rate;
                    printCentered("Enter the number of records that you want to insert as an initial load : \n");
                    printf("\033[1A\033[63C"); 
                    scanf("%d" , &rate);
                    initialLoad_TnOVS(tnovsFile ,rate);
                    break;
        
                case 1:
                    int key1 , key2 ;
                    system("cls");
                    printCentered("Give the first key : \n");
                    scanf("%d",&key1);
                    printCentered("Give the second key : \n");
                    scanf("%d",&key2);
                    printf("fragementimng \n");
                    FragmentFile_TnOVS(tnovsFile , F1 ,F2,F3 ,key1 ,key2 );
                    printf("fragement done\n");
                    break;
                case 2:
                    system("cls");
                    printf("main\n");
                    display_File_TnOVS(tnovsFile);
                    printf("F1\n");
                    display_File_TnOVS(F1);
                    printf("F2\n");
                    display_File_TnOVS(F2);
                    printf("F3\n");
                    display_File_TnOVS(F3);
                    break;
                case 10:
                    exit(0);
                    break ;
                default:
                    printf("Invalid option\n");
                    break;
            }
            printf("Press any key to continue...\n");
            getch(); 
        }
    }

}

//   TOVS functions : 
void insertRecord_TOVS(File *file, Record rec) {
    char recordStr[BLOCK_SIZE * 2]; // Buffer for serialized record.
    Record_to_String(rec, recordStr); // Convert record to string.
    int recordLen = strlen(recordStr); // Length of the serialized record.

    if (recordLen > BLOCK_SIZE) {
        printf("Error: Record size exceeds block size.\n");
        return;
    }

    Block block;
    bool isDuplicate = false;

    // Check for duplicate records by scanning all blocks.
    for (int blockNumber = 0; blockNumber < file->header.Number_of_Blocks; blockNumber++) {
        readBlock(file->file, blockNumber, &block);

        char *token = strtok(block.data, DELIMITER);
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord);

            // If a matching key is found, mark as duplicate.
            if (!existingRecord.Eraser && existingRecord.key == rec.key) {
                isDuplicate = true;
                break;
            }

            token = strtok(NULL, DELIMITER);
        }
        if (isDuplicate) break;
    }

    if (isDuplicate) {
        printf("Duplicate record with key %d found. Insertion skipped.\n", rec.key);
        return;
    }

    // Find the block to insert the record, or create a new one.
    int blockNumber = file->header.Number_of_Blocks > 0 ? file->header.Number_of_Blocks - 1 : 0;
    readBlock(file->file, blockNumber, &block);

    // If the block is full, prepare a new block for the record.
    if (block.Byte_Used >= BLOCK_SIZE || file->header.Number_of_Blocks == 0) {
        blockNumber = file->header.Number_of_Blocks;
        memset(&block, 0, sizeof(Block));
    }

    int remainingBytes = recordLen;
    char *recordPointer = recordStr;

    // Insert the record across blocks if necessary.
    while (remainingBytes > 0) {
        int availableSpace = BLOCK_SIZE - block.Byte_Used;

        if (remainingBytes > availableSpace) {
            // Fill the current block to its capacity.
            strncat(block.data, recordPointer, availableSpace);
            block.Byte_Used += availableSpace;
            block.Number_of_records++;
            writeBlock(file->file, blockNumber++, &block);

            // Move to the next block and reset it.
            memset(&block, 0, sizeof(Block));
            recordPointer += availableSpace;
            remainingBytes -= availableSpace;
        } else {
            // Insert the remaining part of the record.
            strcat(block.data, recordPointer);
            block.Byte_Used += remainingBytes;
            block.Number_of_records++;
            remainingBytes = 0;
        }
    }

    writeBlock(file->file, blockNumber, &block);
    printf ("Record with key %d is inserted \n",rec.key);
    // Update header metadata.
    file->header.Number_of_Blocks = blockNumber + 1;
    file->header.Number_of_Records++;
    setHeader(file->file, &file->header);
}


void initialLoad_TOVS(File *file, int rate) {

    for (int i = 1; i <= rate; i++) {
        Record rec;
        rec.key = i;
        snprintf(rec.First_Name, sizeof(rec.First_Name), "First%d", i);
        snprintf(rec.Last_Name, sizeof(rec.Last_Name), "Last%d", i);
        snprintf(rec.Description, sizeof(rec.Description), "Record number %d", i);
        rec.Eraser = false;

        insertRecord_TOVS(file, rec);
    }
    printf("Initial load is completed with %d records.\n", rate);
}


void Display_Header_TOVS(File *file) {
    printf("The number of blocks here is  : %d \n", file->header.Number_of_Blocks);
    printf("The number of records here is  : %d \n", file->header.Number_of_Records);
}

void display_File_TOVS(File *file) {
    Display_Header_TOVS(file);
    Block block;
    for (int i = 0; i < file->header.Number_of_Blocks; i++) {
        readBlock(file->file, i, &block);
        char *token = strtok(block.data, DELIMITER);
        
        printf("Block %d:\n", i);
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord);

            if (!existingRecord.Eraser) {
                printf("  %s\n", token);
            }
            token = strtok(NULL, DELIMITER);
        }
    }
}

bool search_TOVS(File *file, int key) {
    Block block;
    bool found = 0; // Flag to track if the record was found

    // Iterate through all blocks to search for the record
    for (int i = 0; i < file->header.Number_of_Blocks; i++) {
        readBlock(file->file, i, &block); // Read the block from the file
        char *token = strtok(block.data, DELIMITER); // Tokenize the block data

        int pos = 0; // Position counter within the block
        while (token != NULL) {
            Record existingRecord;
            String_to_Record(token, &existingRecord); // Convert the token into a record

            // If the record is found and not erased, display its information
            if (!existingRecord.Eraser && existingRecord.key == key) {
                found = 1;
                return 1 ;
            }

            token = strtok(NULL, DELIMITER); // Move to the next token
            pos++;
        }
    }

    // If the record was not found, display a message
    if (!found) {
       return 0 ;
    }
}
bool getRecord_TOVS(File *file, int key, Record *record) {
    Block block;

    // Iterate through all blocks in the file
    for (int blockNumber = 0; blockNumber < file->header.Number_of_Blocks; blockNumber++) {
        readBlock(file->file, blockNumber, &block);

        // Create a temporary copy of block data for tokenization
        char blockDataCopy[BLOCK_SIZE];
        strncpy(blockDataCopy, block.data, BLOCK_SIZE);
        blockDataCopy[BLOCK_SIZE - 1] = '\0'; // Ensure null termination

        char *token = strtok(blockDataCopy, DELIMITER);

        // Tokenize the block data to retrieve records
        while (token != NULL) {
            Record tempRecord;
            String_to_Record(token, &tempRecord);

            // Check if the record matches the key and is not marked as erased
            if (!tempRecord.Eraser && tempRecord.key == key) {
                *record = tempRecord; // Copy the found record to the output parameter
                return true;
            }

            token = strtok(NULL, DELIMITER);
        }
    }

    // Record not found
    return false;
}

void FragmentFile_TOVS(File *file, File *F1, File *F2, File *F3, int C1, int C2) {
    Block block;
    Record rec;

    // Process records with keys less than C1
    for (int i = 0; i < C1; i++) {
        rec.key = i;
        if (search_TOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TOVS(file, rec.key, &rec)) {
                insertRecord_TOVS(F1, rec);
            }
        }
    }

    // Process records with keys between C1 and C2
    for (int i = C1; i < C2; i++) {
        rec.key = i;
        if (search_TOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TOVS(file, rec.key, &rec)) {
                insertRecord_TOVS(F2, rec);
            }
        }
    }

    // Process records with keys greater than or equal to C2
    for (int i = C2; i <= file->header.Number_of_Records; i++) {
        rec.key = i;
        if (search_TOVS(file, rec.key)) {
            // Retrieve the actual record
            if (getRecord_TOVS(file, rec.key, &rec)) {
                insertRecord_TOVS(F3, rec);
            }
        }
    }
}


void TOVS(){
    int key   ;
    int choice = 0; 
    char filename[24];  
    Before_tovs(filename);

    strcat(filename, ".tovs");

    File *tovsFile = Open(filename, "rb+");
    File *F1 = Open("F1.tovs", "rb+");
    File *F2 = Open("F2.tovs", "rb+");
    File *F3 = Open("F3.tovs", "rb+");
    
    while (1) {
        display_TOVS_Menu(choice);

        key = getch();

        if (key == 224) {
            key = getch();
            switch (key) {
                case 72: 
                    choice = (choice - 1 + 5) % 5; 
                    break;
                case 80: 
                    choice = (choice + 1) % 5; 
                    break;
            }
        } else if (key == 13) { 


            switch (choice) {
                                    
                case 0:
                    system("cls");
                    int rate;
                    printCentered("Enter the number of records that you want to insert as an initial load : \n");
                    printf("\033[1A\033[63C"); 
                    scanf("%d" , &rate);
                    initialLoad_TOVS(tovsFile ,rate);
                    break;
        
                case 1:
                    int key1 , key2 ;
                    system("cls");
                    printCentered("Give the first key : \n");
                    scanf("%d",&key1);
                    printCentered("Give the second key : \n");
                    scanf("%d",&key2);
                    printf("fragementimng \n");
                    FragmentFile_TOVS(tovsFile , F1 ,F2,F3 ,key1 ,key2 );
                    printf("fragement done\n");
                    break;
                case 2:
                    system("cls");
                    printf("main\n");
                    display_File_TOVS(tovsFile);
                    printf("F1\n");
                    display_File_TOVS(F1);
                    printf("F2\n");
                    display_File_TOVS(F2);
                    printf("F3\n");
                    display_File_TOVS(F3);
                    break;
                case 10:
                    exit(0);
                    break ;
                default:
                    printf("Invalid option\n");
                    break;
            }
            printf("Press any key to continue...\n");
            getch(); 
        }
    }

}



int main() {
    int choice = 0; // Variable to keep track of the current menu option (initially 0)
    int key;        // Variable to capture the key press from the user
    
    // Call the welcome function to display any introductory messages
    welcome();
    
    system("cls"); // Clear the console screen
    
    // Infinite loop for the main menu, allowing continuous interaction with the program
    while (1) {
        // Display the main menu with the current selection highlighted
        display_Main_Menu(choice);

        // Capture the user's key press
        key = getch();

        // Check if the key is a special key (arrow keys)
        if (key == 224) {
            key = getch(); // Capture the second part of the special key
            switch (key) {
                case 72: // Up arrow key
                    choice = (choice - 1 + 3) % 3; // Move selection up in the menu, wrap around
                    break;
                case 80: // Down arrow key
                    choice = (choice + 1) % 3; // Move selection down in the menu, wrap around
                    break;
            }
        } 
        // Check if the Enter key was pressed
        else if (key == 13) {
            switch (choice) {
                case 0: // Option 0: TOVS functionality
                    system("cls");  // Clear the screen
                    TOVS();         // Call the TOVS function
                    break;
                case 1: // Option 1: TnOVS functionality
                    system("cls");  // Clear the screen
                    TnOVS();         // Call the TnOVS function
                    break;
                case 2: // Option 3: Exit the program
                    exit(0);         // Exit the program
                    break;
                default:
                    printf("Invalid option\n"); // In case of an invalid menu option
                    break;
            }
            // Prompt the user to press any key to continue after an action
            printf("Press any key to continue...\n");
            getch();  // Wait for the user to press a key
        }
    }
}

