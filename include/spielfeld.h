#ifndef SPIELFELD_H
#define SPIELFELD_H

#include "buttons.h"
namespace solitaer_ns{

    const int   PIXEL_OFFSET = 140;

    enum  Game_board_state{
        no_stone_chosen = 0,
        stone_to_be_moved_is_chosen = 1,
        target_is_chosen = 2,
    };

    enum field_states{

        empty_field = 0,
        occupied_field = 1,

        unaccessible = 2,
        accessible = 3,       
    };

    struct game_board_struct {
            int accessibility;
            int occupation_state;
            Color color_variable;
            solitaer_ns::Button* button_ptr;
            bool show_possibilities;
            bool is_possible_move_field;
            bool stone_move_request;
            bool is_endpossition_of_move;

        };


/* This class offers the game board and offers a interface to manipulate it
whether this is done by a human player, AI or algorithm is irrelevant*/
    class gameboard_class{

    public:
        gameboard_class();

        //Member variablen
    private:
        game_board_struct game_board [7][7];
        Button cancel_btn_obj;

        int number_of_moves;
        int global_state;
        
        //Member funktionen
    public:
        void draw_game (void);
        void check_buttons(void);
        void first_move(void);
        void manipulate_game_board(void);

    private:
        void show_possibilities(int x, int y);
        void reset_which_stone_to_move(void);

        bool is_target_valid(const int& start_x, const int& start_y);
        


    private:

    // const int   FIELD_TO_FIELD_OFFSET = 192;
    // const int   X_OFFSET = 170;
    // const int   Y_OFFSET = 150;

    enum field_states{

        empty_field = 0,
        occupied_field = 1,

        unaccessible = 2,
        accessible = 3,

        default_state = 4,
        clicked = 5,

        possible = 6,

    };

    


    };
};
#endif //SPIELFELD_H