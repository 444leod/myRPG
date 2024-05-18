/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** functions of my_rpg project
*/

#ifndef B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_FUNCTIONS_H
    #define B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_FUNCTIONS_H

    #include "macro.h"
    #include "struct.h"

//   ███████ ██    ██ ███    ██  ██████ ████████ ██  ██████  ███    ██ ███████
//   ██      ██    ██ ████   ██ ██         ██    ██ ██    ██ ████   ██ ██
//   █████   ██    ██ ██ ██  ██ ██         ██    ██ ██    ██ ██ ██  ██ ███████
//   ██      ██    ██ ██  ██ ██ ██         ██    ██ ██    ██ ██  ██ ██      ██
//   ██       ██████  ██   ████  ██████    ██    ██  ██████  ██   ████ ███████







//                        ███    ███  █████  ██████
//                        ████  ████ ██   ██ ██   ██
//                        ██ ████ ██ ███████ ██████
//                        ██  ██  ██ ██   ██ ██
//                        ██      ██ ██   ██ ██


/**
 * @brief load the tutorial map
*/
map_manager *load_tutorial(void);

/**
 * @brief Display the map
 * @param struct my_rpg
 * @param struct tile
*/
void display_map(struct window *my_rpg, tile *tiles);

/**
 * @brief Generate a sprite
 * @param texture Texture of the sprite
 * @param pos Position of the sprite
 * @return The sprite
 */
sfSprite *gen_sprite(sfTexture *texture, V2F pos);

/**
 * @brief Add an animated sprite to the map
 * @param map The map
 * @param sprite The sprite
 * @param id the id of the sprite
 */
void add_ani_sprite(map_manager *map, sfSprite *sprite, int id);

/**
 * @brief Add a sprite to the map
 * @param map The map
 * @param sprite The sprite
 * @param id The id of the sprite
 */
void add_sprite(map_manager *map, sfSprite *sprite, int id);

/**
 * @brief Add a tile to the tile list
 * @param tiles The tile list
 * @param sprite The sprite of the tile
 * @param pos The position of the tile
 * @param walkable is the tile walkable
 */
tile *add_tile(tile *tiles, sprite *sprite, V2F pos, int walkable);

/**
 * @brief Get the sprite from its id
 * @param map The map where the sprite is
 * @param id The id of the sprite
 * @return The sprite or NULL if not found
 */
sprite *get_sprite(map_manager *map, int id);

/**
 * @brief Retrieve the map from a CSV file
 * @param path Path to the CSV file
 * @param size Size of the map (Tile count)
 * @return An int table containing the map
 */
int **get_int_map(char *path, int size);



//               ██████  ██       █████  ██    ██ ███████ ██████
//               ██   ██ ██      ██   ██  ██  ██  ██      ██   ██
//               ██████  ██      ███████   ████   █████   ██████
//               ██      ██      ██   ██    ██    ██      ██   ██
//               ██      ███████ ██   ██    ██    ███████ ██   ██



/**
 * @brief update the player animation
 * @param map_manager
*/
void update_animation(map_manager *map);

/**
 * @brief update the player position
 * @param struct my_rpg
*/
void update_player(struct window *my_rpg);

/**
 * @brief update the player animation
 * @param struct my_rpg
*/
void update_p_animation(struct window *my_rpg);

/**
 * @brief init the player
 * @param struct my_rpg
 * @return 0 if success
 * @return 84 if error
*/
int init_player(struct window *my_rpg);

/**
 * @brief display the player
 * @param struct my_rpg
*/
void display_player(struct window *my_rpg);

/**
 * @brief move the player
 * @param struct my_rpg
*/
void move_player(struct window *my_rpg);



//                  ███    ███ ███████ ███    ██ ██    ██
//                  ████  ████ ██      ████   ██ ██    ██
//                  ██ ████ ██ █████   ██ ██  ██ ██    ██
//                  ██  ██  ██ ██      ██  ██ ██ ██    ██
//                  ██      ██ ███████ ██   ████  ██████

void display_option(struct window *my_rpg);

int init_menus(struct window *my_rpg);

int change_sound(struct window *my_rpg, int volume);
/**
 * @brief change the music volume
 * @param my_rpg The main struct
 * @param volume The volume to add
 * @return
 */
int change_music(struct window *my_rpg, int volume);

void menu_display_hover(struct window *my_rpg, sfVector2f pos);

/**
 * @brief handle all the menu's click and else
 * @param my_rpg the main struct
 * @param pos the position of the mouse
*/
void handle_menus(struct window *my_rpg, sfVector2f pos);
void handle_pause_menu(struct window *my_rpg, sfVector2f pos);
void handle_controls(struct window *my_rpg, sfVector2f pos);
void handle_skills(struct window *my_rpg, sfVector2f pos);

/**
 * @brief display the different menus
 * @param my_rpg the main struct
*/
void display_menu(struct window *my_rpg);

/**
 * @brief display the main menu
 * @param my_rpg the main struct
*/
void display_main_menu(struct window *my_rpg);

void handle_screen_change(struct window *my_rpg, sfVector2f pos);

void handle_sound_change(struct window *my_rpg, sfVector2f pos);


//                  ███    ███  █████  ██ ███    ██
//                  ████  ████ ██   ██ ██ ████   ██
//                  ██ ████ ██ ███████ ██ ██ ██  ██
//                  ██  ██  ██ ██   ██ ██ ██  ██ ██
//                  ██      ██ ██   ██ ██ ██   ████


/**
 * @brief launch the main function
 * @param int ac
 * @param char **av
 * @param char **env
*/
int myrpg(int ac, char **av, char **env);

/**
 * @brief init all the struct
 * @param  my_rpg the main struct
 * @return 0 if success
 * @return 84 if error
*/
int init_all(struct window * my_rpg);

/**
 * @brief display all the sprites
 * @param my_rpg the main struct
*/
void display_all(struct window *my_rpg);

int init_window(struct window *my_rpg);
int init_states(struct window *my_rpg);
int init_buttons(struct window *my_rpg);
int init_sounds(struct window *my_rpg);
int init_texts(struct window *my_rpg);
void save_settings(struct window *my_rpg);
int load_settings(struct window *my_rpg);
void save_player_data(struct window *my_rpg);
void reload_window(struct window *my_rpg);
void save_data(char *path, char *data, int size);
int get_health(void);
int get_stamina(void);
int get_xp(void);
void display_save_data(struct window *my_rpg);
int load_player_data(struct window *my_rpg);
void reset_player_data(struct window *my_rpg);
int init_collision(struct window *my_rpg);
bool check_coll(struct window *my_rpg, char c);
int save_exists(void);
void get_coconut(struct window *my_rpg);
void unload_tutorial(struct window *my_rpg);
sprite *get_sprite_by_id(sprite *sprites, int id);
sfVector2u get_current_tile(struct window *my_rpg);
tile *get_tile(struct window *my_rpg, sfVector2u tile, struct tile *layer);
void remove_tile(struct tile *tile, struct tile *layer);
struct tile *is_there_a_coconut_near_me(struct tile *layer,
        struct window *my_rpg);
int is_this_a_coconut(struct tile *tile);
void display_coconut_help(struct window *my_rpg);

slot_t create_slot(int id, image_t sprite, attack_t attack);
attack_t create_attack(int damage, int speed, int precision, char *text);
int init_fight(struct window *my_rpg);
bool check_coll(struct window *my_rpg, char c);
int init_collision(struct window *my_rpg);
void handle_fight_event(struct window *my_rpg, sfVector2f pos);
void attack(struct window *my_rpg, int attack_id);
void fight_screen(struct window *my_rpg);
void display_fight(struct window *my_rpg);
int init_fight_texts(struct window *my_rpg);
int get_rand_between(int min, int max);
void ennemy_attack(struct window *my_rpg, attack_t attack);
void ally_attack(struct window *my_rpg, attack_t attack);
void change_state_fight(struct window *my_rpg);
void special_attack(struct window *my_rpg, attack_t attack, attack_t ennemy);
int init_fight_lifes(struct window *my_rpg);
void update_health(struct window *my_rpg);
void update_health_smooth(struct window *my_rpg, attack_t attack, int *hp,
    float multi);
void check_if_win(struct window *my_rpg);
void handle_option(struct window *my_rpg, sfVector2f pos);
void display_bag(struct window *my_rpg);
void handle_option(struct window *my_rpg, sfVector2f pos);
void display_bag(struct window *my_rpg);
void destroy_all(struct window *my_rpg);
void clean_player(struct window *my_rpg);
void clean_map(struct map_manager *map);
void display_npc_interaction(struct window *my_rpg);
struct tile *am_i_near_a_npc(struct tile *layer, struct window *my_rpg);
char *get_npc_line(int npc_id, int line_id);
void display_tooltip(char *text, struct window *my_rpg);
void hide_tooltip(struct window *my_rpg);
void draw_tooltip(struct window *my_rpg);
void clean_tooltip(struct tooltip *tooltip);
int init_tooltip(struct window *my_rpg);
void display_quest(struct window *my_rpg);
int init_quests(struct window *my_rpg);
struct tile *am_i_near_a_sword(struct tile *layer, struct window *my_rpg);
void display_sword_help(struct window *my_rpg);
void get_sword(struct window *my_rpg);
void level_up(struct window *my_rpg);
sfText *new_txt(char *str, int size, sfVector2f pos, sfFont *font);
void use_coconut(struct window *my_rpg);
void display_choose_attack(struct window *my_rpg);
void display_window(struct window *my_rpg);
void load_intro(struct window *my_rpg);
void continue_display(struct window *my_rpg);
int verif_deps(void);
#endif //B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_FUNCTIONS_H
