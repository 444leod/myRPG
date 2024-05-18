/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Auto generated file
*/

#ifndef MY
    #define MY
    int my_char_contains(const char chr, const char *cmp);
    int my_char_isalpha(char c);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_file_exists(char *path);
    int my_file_size(char *path);
    int my_find_prime_sup(int nb);
    void my_free_array(char **array);
    int my_getnbr(char const *str);
    int my_get_nbr_len(int nbr);
    char *my_int_to_bin(int nb);
    char *my_int_to_str(int nbr);
    int my_is_a_folder(char *path);
    int my_isneg(int n);
    int my_is_prime(int nb);
    void my_memset(char *str, int len);
    int my_pow(int nbr, int x);
    void my_putchar(char c);
    int my_put_error(char *str);
    int my_put_nbr(int nbr);
    int my_put_str_array(char **array);
    int my_putstr(char const *str);
    char *my_read_file(char *path, int size);
    char *my_revstr(char *str);
    int my_showmem(char const *str, int size);
    void my_sort_int_array(int *array, int size);
    int my_sort_word_array(char **tab);
    int my_str_array_len(char *array);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_str_contains(const char *str, const char *cmp);
    char *my_strcpy(char *dest, char *src);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    int my_strlen(char *str);
    char *my_strlowcase(char *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char **my_str_to_word_array(char *str, char *separator);
    char *my_strupcase(char *str);
    void my_swap(int *a, int * b);
    char *my_trim(char *str, char *separator);
    char *supercat(int nbr, ...);

#endif
