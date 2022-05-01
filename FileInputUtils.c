#include "Utils.h"

// check if vbs extension exists
// if exists return true, otherwise false
bool check_vbs_extension(char fname[])
{
    if (strstr(fname, ".vbs") != NULL) 
    {
        return true;
    }
    return false;
}

// check if file exists
// if exists return true, otherwise false
bool file_exists(char fname[])
{
    FILE *fp;
    if (fopen(fname, "r") != NULL)
    {
        return true;
    }
    return false;
}

// count chars of file
unsigned int get_file_size(char fname[])
{
    FILE *fp;
    fp = fopen(fname,"r");

    unsigned int len;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);

    fclose(fp);

    return len;
}

// open, read file, save content into string variable
void get_file_content(char fname[],char content[])
{
    FILE *fp;
    fp = fopen(fname, "r");
    
    int i = 0;
    while(!feof(fp))
    {   
        content[i] = (char) fgetc(fp);
        i++;
    }
    content[i] ='\0';

    fclose(fp);
}