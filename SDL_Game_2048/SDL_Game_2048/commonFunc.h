
#ifndef COMMONFUNC_H_
#define COMMONFUNC_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;
const int SIZE_GAME = 10;
const int SIZE_BOARD = 440;
const int BORDER_BOARD_IN = 10;
const int WIDTH_SQUARE = 96 * 4 / SIZE_GAME;
const int BORDER = ((SIZE_BOARD - WIDTH_SQUARE*SIZE_GAME) - BORDER_BOARD_IN *2)/(SIZE_GAME - 1);
const int BORDER_BOARD_OUT = (SCREEN_WIDTH - SIZE_BOARD) / 2;
const int BORDER_BOARD_UP = (SCREEN_HEIGHT - BORDER_BOARD_OUT - SIZE_BOARD);



enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

#endif // COMMON_H_
