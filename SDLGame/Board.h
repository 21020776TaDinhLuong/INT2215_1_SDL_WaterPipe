#ifndef BOARD_H_
#define BOARD_H_
#include "CommonFunction.h"
#include "Cell.h"
class Board
{
	public:
		Board();
		~Board();
		void Show_Board(SDL_Surface* des);
		bool CheckBoard();
		void print();
		void HandleInputAction(SDL_Event events);
	private:
		Cell arr[4][4];
};
#endif

