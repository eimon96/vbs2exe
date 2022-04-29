#include <stdio.h>

// intro and instructions
void instructions()
{
    printf("\n--------------------");
    printf("\neimon (c) April 2022");
    printf("\n--------------------\n\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Usage vbs2exe <filename> \n\
Where <filename> the name of the VBS file you would like to convert into the EXE. \n\
The file extension is optional. Name must be 20 characters long max.\n\
Make sure the VBS file is in the same directorry as this one. \n\
The output EXE file will be placed into this directory with the exact same name as the original.\n\
Attention. wscripts only.");
    printf("\n------------------------------------------------------------------------------------------------------\n");
}
