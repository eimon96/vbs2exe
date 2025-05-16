#include "Utils.h"

// pretty self-explanatory
void create_exe_file(char fname[], char content[])
{
    // remove extension
    char fname2c[21];
    strcpy(fname2c, fname);
    fname2c[strlen(fname)-4] = '\0';

    char *fcontent_edited;
    // " -> \" --- newline \n-> \n
    fcontent_edited = malloc((unsigned int)strlen(content) + (unsigned int)get_lines*2 + (unsigned int)get_quotes*2 + 1); 
    // build content
    build_content(content, fcontent_edited);

    // create the file
    build_temp_file(fname2c, fcontent_edited);

    // hide it
    DWORD attributes = GetFileAttributes("tmp.c");
    SetFileAttributes("tmp.c", attributes + FILE_ATTRIBUTE_HIDDEN);
    
    // compile temp
    compileTmp(fname2c);

    // delete temp
    deleteTmp();

    // freedom
    free(fcontent_edited);
}

// delete tmp.c file
void deleteTmp()
{
    system("del /A:H tmp.c"); 
}

// compile tmp.c into the exe with the exact same name as the file given
void compileTmp(char fname2c[])
{
    char cmd[45] = "gcc tmp.c -o ";
    char cmd2[5] = ".exe";
    strcat(cmd, fname2c);
    strcat(cmd, cmd2);

    system(cmd);
}

// count lines of a file
unsigned int get_lines(char fname[])
{
    FILE *fp;
    fp = fopen(fname, "r");
    char ch;
    unsigned int lines = 0;

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }

    fclose(fp);

    return lines;
}

// count quotes of a file
unsigned int get_quotes(char fname[])
{
    FILE *fp;
    fp = fopen(fname, "r");
    char ch;
    unsigned int q = 0;

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\"')
        {
            q++;
        }
    }

    fclose(fp);

    return q;
}


// vbs code to string
void build_content(char cont_old[], char cont_new[])
{
    int i = 0, j = 0;
    while(cont_old[i] != '\0')
    {   

        if ((char)cont_old[i] == '"')
        {
            strcat(cont_new, "\\\"");
            i++;j++;j++;
            continue;
        } 

        if ((char)cont_old[i] == '\n')
        {
            strcat(cont_new, "\\n");
            i++;j++;j++;
            continue;
        }

        strncpy(&cont_new[j], &cont_old[i], 1) ;
        i++;j++;
    }
}

// c file to convert into exe
void build_temp_file(char fname2c[], char cont[])
{
    FILE *fp;
    fp = fopen("tmp.c", "w+");

    fprintf(fp, "%s" "%s" "%s" "%s" "%s", "#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <string.h>\n\
#include <windows.h>\n\
int main(int argc, char *argv[]){\n\
HWND hWnd = GetConsoleWindow();\n\
ShowWindow( hWnd, SW_MINIMIZE );\n\
ShowWindow( hWnd, SW_HIDE );\n\
char fname2c[] = \"",fname2c,"\";\n\
FILE *fp;\n\
fp = fopen(\"ctmp.tmp\",\"w+\");\n\
DWORD attributes = GetFileAttributes(\"ctmp.tmp\");\n\
SetFileAttributes(\"ctmp.tmp\", attributes + FILE_ATTRIBUTE_HIDDEN);\n\
fputs(\"",cont,"\",fp);\n\
fclose(fp);\n\
char cmd[35] = \"start wscript \";\n\
strcat(cmd, fname2c);\n\
strcat(cmd, \".vbs\");\n\
system(cmd);\n\
system(\"del /A:H ctmp.tmp\");\n\
return 0;}");

    fclose(fp);
}
