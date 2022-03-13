#include "CommonFunction.h"
#include "Board.h"
#include <ctime>
#include <iostream>

#undef main

bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {   
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if (g_screen == NULL)
        return false;
    return true;
}




int main(int arc, char* argv[])
{
    bool is_quit = false;
    if (Init() == false)
        return 0;
    // Apply Background
    g_bkground = SDLCommonFunc::LoadImage("background.png");
    if (g_bkground == NULL)
    {
        return 0;
    }
    //Make Board
    Board board;
    board.Show_Board(g_screen);
 
    SDL_Flip(g_screen);
    while (!is_quit)
    {
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0,SCREEN_HEIGHT,SCREEN_WIDTH);
        while (SDL_PollEvent(&g_even))
        {
            if (g_even.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
         
        }
        
        board.HandleInputAction(g_even);
        board.Show_Board(g_screen);
        if (SDL_Flip(g_screen) == -1)
            return 0;

        if (board.CheckBoard())
        {

            if (MessageBox(NULL, L"You Win!", L"Infomation", MB_ICONINFORMATION) == IDOK)
            {
                
                
                break;
            }
        }

       
        SDL_Delay(70);
    }
   
   
    
    SDLCommonFunc::CleanUp();
    SDL_Quit();

    return 1;
}
