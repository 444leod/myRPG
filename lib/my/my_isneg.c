/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** CPool day 3 - Task04
*/
void my_putchar(char c);

int my_isneg(int n)
{
    if ( n < 0 ) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
