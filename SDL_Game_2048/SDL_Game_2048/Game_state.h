#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "logic_game.h"
#include "load_photo.h"
#include "box_game.h"
#include "commonFunc.h"
#include "Mouse_button.h"
#include "Load_text.h"

class state
{
public:
	state();
	~state();
	void MENU(SDL_Renderer* gRenderer, bool &quit, bool &playplay, box game);
	void GAMEOVER(SDL_Renderer* gRenderer, TTF_Font* gFont, int board_game[][SIZE_GAME], box &game, bool &quit, TextObj gameScore_text, _logic _game);
	void REPLAY(SDL_Renderer* gRenderer, _logic &_game, box &game, int board_game[][SIZE_GAME]);
	void GAMEPLAY(SDL_Renderer* gRenderer, int board_game[][SIZE_GAME], _logic &_game, bool &quit, bool &checkMove);
	void state_button_menu(LButton mouse_event[3], SDL_Renderer* gRenderer);
	void GAME_SCORE(SDL_Renderer* gRenderer, TTF_Font* gFont, TextObj gameScore_text,_logic _game);
	void back_htp(LButton mouse_event_back, SDL_Renderer* gRenderer, LTexture howToPlay, box game, bool &quit);
	void free();

private:
	Mix_Chunk* Beat_move;

	LTexture menu_click;
	LTexture back_g_gameover;
	LTexture text_gameover;
	LTexture howToPlay;
	LTexture Score_board;


	LButton mouse_event[3];
	LButton mouse_event_back;
	LButton mouse_event_newgame;
	

	bool quit_menu;
	bool replay;
	SDL_Event e;

	const int BUTTON_MENU_WIDTH = 180;
	const int BUTTON_MENU_HEIGHT = 60;
	const int DISTANCE_BUTTON = 20;
	const int BUTTON_MENU_Oy = 300;
	const int BUTTON_MENU_Ox = (SCREEN_WIDTH - BUTTON_MENU_WIDTH) / 2;
};

#endif // !GAME_STATE_H

