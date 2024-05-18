/*
** EPITECH PROJECT, 2023
** CSFML Lib
** File description:
** lib_csfml
*/


#pragma once


/* ######    CSFML                 ###### */


    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/Network.h>


/* ######    STRUCTURES            ###### */


    typedef struct my_image {
        sfSprite *sprite;
        sfTexture *texture;
        sfFloatRect rect;
    }*image_t;
    typedef struct my_rect {
        sfRectangleShape *rect;
        sfIntRect bounds;
    }*rect_t;


/* ######    CSFML MACROS          ###### */


typedef sfVector2f V2F;
typedef sfIntRect IRECT;

    #define bool int
    #define true 1
    #define false 0
    #define GET_EVENT sfRenderWindow_pollEvent
    #define SP_GET_BOUNDS sfSprite_getGlobalBounds
    #define RECT_GET_BOUNDS sfRectangleShape_getGlobalBounds
    #define MOUSE_ON is_mouse_on_sprite
    #define MOUSE_ON_F is_mouse_on_sprite_f

    enum shape_type {
        SPRITE,
        RECTANGLE
    };


/* ######    MAIN FUNCTIONS        ###### */



/**
    * @brief Create a sprite object from a path
    * @param path
    * @return sfSprite* if the path is correct, NULL otherwise
*/
image_t create_sprite(char *path, sfVector2f pos);


/**
    * @brief Set the position of a sprite
    * @param sprite
    * @param pos
*/
void set_position(sfSprite *sprite, sfVector2f pos);


/**
    * @brief Create a rect_t object
    * @param color
    * @param rect
    * @return rect_t if the rectangle is created, NULL otherwise
*/
rect_t create_rect(sfColor color, sfIntRect rect);


/**
    * @brief Create a sprite object and its bounds
    * @param file_name
    * @param pos
    * @param sprite
    * @param spBounds
    * @return int 0 if the sprite is created, 84 otherwise
*/
int create_sprite_bounds(char *file_name, sfVector2f pos, sfSprite **sprite,
    sfFloatRect *spBounds);

/**
 * @brief make a sprite visible or not
 * @param sprite
*/
void sp_set_visible(sfSprite *sprite, bool state);


/**
 * @brief get the position of mouse in pixels
 * @param m
 * @return sfVector2f pos in px
*/
sfVector2f get_pxmousepos(sfRenderWindow *window);


/**
 * @brief check if the mouse is on a sprite
 * @param sprite_rect
 * @param mouse_pos
 * @return true if the mouse is on the sprite, false otherwise
*/
bool is_mouse_on_sprite(sfIntRect sprite_rect, sfVector2f mouse_pos);


/**
 * @brief change the state of a button
 * @param state
 * @param button
 * @return the new state of the button
*/
int change_state(int state, int button);

/**
 * @brief make a rectangle visible or not
 * @param rect
 * @param state
*/
void rect_set_visible(sfRectangleShape *rect, bool state);


/**
 * @brief get the color of the pixel under the mouse
 * @param sprite
 * @param mousePos
 * @param bounds
 * @return sfColor
*/
sfColor get_pixel(sfSprite *sprite, sfVector2f mousePos, sfFloatRect bounds);

/**
    * @brief draw the sprite if the mouse is hover
    * @param window
    * @param bounds
    * @param sprite
    * @param mousePos
*/
void draw_if_hover(sfRenderTexture *window, sfFloatRect bounds,
    sfSprite *sprite, sfVector2f mousePos);


void text_set_visible(sfText *text, bool state);

sfVector2f substract_vectors(sfVector2f v1, sfVector2f v2);

bool is_mouse_on_sprite_f(sfFloatRect sprite_rect, sfVector2f mouse_pos);

void display_hover(V2F pos, int type, sfRenderTexture *window, ...);

bool has_clicked(sfEvent event, sfMouseButton button);
void my_wait(float seconds, sfRenderWindow *window);
