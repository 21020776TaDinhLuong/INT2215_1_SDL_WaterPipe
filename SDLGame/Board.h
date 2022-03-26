#ifndef BOARD_H_
#define BOARD_H_
const int RIGHT = 0;
const int LEFT = 1;
const int UP = 2;
const int DOWN = 3;
#include "CommonFunction.h"
#include "Cell.h"
#include<iostream>
#include <queue>
class Board
{
	public:
		Board();
		~Board();
		void Show_Board(SDL_Surface* des);
		bool CheckBoard();
		void HandleInputAction(SDL_Event events);
		void print();
		void convert();
		
		
	private:
		Cell arr[4][4];
		bool check[4][4];
		bool direct[18][4];

		
};
#endif

