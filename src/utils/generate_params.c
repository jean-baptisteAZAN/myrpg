/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-romain.collignon
** File description:
** gene
*/

#include "my.h"
#include "my_rpg.h"

sfSprite *my_sprite(sprite_create sprite)
{
    sfSprite *sprite_genrate = sfSprite_create();

    sfRectangleShape_setOrigin((sfRectangleShape *)
    sprite_genrate, sprite.origine);
    sfRectangleShape_setScale((sfRectangleShape *)
    sprite_genrate, sprite.scale);
    sfSprite_setPosition(sprite_genrate, sprite.position);
    sfSprite_setColor(sprite_genrate, sprite.color);
    sfSprite_setRotation(sprite_genrate, sprite.rotate);
    sfSprite_setTexture(sprite_genrate, sprite.texture, sfTrue);

    return sprite_genrate;
}

sfText *my_text(text_create text)
{
    sfText *txt = sfText_create();

    sfText_setFont(txt, text.font);
    sfText_setColor(txt, text.color);
    sfText_setPosition(txt, text.position);
    sfText_setString(txt, text.text);
    sfText_setCharacterSize(txt, text.size);
    return txt;
}

sfCircleShape *my_circle(circle_create circle)
{
    sfCircleShape *circle_generate = sfCircleShape_create();

    sfCircleShape_setPosition(circle_generate, circle.position);
    sfCircleShape_setOrigin(circle_generate, circle.origine);
    sfCircleShape_setOutlineThickness(circle_generate, circle.tickness);
    sfCircleShape_setRadius(circle_generate, circle.rad);
    sfCircleShape_setFillColor(circle_generate, circle.color);

    return circle_generate;
}

sfRectangleShape *my_rectangle(button_create button)
{
    sfRectangleShape *rect_generate = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect_generate, button.position);
    sfRectangleShape_setSize(rect_generate, button.size);
    sfRectangleShape_setFillColor(rect_generate, button.color);

    return rect_generate;
}
