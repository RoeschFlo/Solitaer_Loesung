#ifndef BUTTONS_H
#define BUTTONS_H

#include "global_defines.h"
#include "raylib.h"

namespace solitaer_ns{
    
    class Button{

    public:
        Button(int x, int y);

        //void draw_m();
        bool isClicked_m();
    private:
	    //bool isHovering_m();

    };
};



#endif // BUTTONS_H