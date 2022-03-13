#include "Cell.h"

Cell::Cell()
{
    rect_.x = 0;
    rect_.y = 0;
    val_ = 0;
}

Cell::~Cell()
{
    if (p_object != NULL)
    {
        SDL_FreeSurface(p_object);
    }
}

bool Cell::LoadImg(const char* file_name)
{
    p_object = SDLCommonFunc::LoadImage(file_name);
    if (p_object == NULL)
        return false;
    return true;
}

void Cell::Show(SDL_Surface* des)
{
    if (p_object != NULL)
    {
        rect_ = SDLCommonFunc::ApplySurface(p_object, des, rect_.x, rect_.y, rect_.w, rect_.h);
    }
}
void Cell::HandleInputAction(SDL_Event events)
{
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
       
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            val_++;
            if (val_ % 4 == 0) val_ = val_ - 4;
            if (val_ == 14) val_ = 12;
        }
        else if (events.button.button == SDL_BUTTON_RIGHT)
        {
            val_++;
            if (val_ % 4 == 0) val_ = val_ - 4;
            if (val_ == 14) val_ = 12;
        }
    }
}
