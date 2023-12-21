#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

//defines
#define srceen_size_x 1490
#define srceen_size_y 1450

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    InitWindow(srceen_size_x,srceen_size_y, "window");
    SetTargetFPS(50);
    Image spielfeld = LoadImage("../resources/Solitaer_Brett.png");
    Texture2D spielfeld_tex = LoadTextureFromImage(spielfeld);          
    

    while (!WindowShouldClose())
    {
        //Update

        //Draw
        BeginDrawing();
        
            //ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);  
        DrawTextureEx(spielfeld_tex, {0.0f, 0.0f}, 0.0f, 0.5f , WHITE);

        EndDrawing();

    }

        // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
    

    
    
}