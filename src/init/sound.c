/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** sound
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

static int init_all_sounds(struct window *my_rpg)
{
    SOUND(coconut) = sfSound_create();
    sfSoundBuffer *b = sfSoundBuffer_createFromFile("assets/sound/coconut.ogg");
    sfSound_setBuffer(SOUND(coconut), b);
    sfSound_setVolume(SOUND(coconut), 50);
    SOUND(sword) = sfSound_create();
    b = sfSoundBuffer_createFromFile("assets/sound/sword.ogg");
    sfSound_setBuffer(SOUND(sword), b);
    sfSound_setVolume(SOUND(sword), 50);
    return SUCCESS;
}

int init_sounds(struct window *my_rpg)
{
    my_rpg->sounds = malloc(sizeof(struct my_sound));
    CHECK_MALLOC(my_rpg->sounds);
    CHECK_ERROR(init_all_sounds(my_rpg));
    SOUND(whistle) = sfSound_create();
    sfSoundBuffer *b = sfSoundBuffer_createFromFile("assets/sound/whistle.ogg");
    sfSound_setBuffer(SOUND(whistle), b);
    sfSound_setVolume(SOUND(whistle), 50);
    SOUND(win) = sfSound_create();
    b = sfSoundBuffer_createFromFile("assets/sound/win.ogg");
    sfSound_setBuffer(SOUND(win), b);
    sfSound_setVolume(SOUND(win), 50);
    SOUND(music) = sfMusic_createFromFile("assets/sound/main_theme.ogg");
    CHECK_MALLOC(SOUND(music));
    sfMusic_setLoop(SOUND(music), sfTrue);
    sfMusic_setVolume(SOUND(music), 50);
    return SUCCESS;
}
