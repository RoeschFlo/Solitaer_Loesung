
#include <raylib.h>
#include <iostream>
#include <stdlib.h>

#include "../include/spielfeld.h"
#include "../include/global_defines.h"

solitaer_ns::gameboard_class::gameboard_class():
    cancel_btn_obj(1000, 1000)
{

    number_of_moves = 0;
    global_state = no_stone_chosen;

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
    for (int x=0; x< 7;++x )
        { //effizienter als x++
            for(int y=0; y < 7; ++y )
            {

                game_board[x][y].color_variable = YELLOW;
                game_board[x][y].show_possibilities = false;
            
                if( (x <= 1 && (y <= 1 || y>= 5 ))|| //not a fields shall be 1!
                    (x >= 5 && (y <= 1 || y>= 5 ))
                )
                {
                    game_board[x][y].accessibility =field_states::unaccessible;
                    game_board[x][y].occupation_state =field_states::empty_field;
                    game_board[x][y].button_ptr = nullptr;
                
                }
                else  //fields that are occupied at the beginning of the game
                {
                game_board[x][y].accessibility = field_states::accessible;
                game_board[x][y].occupation_state = field_states::occupied_field;
                game_board[x][y].stone_move_request = false;
                game_board[x][y].is_possible_move_field = false;
                game_board[x][y].show_possibilities = false;

                //check at every access that that button is not nullptr!
                game_board[x][y].button_ptr = new Button(FIELD_TO_FIELD_OFFSET*x+ X_OFFSET,
                                            FIELD_TO_FIELD_OFFSET*y+Y_OFFSET);
            }
        }
    }       
};

void solitaer_ns::gameboard_class::draw_game(void)
{
    for (int x=0; x< 7;++x )
    { //effizienter als x++
        for(int y=0; y < 7; ++y )
        {
            
            if (game_board[x][y].accessibility==field_states::accessible &&
                game_board[x][y].occupation_state==field_states::occupied_field)
            {
                    DrawCircle(FIELD_TO_FIELD_OFFSET*x+ X_OFFSET, 
                                FIELD_TO_FIELD_OFFSET*y+Y_OFFSET,
                        CIRCLE_RADIUS, game_board[x][y].color_variable);
            }
        }
    } 

    // the cancel button
    DrawCircle(cancel_btn_obj.get_x(), cancel_btn_obj.get_y(),
        CIRCLE_RADIUS, cancel_btn_obj.color);

    DrawText("Press to cancel current move", cancel_btn_obj.get_x(),
        cancel_btn_obj.get_y()+25 ,30, BLACK);

};

void solitaer_ns::gameboard_class::check_buttons(void)
{
    //iterate over the whole board
    for (int x=0; x< 7;++x ){ //effizienter als x++
        for(int y=0; y < 7; ++y )
        {
            if (game_board[x][y].button_ptr!=nullptr)
            {
                // if hovering we could be possible that we press the button
                if (game_board[x][y].button_ptr->isHovering_m())
                {
                    game_board[x][y].color_variable = RED;
                    game_board[x][y].show_possibilities = true;

                    if(game_board[x][y].button_ptr->isClicked_m())
                    {
                        std::cout<< "Button" << x <<":" << y << "was clicked";

                        if (global_state == no_stone_chosen){
                        /*if no stone is chosen the player choses the stone
                        which he wants to move*/
                        
                        game_board[x][y].stone_move_request = true;
                        global_state = stone_to_be_moved_is_chosen;
                        }
                        else /*ergo global_state == stone_to_be_moved_is_chosen*/ 
                        { 
                            game_board[x][y].is_endpossition_of_move = true;
                            global_state = target_is_chosen;
                        }
                    }
                }
                else /*ergo we are not hovering over buttons*/
                {
                    game_board[x][y].color_variable = YELLOW; 
                    game_board[x][y].show_possibilities = false;
                }
            }
        }
    }

    if(cancel_btn_obj.isHovering_m())
    {
        cancel_btn_obj.color = RED;

        if(cancel_btn_obj.isClicked_m())
        {
            reset_which_stone_to_move();
        }
    }
    else 
    { 
        cancel_btn_obj.color = PINK;
    } 
};





/*Funktion that checks from the second move on if a move is 
possible and if so it removes a stone*/
void solitaer_ns::gameboard_class::manipulate_game_board(void)
{
    
    //if we do not indent to move a stone we dont need do waste cpu
    if (global_state == target_is_chosen){

        for (int x=0; x< 7;++x ) //effizienter als x++
        {   for(int y=0; y < 7; ++y )

                if (game_board[x][y].button_ptr != nullptr)
                {   //beware of out of bounds error!!! 
            
                    if (game_board[x][y].stone_move_request &&
                        is_target_valid(x,y))
                    {
                        game_board[x][y].occupation_state = empty_field;
                        game_board[x][y].stone_move_request = false;
                        number_of_moves++;
                }
        
            }    
        }
    }
};

/*we need to check if there is stone between the stone we want to move
and the empty field we have chosen as our target
there for we search for the stone that is requested to move*/
bool solitaer_ns::gameboard_class::is_target_valid(const int& start_x, const int& start_y)
{ 
    for (int target_x=0; target_x< 7; ++target_x )
    { 
        for(int target_y=0; target_y < 7; ++target_y )
        {
            if (game_board[target_x][target_y].button_ptr != nullptr && 
                game_board[target_x][target_y].is_endpossition_of_move)
            {


                /*two conditions must be fullfilled:
                1. there must be a shit of 2 fields between the target
                and the moving stone in x exclusive_or y
                2. there must be a stone to skip in the field between*/
                if(abs(start_x - target_x)==2 && start_y == target_y){
                    if(target_x < start_x  && 
                        game_board[target_x+1][target_y].occupation_state == occupied_field)
                    {
                        game_board[target_x+1][target_y].occupation_state = empty_field;
                        return true;
                    }
                    if(target_x > start_x &&
                       game_board[target_x-1][target_y].occupation_state == occupied_field)
                    {
                        game_board[target_x-1][target_y].occupation_state = empty_field;
                        return true;
                    }
                }


                if(abs(target_y - start_y)==2 && start_x == target_x){
                    if(target_y < start_y &&
                        game_board[target_x][target_y+1].occupation_state == occupied_field)
                    {
                        game_board[target_x][target_y+1].occupation_state = empty_field;
                        return true;
                    }
                    if(target_y > start_y &&
                        game_board[target_x][target_y-1].occupation_state == occupied_field)
                    {
                        game_board[target_x][target_y-1].occupation_state = empty_field;
                        return true;
                    }
                }    
            }    
        }    
    }
    return false;
};


/*checks if neighbour field is occupied and the field 2 fields away from 
(x|y) is free and accessible */
void solitaer_ns::gameboard_class::show_possibilities (int x, int y)
{
    
};

/*this function reverts the decision of the player to move a certain
stone*/
void solitaer_ns::gameboard_class::reset_which_stone_to_move(void)
{
    global_state = no_stone_chosen;   

    for (int x=0; x< 7;++x ){ //effizienter als x++
        for(int y=0; y < 7; ++y )
        {
            game_board[x][y].stone_move_request = false;
            game_board[x][y].is_endpossition_of_move = false;
        }
    }    
};
