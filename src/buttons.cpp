#include "../include/buttons.h"
#include <iostream>

solitaer_ns::Button::Button(int x, int y){
    x_m = x;
    y_m = y;
    color = GREEN;
};

bool solitaer_ns::Button::isClicked_m(void)
{
    //Vector2 Anlegen für Punkt, diesen mit getmousepositon füllen 
    Vector2 mouse_position_strct = GetMousePosition();
    //zweiten vector 2 mit int x und int y füllen
    Vector2 center_positon_struct = {float(x_m),float(y_m) };
    //radius wird noch benötigt, kann als Konstante definiert werden in global defines


	return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointCircle(
            mouse_position_strct, center_positon_struct, CIRCLE_RADIUS);
};

bool solitaer_ns::Button::isHovering_m(void)
{
    Vector2 mouse_position_strct = GetMousePosition();
    Vector2 center_positon_struct = {float(x_m),float(y_m) };

    return CheckCollisionPointCircle(mouse_position_strct, center_positon_struct,
        CIRCLE_RADIUS);
};

int solitaer_ns::Button::get_x(void) {return x_m;};

int solitaer_ns::Button::get_y(void) {return y_m;};