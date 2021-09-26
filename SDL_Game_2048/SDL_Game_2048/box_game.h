
#ifndef BOX_GAME_H_
#define BOX_GAME_H_

#include "commonFunc.h"
#include "load_photo.h"
#include "Load_text.h"

class box
{
public:
	box();
	~box();

	void draw_square(SDL_Renderer* gRenderer, SDL_Rect new_Rect, Uint8 red, Uint8 green, Uint8 blue);
	void setRect(SDL_Rect& new_Rect, int _x, int _y, int _w, int _h);
	void setup_board(SDL_Renderer* gRenderer, int board_game[][SIZE_GAME]);
	void setup_board_bg(SDL_Renderer* gRenderer);
	void view_board( SDL_Renderer* gRenderer, int board_game[][SIZE_GAME]);
	void view_menu(SDL_Renderer* gRenderer);
	void free();


	SDL_Rect getRect() { return square_rect; }

private:
	SDL_Rect square_rect;
	LTexture box_number;
	TextObj menu_2048;
	
};
#endif // !BOX_GAME_H_
