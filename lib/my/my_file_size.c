/*
** EPITECH PROJECT, 2023
** my_file_size.c
** File description:
** B-PSU-100-LIL-1-1-navy-nicolas.pechart
*/
#include <sys/stat.h>

int my_file_size(char *path)
{
    struct stat st;
    if (stat(path, &st) == -1 || S_ISDIR(st.st_mode))
        return -1;
    return st.st_size;
}
