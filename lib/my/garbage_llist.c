/*
** EPITECH PROJECT, 2023
** garbage_collector
** File description:
** garbage_llist
*/

#include "garbage.h"

g_llist_t *get_llist(void)
{
    static g_llist_t llist = NULL;

    return &llist;
}

g_llist_t g_create(void *data)
{
    g_llist_t new_node = malloc(sizeof(garbage_t));

    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

g_llist_t g_insert_end(void *data, g_llist_t list)
{
    g_llist_t new_node = g_create(data);

    if (new_node == NULL)
        return NULL;
    if (list == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        list = new_node;
        return list;
    }
    list->prev->next = new_node;
    new_node->prev = list->prev;
    new_node->next = list;
    list->prev = new_node;
    return list;
}

g_llist_t g_delete_begin(g_llist_t list)
{
    g_llist_t temp;

    if (list == NULL)
        return list;
    else if (list->next == list) {
        free(list->data);
        free(list);
        list = NULL;
        return list;
    }
    temp = list;
    list->prev->next = list->next;
    list->next->prev = list->prev;
    list = list->next;
    free(temp->data);
    free(temp);
    temp = NULL;
    return list;
}
