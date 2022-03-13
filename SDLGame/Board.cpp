#include "Board.h"
#include <iostream>

Board::Board()
{
	arr[0][0].set_val(6);
	arr[0][1].set_val(0);
	arr[0][2].set_val(1);
	arr[0][3].set_val(5);
	arr[1][0].set_val(12);
	arr[1][1].set_val(3);
	arr[1][2].set_val(7);
	arr[1][3].set_val(13);
	arr[2][0].set_val(9);
	arr[2][1].set_val(8);
	arr[2][2].set_val(9);
	arr[2][3].set_val(4);
	arr[3][0].set_val(0);
	arr[3][1].set_val(7);
	arr[3][2].set_val(12);
	arr[3][3].set_val(0);

}
Board::~Board()
{

}
void Board::Show_Board(SDL_Surface* des)
{
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j].LoadImg(s[arr[i][j].get_val()].c_str());
			arr[i][j].SetRect(i * HEIGHT_CELL, j * WIDTH_CELL, WIDTH_CELL, HEIGHT_CELL);
			arr[i][j].Show(des);
		}
	}
}
bool Board::CheckBoard()
{
	return (arr[0][0].get_val() == 7 && arr[0][1].get_val() == 3 && arr[0][2].get_val() == 1 && arr[0][3].get_val() == 6 && arr[1][0].get_val() == 12 && arr[1][1].get_val() == 1 && arr[1][2].get_val() == 6 && arr[1][3].get_val() == 12 && arr[2][0].get_val() == 10 && arr[2][1].get_val() == 9 && arr[2][2].get_val() == 11 && arr[2][3].get_val() == 5 && arr[3][0].get_val() == 2 && arr[3][1].get_val() == 4 && arr[3][2].get_val() == 13 && arr[3][3].get_val() == 3);
}
void Board::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_MOUSEBUTTONDOWN)
	{

		if (events.button.button == SDL_BUTTON_LEFT)
		{
			int x_loc = events.button.x / HEIGHT_CELL; 
			int y_loc = events.button.y / WIDTH_CELL;
			arr[x_loc][y_loc].HandleInputAction(events);
			arr[x_loc][y_loc].Show(g_screen);


		}
		else if (events.button.button == SDL_BUTTON_RIGHT)
		{
			int x_loc = events.button.x / HEIGHT_CELL;
			int y_loc = events.button.y / WIDTH_CELL;
			arr[x_loc][y_loc].HandleInputAction(events);
			arr[x_loc][y_loc].Show(g_screen);
		}
	}
}
void Board::print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cerr << arr[i][j].get_val() << ' ';
		std::cerr << '\n';
	}
		
}