#include "box_game.h"


box::box()
{
	square_rect.x = 0;
	square_rect.y = 0;
	square_rect.w = 0;
	square_rect.h = 0;
}

box::~box() { ; }
void box::draw_square(SDL_Renderer* gRenderer, SDL_Rect new_Rect, Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetRenderDrawColor(gRenderer, red, green, blue, 255);
	SDL_RenderFillRect(gRenderer, &new_Rect);
}

void box::setRect(SDL_Rect& new_Rect, int _x, int _y, int _w, int _h)
{
	new_Rect.x = _x;
	new_Rect.y = _y;
	new_Rect.w = _w;
	new_Rect.h = _h;
}

void box::setup_board_bg(SDL_Renderer* gRenderer)
{
	SDL_SetRenderDrawColor(gRenderer, 240, 240, 215, 255);
	SDL_RenderClear(gRenderer);

	box_number.loadFromFile("photo/bg_play_.png", gRenderer);
	box_number.setRect(0, 0, 480, 640);
	box_number.render(gRenderer);

	setRect(square_rect, BORDER_BOARD_OUT, BORDER_BOARD_UP, SIZE_BOARD, SIZE_BOARD);
	draw_square(gRenderer, square_rect, 176, 165, 145);

	setRect(square_rect, 240, 10, 105, 60);
	draw_square(gRenderer, square_rect, 176, 165, 145);

	setRect(square_rect, 355, 10, 105, 60);
	draw_square(gRenderer, square_rect, 176, 165, 145);

	box_number.loadFromFile("photo/newgame.png", gRenderer);
	box_number.setRect(290, 100, 170, 50);
	box_number.render(gRenderer);

	int x = 0, y = 0;

	for (int i = 0; i < SIZE_GAME; i++)
	{
		for (int j = 0; j < SIZE_GAME; j++)
		{
			x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
			y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
			setRect(square_rect, x, y, WIDTH_SQUARE, WIDTH_SQUARE);
			draw_square(gRenderer, square_rect, 220, 200, 180);
		}
	}
}
void box::setup_board(SDL_Renderer* gRenderer, int board_game[][SIZE_GAME])
{
	box::setup_board_bg(gRenderer);
	int tile[SIZE_GAME];
	srand(time(NULL));

	tile[0] = rand() % SIZE_GAME;
	tile[1] = rand() % SIZE_GAME;

	do
	{
		tile[2] = rand() % SIZE_GAME;
		tile[3] = rand() % SIZE_GAME;
	} while (tile[0] == tile[2] && tile[1] == tile[3]);

	board_game[tile[0]][tile[1]] = 2;
	board_game[tile[2]][tile[3]] = 2;
}

void box::view_menu(SDL_Renderer* gRenderer)
{

	int x1 = (SCREEN_WIDTH - 180) / 2, y1 = 300;
	int x2 = x1, y2 = y1 + 60 + 20;
	int x3 = x1, y3 = y2 + 60 + 20;
	SDL_SetRenderDrawColor(gRenderer, 240, 240, 215, 255);
	SDL_RenderClear(gRenderer);

	box_number.loadFromFile("photo/bg_menu.png", gRenderer);
	box_number.setRect(0, 0, 480, 640);
	box_number.render(gRenderer);

	box_number.loadFromFile("photo/menu_play2.png", gRenderer);
	box_number.setRect(x1, y1, 180, 60);
	box_number.render(gRenderer);

	box_number.loadFromFile("photo/menu_quit2.png", gRenderer);
	box_number.setRect(x2, y2, 180, 60);
	box_number.render(gRenderer);

	box_number.loadFromFile("photo/menu_htp.png", gRenderer);
	box_number.setRect(x3, y3, 180, 60);
	box_number.render(gRenderer);


	SDL_RenderPresent(gRenderer);
}

void box::view_board(SDL_Renderer* gRenderer, int board_game[][SIZE_GAME])
{
	int x = 0, y = 0;

	for (int i = 0; i < SIZE_GAME; i++)
	{
		for (int j = 0; j < SIZE_GAME; j++)
		{

			if (board_game[i][j] == 0)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				setRect(square_rect, x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				draw_square(gRenderer, square_rect, 220, 200, 180);
			}
			else if (board_game[i][j] == 2)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_2_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 4)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_4_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 8)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_8_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 16)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_16_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 32)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_32_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 64)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_64_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 128)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_128_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 256)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_256_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 512)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_512_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 1024)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_1024_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
			else if (board_game[i][j] == 2048)
			{
				x = (BORDER_BOARD_IN + BORDER_BOARD_OUT) + j * (BORDER + WIDTH_SQUARE);
				y = (BORDER_BOARD_UP + BORDER_BOARD_IN) + i * (BORDER + WIDTH_SQUARE);
				box_number.loadFromFile("photo/so_2048_.png", gRenderer);
				box_number.setRect(x, y, WIDTH_SQUARE, WIDTH_SQUARE);
				box_number.render(gRenderer);
			}
		}
	}
}

void box::free()
{
	box_number.free();
	menu_2048.free();
}