/*
** EPITECH PROJECT, 2023
** garbage_collector
** File description:
** garbage_collector
*/

#include "garbage.h"
int my_error(char *);

void *my_malloc(size_t size)
{
    void *variable = malloc(size);
    g_llist_t *llist = get_llist();

    if (variable == NULL) {
        my_free_all();
        return NULL;
    }
    *llist = g_insert_end(variable, *llist);
    if (*llist == NULL) {
        my_free_all();
        return NULL;
    }
    return variable;
}

void my_free(void *pointer)
{
    g_llist_t *llist = get_llist();
    g_llist_t temp;

    if ((*llist)->data == pointer) {
        *llist = g_delete_begin(*llist);
        return;
    }
    temp = (*llist)->next;
    while (temp != *llist) {
        if (temp->data == pointer) {
            temp = g_delete_begin(temp);
            return;
        }
        temp = temp->next;
    };
    free(pointer);
}

void my_free_all(void)
{
    g_llist_t *llist = get_llist();

    while (*llist)
        *llist = g_delete_begin(*llist);
}

void *force_malloc(size_t size)
{
    void *variable = malloc(size);

    if (variable == NULL) {
        my_free_all();
        return NULL;
    }
    return variable;
}

void force_free(void *pointer)
{
    free(pointer);
}
