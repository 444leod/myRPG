#include "../include/my_rpg.h"
int main(int argc, char const *argv[])
{
    sfRenderTexture *text = sfRenderTexture_create(1920, 1080, 0);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape *rect2 = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    sfRectangleShape_setSize(rect2, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 0, 0, 200));
    sfRectangleShape_setFillColor(rect2, sfColor_fromRGBA(0, 0, 255, 200));
    sfRenderTexture_drawRectangleShape(text, rect, NULL);
    sfRenderTexture_drawRectangleShape(text, rect2, NULL);
    sfRenderTexture_display(text);
    sfImage *image = sfTexture_copyToImage(sfRenderTexture_getTexture(text));
    sfColor color = sfImage_getPixel(image, 0, 0);
    return 0;
}

