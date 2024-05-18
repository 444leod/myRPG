/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** intro
*/

#include "../include/my_rpg.h"

void display_intro(struct window *my_rpg, image_t sprite)
{
    display_all(my_rpg);
    continue_display(my_rpg);
    sfRenderTexture_drawSprite(RDTEXTURE, sprite->sprite, NULL);
    sfRenderTexture_display(RDTEXTURE);
    sfRenderTexture_display(HTEXTURE);
    sfSprite_setTexture(RDSPRITE, sfRenderTexture_getTexture(RDTEXTURE), true);
    sfRenderWindow_drawSprite(WINDOW, RDSPRITE, NULL);
    sfRenderWindow_display(WINDOW);
}

void load_intro(struct window *my_rpg)
{
    image_t *sprites = malloc(sizeof(struct my_image) * 6);
    sprites[0] = create_sprite("intro_end/discu1.png", (V2F){0, 0});
    sprites[1] = create_sprite("intro_end/discu2.png", (V2F){0, 0});
    sprites[2] = create_sprite("intro_end/discu3.png", (V2F){0, 0});
    sprites[3] = create_sprite("intro_end/discu4.png", (V2F){0, 0});
    sprites[4] = create_sprite("intro_end/discu5.png", (V2F){0, 0});
    sprites[5] = create_sprite("intro_end/discu6.png", (V2F){0, 0});
    for (int i = 0; i < 6 && sfRenderWindow_isOpen(WINDOW); i++) {
        if (sprites[i] == NULL)
            continue;
        display_intro(my_rpg, sprites[i]);
        my_wait(2, WINDOW);
        sfTexture_destroy(sprites[i]->texture);
        sfSprite_destroy(sprites[i]->sprite);
        free(sprites[i]);
    }
    my_wait(1, WINDOW);
    STATE(controls) = 1;
}
