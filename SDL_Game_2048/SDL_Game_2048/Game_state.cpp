#include "Game_state.h"


state::state()
{
	Mix_Chunk* Beat_move = NULL;

	bool quit_menu = false;
	bool replay = false;
	bool checkMove = false;
}
state::~state() {  }

void state::state_button_menu(LButton mouse_event[3], SDL_Renderer* gRenderer)
{
	if (mouse_event[0].getSprite() == BUTTON_SPRITE_MOUSE_OVER_MOTION)
	{
		menu_click.loadFromFile("photo/menu_play_.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}
	else
	{
		menu_click.loadFromFile("photo/menu_play2.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}

	if (mouse_event[1].getSprite() == BUTTON_SPRITE_MOUSE_OVER_MOTION)
	{
		menu_click.loadFromFile("photo/menu_quit_.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy + BUTTON_MENU_HEIGHT + DISTANCE_BUTTON, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}
	else
	{
		menu_click.loadFromFile("photo/menu_quit2.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy + BUTTON_MENU_HEIGHT + DISTANCE_BUTTON, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}

	if (mouse_event[2].getSprite() == BUTTON_SPRITE_MOUSE_OVER_MOTION)
	{
		menu_click.loadFromFile("photo/menu_htp_.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy + (BUTTON_MENU_HEIGHT + DISTANCE_BUTTON) * 2, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}
	else
	{
		menu_click.loadFromFile("photo/menu_htp.png", gRenderer);
		menu_click.setRect(BUTTON_MENU_Ox, BUTTON_MENU_Oy + (BUTTON_MENU_HEIGHT + DISTANCE_BUTTON) * 2, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
		menu_click.render(gRenderer);
		SDL_RenderPresent(gRenderer);
	}
}


void state::back_htp(LButton mouse_event_back, SDL_Renderer* gRenderer, LTexture howToPlay, box game, bool &quit)
{
	bool back = false;
	while (!back)
	{
		int Pos_click_back_x = 0;
		int Pos_click_back_y = 580;
		mouse_event_back.setPosition(Pos_click_back_x, Pos_click_back_y);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				back = true;
				quit_menu = true;
				quit = true;
				game.view_menu(gRenderer);
				mouse_event[2].set_CurrentSprite();
			}

			int Pos_click_back_w = 43;
			int Pos_click_back_h =60;
			mouse_event_back.handleEvent(&e, Pos_click_back_w, Pos_click_back_h);
		}

		howToPlay.loadFromFile("photo/bg_htp.png", gRenderer);
		howToPlay.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		howToPlay.render(gRenderer);
		SDL_RenderPresent(gRenderer);

		if (mouse_event_back.getSprite() == BUTTON_SPRITE_MOUSE_DOWN)
		{
			back = true;
			game.view_menu(gRenderer);
			mouse_event[2].set_CurrentSprite();
		}
	}
}


void state::MENU(SDL_Renderer* gRenderer, bool &quit, bool &playplay, box game)
{
	quit_menu = false;
	while (!quit_menu)
	{
		mouse_event[0].setPosition(BUTTON_MENU_Ox, BUTTON_MENU_Oy);
		mouse_event[1].setPosition(BUTTON_MENU_Ox, BUTTON_MENU_Oy + BUTTON_MENU_HEIGHT + DISTANCE_BUTTON);
		mouse_event[2].setPosition(BUTTON_MENU_Ox, BUTTON_MENU_Oy + (BUTTON_MENU_HEIGHT + DISTANCE_BUTTON) * 2);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit_menu = true;
			}

			for (int i = 0; i < 3; i++)
			{
				mouse_event[i].handleEvent(&e, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT);
			}

		}

		state_button_menu(mouse_event, gRenderer);
		if (mouse_event[0].getSprite() == BUTTON_SPRITE_MOUSE_DOWN)
		{
			playplay = true;
			quit_menu = true;
		}
		if (mouse_event[1].getSprite() == BUTTON_SPRITE_MOUSE_DOWN)
		{
			playplay = false;
			quit_menu = true;
		}
		
		if (mouse_event[2].getSprite() == BUTTON_SPRITE_MOUSE_DOWN)
		{
			back_htp(mouse_event_back, gRenderer, howToPlay, game, quit);
		}

	}
}
void state::GAMEOVER(SDL_Renderer* gRenderer, TTF_Font* gFont, int board_game[][SIZE_GAME],
				box &game, bool &quit,TextObj gameScore_text, _logic _game)
{
		back_g_gameover.loadFromFile("photo/bg_gameOver.png", gRenderer);
		back_g_gameover.setBlendMode(SDL_BLENDMODE_BLEND);

		text_gameover.loadFromFile("photo/game_over_.png", gRenderer);
		text_gameover.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);


		game.setup_board_bg(gRenderer);
		game.view_board(gRenderer, board_game);

		GAME_SCORE(gRenderer, gFont, gameScore_text, _game);

		back_g_gameover.setAlpha(150);
		back_g_gameover.render(gRenderer);
		text_gameover.render(gRenderer);
		SDL_RenderPresent(gRenderer);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_r:
					replay = true;
					break;
				case SDLK_q:
					quit = true;
					break;
				}
			}
		}
}
void state::REPLAY(SDL_Renderer* gRenderer, _logic &_game, box &game, int board_game[][SIZE_GAME])
{
	if (replay == true)
	{
		_game.set_replay(board_game);
		game.setup_board(gRenderer, board_game);
		replay = false;
	}
}
void state::GAMEPLAY(SDL_Renderer* gRenderer, int board_game[][SIZE_GAME], _logic &_game, bool &quit, bool &checkMove)
{
	
	Beat_move = Mix_LoadWAV("music/beat_move.wav");

	int Pos_click_newgame_x = 290;
	int Pos_click_newgame_y = 100;
	int Pos_click_newgame_w = 170;
	int Pos_click_newgame_h = 50;

	mouse_event_newgame.setPosition(Pos_click_newgame_x, Pos_click_newgame_y);

	while (SDL_PollEvent(&e) != 0)
	{
		mouse_event_newgame.handleEvent(&e, Pos_click_newgame_w, Pos_click_newgame_h);

		if (mouse_event_newgame.getSprite() == BUTTON_SPRITE_MOUSE_OVER_MOTION)
		{
			menu_click.loadFromFile("photo/newgame_.png", gRenderer);
			menu_click.setRect(Pos_click_newgame_x, Pos_click_newgame_y, Pos_click_newgame_w, Pos_click_newgame_h);
			menu_click.render(gRenderer);
			SDL_RenderPresent(gRenderer);
		}
		else
		{
			menu_click.loadFromFile("photo/newgame.png", gRenderer);
			menu_click.setRect(Pos_click_newgame_x, Pos_click_newgame_y, Pos_click_newgame_w, Pos_click_newgame_h);
			menu_click.render(gRenderer);
			SDL_RenderPresent(gRenderer);
		}

		if (mouse_event_newgame.getSprite() == BUTTON_SPRITE_MOUSE_DOWN) replay = true;

		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			_game.create_check(board_game);
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				_game.key_up(board_game);
				Mix_PlayChannel(-1, Beat_move, 0);
				checkMove = true;
				break;
			case SDLK_DOWN:
				_game.key_down(board_game);
				Mix_PlayChannel(-1, Beat_move, 0);
				checkMove = true;
				break;
			case SDLK_LEFT:
				_game.key_left(board_game);
				Mix_PlayChannel(-1, Beat_move, 0);
				checkMove = true;
				break;
			case SDLK_RIGHT:
				_game.key_right(board_game);
				Mix_PlayChannel(-1, Beat_move, 0);
				checkMove = true;
				break;

			}
		}

	}
}

void state::GAME_SCORE(SDL_Renderer* gRenderer, TTF_Font* gFont, TextObj gameScore_text, _logic _game)
{
	
	int Pos_board_score_x = 240;
	int Pos_board_score_x_best = 355;
	int Pos_board_score_y = 10;
	int Pos_board_score_w = 105;
	int Pos_board_score_h = 60;

	Score_board.loadFromFile("photo/score_board_.png", gRenderer);
	Score_board.setRect(Pos_board_score_x, Pos_board_score_y, Pos_board_score_w, Pos_board_score_h);
	Score_board.render(gRenderer);

	Score_board.loadFromFile("photo/best_board_.png", gRenderer);
	Score_board.setRect(Pos_board_score_x_best, Pos_board_score_y, Pos_board_score_w, Pos_board_score_h);
	Score_board.render(gRenderer);

	int Pos_text_score_x = 270;
	int Pos_text_score_x_best = 380;
	int Pos_text_score_y = 30;
	int size_score = 35;

	gFont = TTF_OpenFont("photo/SVN-Bali Script.ttf", size_score);
	gameScore_text.write_number(gFont, gRenderer, _game, Pos_text_score_x, Pos_text_score_y, _game.getScore());
	gFont = TTF_OpenFont("photo/SVN-Bali Script.ttf", size_score);
	gameScore_text.write_number(gFont, gRenderer, _game, Pos_text_score_x_best, Pos_text_score_y, _game.bestScore());

	//SDL_RenderPresent(gRenderer);
}


void state::free()
{
	Mix_FreeChunk(Beat_move);
	Beat_move = NULL;

	menu_click.free();
	back_g_gameover.free();
	howToPlay.free();
	Score_board.free();
	text_gameover.free();
}