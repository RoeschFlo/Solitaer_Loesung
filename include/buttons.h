#ifndef BUTTONS_H
#define BUTTONS_H

#include "global_defines.h"
#include "raylib.h"

namespace solitaer_ns{
    
    class Button{

    public:
        Button(int x, int y);

        
        bool isClicked_m(void);
        bool isHovering_m(void);

        int get_x(void);
        int get_y(void);

        Color color;

    private:
        int x_m, y_m;

    
	    

    };
};



#endif // BUTTONS_H