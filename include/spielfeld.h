#ifndef SPIELFELD_H
#define SPIELFELD_H

#include "buttons.h"
namespace solitaer_ns{

    const int   PIXEL_OFFSET = 140;

    enum field_states{

        empty_field = 0,
        occupied_field = 1,

        unaccessible = 2,
        accessible = 3,       
    };

    struct game_board_struct {
            int accessibility;
            int occupation_state;
        };


/* This class offers the game board and offers a interface to manipulate it
whether this is done by a human player, AI or algorithm is irrelevant*/
    class gameboard_class{

    public:
        gameboard_class();

        //Member variablen
    private:
        game_board_struct game_board [7][7];
        /* here pointers to buttons get stored so they can be accessed by the same index
        as the game board fields*/
        solitaer_ns::Button* button_array [7][7];
        //Member funktionen
    public:
        void draw_game ();



    private:

    // const int   FIELD_TO_FIELD_OFFSET = 192;
    // const int   X_OFFSET = 170;
    // const int   Y_OFFSET = 150;

    enum field_states{

        empty_field = 0,
        occupied_field = 1,

        unaccessible = 2,
        accessible = 3,       
    };

    struct game_board_struct {
            int accessibility;
            int occupation_state;
        };



    };
};
#endif //SPIELFELD_H