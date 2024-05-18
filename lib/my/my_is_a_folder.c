/*
** EPITECH PROJECT, 2023
** my_is_a_folder.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/
#include <sys/stat.h>

int my_is_a_folder(char *path)
{
    struct stat sb;
    if (stat(path, &sb) == -1) {
        return 0;
    }
    return S_ISDIR(sb.st_mode);
}
