#include "Utils.h"

int main(int argc, char *argv[])
{
    char fname[21];     // includes the \0 
    char *fcontent;
    unsigned int flen;

    if (argc != 2)
    {
        instructions();
        exit(1);
    }

    // check argv[1l length
    if (strlen(argv[1]) > 20)
    {
        printf("Name must be 20 characters long max.");
        exit(4);
    }

    // get file name
    strcpy(fname, argv[1]);

    // add vbs extension if necessary
    if (!check_vbs_extension(fname))
    {
        strcat(fname, ".vbs");
    }

    // check file existence
    if (!file_exists(fname))
    {
        printf("File not found.");
        exit(2);
    }

    // count chars of file and malloc 
    flen = get_file_size(fname);
    if (flen == 0)
    {
        printf("File is empty.");
        exit(3);
    }
            
    fcontent = (char *) malloc((flen + 1)* (sizeof(char *)));
    // content of the file is into the string now
    get_file_content(fname, fcontent);

    // create the exe file
    create_exe_file(fname, fcontent);

        // freedom
    free(fcontent);

    return 0;
}

// a lame debugging technic whatsoever
// but yep
void dbg(char strr[])
{
    printf("%s", strr);
}