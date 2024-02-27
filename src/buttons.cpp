#include "../include/buttons.h"
#include <iostream>

solitaer_ns::Button::Button(int x, int y){};

bool solitaer_ns::Button::isClicked_m(){

    //Vector2 Anlegen für Punkt, diesen mit getmousepositon füllen
    //zweiten vector 2 mit int x und int y füllen
    //radius wird noch benötigt, kann als Konstante definiert werden in global defines

	return IsMouseButtonPressed(
        MOUSE_LEFT_BUTTON) && CheckCollisionPointCircle(
            GetMousePosition(), { static_cast<float>(pos_x_m),
                static_cast<float>(pos_y_m), static_cast<float>(width_m), 
                static_cast<float>(height_m) }
        );
};