#ifndef LIST_DIR
#define LIST_DIR

void list_dir()
{
    FILE * OUTPUT_FILE;
    char line[256];
    OUTPUT_FILE = fopen("dossier.txt", "w");
    int i = 0, j;
    // const char * dir = "dir /b /a-d";
    // system(dir);

    FILE *cmd=popen("dir /b /a-d", "r");
    char result[24]={0x0};
    while (fgets(result, sizeof(result), cmd) !=NULL)
        {
            fputs (result, OUTPUT_FILE);
            i++;
        }
    fprintf(OUTPUT_FILE, "%d", i); 
    fprintf(OUTPUT_FILE, "\n"); 
    fclose(OUTPUT_FILE);
    pclose(cmd);
}

#endif