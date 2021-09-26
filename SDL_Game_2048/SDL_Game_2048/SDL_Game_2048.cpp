#include "logic_game.h"
#include "load_photo.h"
#include "box_game.h"
#include "commonFunc.h"
#include "Mouse_button.h"
#include "Load_text.h"
#include "Game_state.h"
bool init();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font* gFont = NULL;
Mix_Music* gMusic = NULL;
Mix_Chunk* Beat_move = NULL;
int board_game[SIZE_GAME][SIZE_GAME] = { 0 };

TextObj gameScore_text;

_logic _game;
box game;
box menu;

state game2048;


#include "setup_game.h"

int main(int argc, char* argv[])
{

	if (!init()) return -1;
	else
	{

		bool quit = false;
		bool playplay = false;
		menu.view_menu(gRenderer);
		game2048.MENU(gRenderer, quit, playplay, game);

		if (playplay)
		{
			SDL_SetRenderDrawColor(gRenderer, 240, 240, 215, 255);
			SDL_RenderClear(gRenderer);
			game.setup_board(gRenderer, board_game);

			loadImage();
		
			while (!quit)
			{
				bool ok = false;
				if (_game.getScore() > _game.bestScore())
				{
					_game.write_bestScore(_game.getScore());
				}

				game2048.REPLAY(gRenderer, _game, game, board_game);

				if (_game.check_game_over(board_game))
				{
					game2048.GAMEOVER(gRenderer,gFont, board_game, game, quit, gameScore_text, _game);
				}
				else
				{
					bool checkMove = false;

					game2048.GAMEPLAY(gRenderer, board_game, _game, quit, checkMove);

					game.view_board(gRenderer, board_game);

					game2048.GAME_SCORE(gRenderer, gFont, gameScore_text, _game);

					if (_game.check_move(board_game) == false) continue;
					if (checkMove)
					{
						_game.add_val(board_game);
					}

					SDL_RenderPresent(gRenderer);

				}

			}
		}
	}

	close();

	return 0;
}
