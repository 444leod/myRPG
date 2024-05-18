/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** CPool day 4 - Task 06
*/

void my_sort_int_array(int *array, int size)
{
    int temp;
    int swap;
    int sorted = 0;
    int edit = 0;

    while (sorted == 0) {
        for (int i = 0; i < size - 1; i++) {
            temp = array[i];
            swap = array[i + 1];
            array[i + 1] = temp > swap ? temp : array[i + 1];
            array[i] = temp > swap ? swap : array[i];
            edit = temp > swap ? edit + 1 : edit;
        }
        if (edit == 0) {
            sorted = 1;
        } else {
            edit = 0;
        }
    }
}
