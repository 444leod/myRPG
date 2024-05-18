/*
** EPITECH PROJECT, 2023
** load_beach.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../include/my_rpg.h"
#include <stdlib.h>

tile *gen_map_tiles(map_manager *map, char *path)
{
    int **int_map = NULL;
    struct tile *tiles = NULL;
    int_map = get_int_map(path, 130);
    if (int_map == NULL) return NULL;
    for (int i = 0, j = 0; int_map[i] != NULL; j++) {
        if (int_map[i][j] == -255){
            j = -1;
            i++;
            continue;
        }
        if (int_map[i][j] == -1)
            continue;
        tiles = add_tile(tiles, get_sprite(map, int_map[i][j]),
            (V2F){j * 48, i * 48}, 1);
    }
    return tiles;
}

void generate_sprites(map_manager *map)
{
    sfVector2u bounds = sfTexture_getSize(map->texture);
    int x = 0;
    int y = 0;
    int x_count = bounds.x / map->tile_size;
    int y_count = bounds.y / map->tile_size;
    for (int i = 0; i < x_count * y_count - 1; ++i) {
        if (y <= 8 * map->tile_size)
            add_ani_sprite(map, gen_sprite(map->texture, (V2F){x, y}),i);
        else
            add_sprite(map, gen_sprite(map->texture, (V2F){x, y}),i);
        if (x >= (int)bounds.x - map->tile_size) {
            x = 0;
            y += map->tile_size;
        } else
            x += map->tile_size;
    }
}

static void continue_loading(map_manager *map)
{
    map->layers[0] = NULL;
    map->layers[1] = NULL;
    map->layers[2] = NULL;
    map->layers[3] = NULL;
    map->layers[0] = gen_map_tiles(map, "assets/map/tutorial/layer_1.csv");
    map->layers[1] = gen_map_tiles(map, "assets/map/tutorial/layer_2.csv");
    map->layers[2] = gen_map_tiles(map, "assets/map/tutorial/layer_3.csv");
    map->layers[3] = gen_map_tiles(map, "assets/map/tutorial/layer_4.csv");
}

map_manager *load_tutorial(void)
{
    map_manager *map = malloc(sizeof(struct map_manager));
    map->tile_size = 48;
    map->player_display = 4;
    map->animation_state = 0;
    map->animation_dir = 1;
    map->animation_count = 4;
    map->animation_speed = .5;
    map->animation_spacing = 9;
    map->animated_sprites = NULL;
    map->sprites = NULL;
    map->texture =
        sfTexture_createFromFile("assets/map/tutorial/sprite.png", NULL);
    generate_sprites(map);
    continue_loading(map);
    return map;
}
