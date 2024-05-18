/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** wait
*/

#include "../../include/lib_csfml.h"

void my_wait(float seconds, sfRenderWindow *window)
{
    sfClock* clock = sfClock_create();
    sfTime elapsedTime = sfClock_getElapsedTime(clock);
    sfEvent event;

    while (sfTime_asSeconds(elapsedTime) < seconds) {
        sfRenderWindow_display(window);
        elapsedTime = sfClock_getElapsedTime(clock);
        while (sfRenderWindow_pollEvent(window, &event) && event.type ==
            sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
    }
    sfClock_destroy(clock);
    while (sfRenderWindow_pollEvent(window, &event));
}
