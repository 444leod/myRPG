/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main struct of my_rpg project
*/

#ifndef B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_STRUCT_H
    #define B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_STRUCT_H

    #include "../my_rpg.h"


//          ███████ ████████ ██████  ██    ██  ██████ ████████
//          ██         ██    ██   ██ ██    ██ ██         ██
//          ███████    ██    ██████  ██    ██ ██         ██
//               ██    ██    ██   ██ ██    ██ ██         ██
//          ███████    ██    ██   ██  ██████   ██████    ██


typedef struct states {
        bool pause;
        bool quest;
        bool inventory;
        bool load;
        bool credits;
        bool options;
        bool main_menu;
        bool controls;
        bool save;
        bool fight;
        bool skills;
        int s_size;
        int s_type;
        int sound;
        float f_sound;
        int music;
        float f_music;
    } *state_t;

    struct tooltip {
        int is_active;
        sfSprite *sprite;
        sfTexture *texture;
        sfText *text;
        sfFont *font;
    };

//                  ███    ███ ███████ ███    ██ ██    ██
//                  ████  ████ ██      ████   ██ ██    ██
//                  ██ ████ ██ █████   ██ ██  ██ ██    ██
//                  ██  ██  ██ ██      ██  ██ ██ ██    ██
//                  ██      ██ ███████ ██   ████  ██████


    typedef struct menus {
        image_t main;
        image_t pause;
        image_t option;
        image_t load;
        image_t inventory;
        image_t controls;
        image_t skills;
        image_t skills2;
        image_t credits;

        rect_t sound;
        rect_t music;

        // in work
        image_t quest;

    } *menu_t;

    typedef struct buttons {
        // main menu //
        rect_t play;
        rect_t credits;
        rect_t option;
        rect_t exit;
        rect_t inventory;

        // option UI
        rect_t back;
        rect_t back2;
        rect_t *res;
        rect_t *sound;
        rect_t *music;
        rect_t fullscreen_rect;
        rect_t windowed_rect;
        image_t fullscreen;
        image_t windowed;
        image_t *screen_size;

        // load menu
        rect_t new_rect;
        rect_t load_rect;

        // pause menu
        rect_t pause_bg;
        rect_t resume;
        rect_t save;
        rect_t p_option;
        rect_t p_exit;

        // skills menu
        rect_t skills_bg;
        rect_t skill_hp;
        rect_t skill_dmg;
        rect_t skill_menu;
        rect_t grey;
    } *buttons_t;

    typedef struct texts {
        sfText *hp_level;
        sfText *dmg_level;
    } *text_t;

    typedef struct quests {
        sfText *text;
        sfText *nbr;
        sfText *nbr2;
        int id;
        int completed;
        int actual_completed;
        image_t bg;
    } *quests_t;

//               ██████  ██       █████  ██    ██ ███████ ██████
//               ██   ██ ██      ██   ██  ██  ██  ██      ██   ██
//               ██████  ██      ███████   ████   █████   ██████
//               ██      ██      ██   ██    ██    ██      ██   ██
//               ██      ███████ ██   ██    ██    ███████ ██   ██



    struct player {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f position;
        sfIntRect rect;
        sfSprite *info;
        sfTexture *info_texture;
        sfRectangleShape *hp_bar;
        sfRectangleShape *st_bar;
        sfVector2f st_size;
        sfVector2f hp_size;
        sfRectangleShape *hp_bg;
        sfRectangleShape *st_bg;
        float stamina;
        int max_stamina;
        int xp;
        int health;
        int max_health;
        float damage;
        int refill;
        int x;
        int y;
        int level;
        int skill_p;
        int damage_p;
        int health_p;
        int sword;
        int coconut;
        int animation_state;
        int speed;
        int direction;
        sfText *points_text;
        sfText *text_lvl;
        sfVector2f **hitbox;
    };


    typedef struct attack_stats {
        int damage;
        int speed;
        int precision;
        char *text;
    } *attack_t;

    typedef struct attack_slot {
        int id;
        image_t sprite;
        attack_t stats;
    } *slot_t;

    typedef struct ennemy {
        int id;
        int hp;
        int max_hp;
        float attack;
        image_t life;
        sfText *name;
        sfText *lvl;
    } *ennemy_t;

    typedef struct ally {
        slot_t *slots;
        float attack;
        int hp;
        int max_hp;
        image_t life;
        image_t xp;
        sfText *lvl;
    } *ally_t;

    typedef struct my_fight {
        ally_t ally;
        ennemy_t ennemy;
        image_t *attacks_sp;
        attack_t *attack_stats;
        sfText *attack_text;
        int nbr;
        bool first;
        bool fuit;
        rect_t *hitboxes;
        rect_t fight;
        rect_t bag_rect;
        rect_t cancel;
        image_t attacks;
        image_t healths;
        image_t fightscreen;
        image_t box;
        image_t *bg;
        int state;
        int zone;
        rect_t use_rect;
        image_t bag;
        int bag_state;
        sfText *bag_text;
        image_t no_more;
        bool leveled_up;
    } *fight_t;


//              ███████  ██████  ██    ██ ███    ██ ██████
//              ██      ██    ██ ██    ██ ████   ██ ██   ██
//              ███████ ██    ██ ██    ██ ██ ██  ██ ██   ██
//                   ██ ██    ██ ██    ██ ██  ██ ██ ██   ██
//              ███████  ██████   ██████  ██   ████ ██████


    typedef struct my_sound {
        sfSound *sound;
        sfSoundBuffer *buffer;
        sfMusic *music;
        sfSound *coconut;
        sfSound *sword;
        sfSound *whistle;
        sfSound *win;
    } *sound_t;


//                  ███    ███  █████  ██ ███    ██
//                  ████  ████ ██   ██ ██ ████   ██
//                  ██ ████ ██ ███████ ██ ██ ██  ██
//                  ██  ██  ██ ██   ██ ██ ██  ██ ██
//                  ██      ██ ██   ██ ██ ██   ████



    struct window {
        sfRenderTexture *texture;
        text_t texts;
        sfText *text;
        sfFont *font;
        sfSprite *sprite;
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
        sfClock *player_anim_clock;
        sfClock *player_mov_clock;
        sfClock *map_clock;
        sfClock *npc_clock;
        sfTime time;
        state_t states;
        menu_t menus;
        buttons_t buttons;
        sound_t sounds;
        fight_t fight;
        quests_t quests;
        struct map_manager *current_map;
        struct map_manager *tutorial;
        struct player *player;
        sfUint32 style;
        const sfUint8 *icon;
        sfVector2u size;
        image_t hitbox;
        sfRenderTexture *hitbox_texture;
        sfVector2f *hitbox_pos;
        sfSprite *hitbox_sprite;
        sfImage *hitbox_image;
        int npc_line;
        struct tooltip *tooltip;
    };



//                        ███    ███  █████  ██████
//                        ████  ████ ██   ██ ██   ██
//                        ██ ████ ██ ███████ ██████
//                        ██  ██  ██ ██   ██ ██
//                        ██      ██ ██   ██ ██



    typedef struct sprite {
        int id;
        sfSprite *sprite;
        struct sprite *next;
    } sprite;

    typedef struct tile {
        sfVector2f position;
        int walkable;
        sprite *sprite;
        struct tile *next;
    } tile;

    typedef struct map_manager {
        int tile_size;
        int animation_state;
        int animation_dir;
        int animation_count;
        float animation_speed;
        int animation_spacing;
        int player_display;
        sfTexture *texture;
        sprite *sprites;
        struct sprite *animated_sprites;
        struct tile *layers[4];
    } map_manager;


#endif //B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_STRUCT_H
