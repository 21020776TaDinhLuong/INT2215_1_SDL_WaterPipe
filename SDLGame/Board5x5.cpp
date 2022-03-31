#include "Board5x5.h"
#include <iostream>

Board5x5::Board5x5()
{
	
	arr[0][0].set_val(1);
	arr[0][1].set_val(1);
	arr[0][2].set_val(12);
	arr[0][3].set_val(12);
	arr[0][4].set_val(7);
	arr[1][0].set_val(5);
	arr[1][1].set_val(8);
	arr[1][2].set_val(1);
	arr[1][3].set_val(1);
	arr[1][4].set_val(9);
	arr[2][0].set_val(5);
	arr[2][1].set_val(8);
	arr[2][2].set_val(14);
	arr[2][3].set_val(13);
	arr[2][4].set_val(10);
	arr[3][0].set_val(12);
	arr[3][1].set_val(1);
	arr[3][2].set_val(9);
	arr[3][3].set_val(3);
	arr[3][4].set_val(13);
	arr[4][0].set_val(4);
	arr[4][1].set_val(3);
	arr[4][2].set_val(1);
	arr[4][3].set_val(12);
	arr[4][4].set_val(5);
	arr[2][2].set_watered(1);
	

}
Board5x5::~Board5x5()
{

}
void Board5x5::Show_Board(SDL_Surface* des)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j].update();
			arr[i][j].LoadImg(h[arr[i][j].get_val()].c_str());
			arr[i][j].SetRect(i * WIDTH_CELL_5x5, j * HEIGHT_CELL_5x5, WIDTH_CELL_5x5, HEIGHT_CELL_5x5);
			arr[i][j].Show(des);
		}
	}
}
bool Board5x5::CheckBoard()
{
	bool ok = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j].get_watered() == 0) ok = false;
		}
	}
	return ok;

}
void Board5x5::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_MOUSEBUTTONDOWN)
	{

		if (events.button.button == SDL_BUTTON_LEFT)
		{
			int x_loc = events.button.x / WIDTH_CELL_5x5;
			int y_loc = events.button.y / HEIGHT_CELL_5x5;
			arr[x_loc][y_loc].HandleInputAction(events);
			arr[x_loc][y_loc].Show(g_screen);


		}
		else if (events.button.button == SDL_BUTTON_RIGHT)
		{
			int x_loc = events.button.x / 96;
			int y_loc = events.button.y / 96;
			arr[x_loc][y_loc].HandleInputAction(events);
			arr[x_loc][y_loc].Show(g_screen);
		}
	}
	else if (events.type == SDL_KEYDOWN)
	{
		if (events.key.keysym.sym == SDLK_ESCAPE)
		{
			return;
		}
	}
}
void Board5x5::convert()
{
	std::pair<int, int> source = std::make_pair(2, 2);
	std::vector< int > dx = { 1, -1, 0, 0 };
	std::vector< int > dy = { 0, 0, -1, 1 };
	memset(check, false, sizeof check);
	bool  direct[18][4] =
	{ {1, 0, 0, 0},
	{0, 0, 0, 1},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0},
	{1, 0, 0, 1},
	{1, 1, 1, 0},
	{1, 0, 1, 1},
	{1, 1, 0, 1},
	{0, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 1, 1, 0},
	{1, 0, 1, 1},
	{1, 1, 0, 1},
	{0, 1, 1, 1}
	};

	std::queue< std::pair< int, int > > q;
	//TODO : parameterize
	q.push(source);
	check[source.first][source.second] = true;
	//BFS
	while (!q.empty()) {
		std::pair< int, int > current_cell = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			const int value = arr[current_cell.first][current_cell.second].get_val() % 18;
			std::pair< int, int > new_cell;
			if (direct[value][dir]) {
				new_cell.first = current_cell.first + dx[dir];
				new_cell.second = current_cell.second + dy[dir];

				if (new_cell.first >= 0 && new_cell.first < 5 && new_cell.second >= 0 && new_cell.second < 5)
				{
					int new_val = arr[new_cell.first][new_cell.second].get_val() % 18;
					if (!direct[new_val][dir ^ 1])
						continue;
					if (check[new_cell.first][new_cell.second])
						continue;
					q.push(new_cell);
					check[new_cell.first][new_cell.second] = true;
				}

			}
		}
	}

	//Update water of each cell
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (check[i][j])
				arr[i][j].set_watered(true);
			else
				arr[i][j].set_watered(false);
}
int Board5x5::score()
{
	int score = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[i][j].get_watered())
				score++;
	return score;
}
