#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void instructions();
void read_fname();
bool check_vbs_extension();
bool file_exists();
unsigned int get_file_size();
void get_file_content();
void create_exe_file();
void build_temp_file();
void build_content();
unsigned int get_lines();
unsigned int get_quotes();
void compileTmp();
void deleteTmp();
void dbg();

#endif /* UTILS_H */