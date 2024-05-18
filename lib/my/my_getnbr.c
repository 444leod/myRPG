/*
** EPITECH PROJECT, 2022
** my_todo
** File description:
** why
*/

int my_getnbr(char const *str)
{
    long result = 0;
    int x = 0, minus = 0, found = 0, exit = 0;

    while (str[x] != '\0' && exit == 0) {
        if (str[x] >= 48 && str[x] <= 57) {
            result = result * 10 + (str[x] - 48);
            found = 1;
        } else {
            exit = found == 1 ? 1 : 0;
        }
        if (str[x] == '-') {
            minus = (minus + 1) % 2;
        }
        x++;
    }
    if (result > 2147483647) {
        return 0;
    }
    return minus ? (int)-result : (int)result;
}
