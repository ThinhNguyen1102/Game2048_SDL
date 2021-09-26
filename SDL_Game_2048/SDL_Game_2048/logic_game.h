#pragma once
#ifndef LOGIC_GAME_H_
#define LOGIC_GAME_H_

#include "commonFunc.h"

class _logic
{
public:
	_logic();
	~_logic();

	void key_up(int board_game[][SIZE_GAME]);
	void key_down(int board_game[][SIZE_GAME]);
	void key_left(int board_game[][SIZE_GAME]);
	void key_right(int board_game[][SIZE_GAME]);

	void add_val(int board_game[][SIZE_GAME]);
	void create_check(int board_game[][SIZE_GAME]);
	bool check_move(int board_game[][SIZE_GAME]);
	bool check_game_over(int board_game[][SIZE_GAME]);
	bool check_zero(int board_game[][SIZE_GAME]);
	int getScore();
	void write_bestScore(int game_score);
	int bestScore();
	void set_replay(int board_game[][SIZE_GAME]);

	int broad_check[SIZE_GAME][SIZE_GAME] = { 0 };
	
private:
	int game_score = 0;
	bool replayGame = false;
};
#endif // !EVENT_GAME_H_
