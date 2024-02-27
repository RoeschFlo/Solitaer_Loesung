
#include <raylib.h>
#include <iostream>

#include "../include/spielfeld.h"
#include "../include/global_defines.h"

solitaer_ns::gameboard_class::gameboard_class(){

    /*init of game_board, filds with + are accessible
    || 0.0 || 1.0 ||+2.0 ||+3.0 ||+4.0 || 5.0 || 6.0 ||
    || 0.1 || 1.1 ||+2.1 ||+3.1 ||+4.1 || 5.1 || 6.1 ||
    ||+0.2 ||+1.2 ||+2.2 ||+3.2 ||+4.2 ||+5.2 ||+6.2 ||
    ||+0.3 ||+1.3 ||+2.3 ||+3.3 ||+4.3 ||+5.3 ||+6.3 ||
    ||+0.4 ||+1.4 ||+2.4 ||+3.4 ||+4.4 ||+5.4 ||+6.4 ||
    || 0.5 || 1.5 ||+2.5 ||+3.5 ||+4.5 || 5.5 || 6.5 ||
    || 0.6 || 1.6 ||+2.6 ||+3.6 ||+4.6 || 5.6 || 6.6 ||
    */

    //initialisation of the game board fields and the buttons
    for (int x=0; x< 7;++x ){ //effizienter als x++
        for(int y=0; y < 7; ++y ){
            
            if( (x <= 1 && (y <= 1 || y>= 5 ))|| //not a fields shall be 1!
                (x >= 5 && (y <= 1 || y>= 5 ))
                )
            {
                game_board[x][y].accessibility =field_states::unaccessible;
                game_board[x][y].occupation_state =field_states::empty_field;
                button_array[x][y] = nullptr;
            }
            else
            {
            game_board[x][y].accessibility = field_states::accessible;
            game_board[x][y].occupation_state = field_states::occupied_field;
            //check at every access that that button is not nullptr!
            button_array[x][y] = new Button(FIELD_TO_FIELD_OFFSET*x+ X_OFFSET,
                                            FIELD_TO_FIELD_OFFSET*y+Y_OFFSET);
            }
        }
    }

    
};

void solitaer_ns::gameboard_class::draw_game(){
   // DrawCircle(175, 540, 30.0, RED);

    //DrawCircle(555, 155, 30.0, GREEN);
    for (int x=0; x< 7;++x ){ //effizienter als x++
        for(int y=0; y < 7; ++y ){
            
            if (game_board[x][y].accessibility==field_states::accessible &&
                game_board[x][y].occupation_state==field_states::occupied_field)
                {
                    DrawCircle(FIELD_TO_FIELD_OFFSET*x+ X_OFFSET, 
                                FIELD_TO_FIELD_OFFSET*y+Y_OFFSET,
                        30.0, YELLOW);
                }
        }
    }

    /*Warum geht das?
    int* ptr = reinterpret_cast<int*>(0x0);
    std::cout << &ptr;*/
    
};