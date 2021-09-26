#include "logic_game.h"

_logic::_logic() { ; }
_logic::~_logic() { ; }

void _logic::key_up(int board_game[][SIZE_GAME])
{
    for (int y = 0; y < SIZE_GAME; y++)
    {
        for (int x = 0; x < SIZE_GAME-1; x++)
        {
            for (int x1 = x + 1; x1 < SIZE_GAME; x1++)
            {
                if (board_game[x1][y] > 0)
                {
                    if (board_game[x][y] == 0)
                    {
                        board_game[x][y] = board_game[x1][y];
                        board_game[x1][y] = 0;
                        x--;
                    }
                    else if (board_game[x][y] == broad_check[x1][y])
                    {
                        board_game[x][y] *= 2;
                        board_game[x1][y] = 0;
                        game_score += board_game[x][y];

                    }
                    break;
                }
            }
        }
    }
}

void _logic::key_down(int board_game[][SIZE_GAME])
{
    for (int y = 0; y < SIZE_GAME; y++)
    {
        for (int x = SIZE_GAME-1; x >= 1; x--)
        {
            for (int x1 = x - 1; x1 >= 0; x1--)
            {
                if (board_game[x1][y] > 0)
                {
                    if (board_game[x][y] == 0)
                    {
                        board_game[x][y] = board_game[x1][y];
                        board_game[x1][y] = 0;
                        x++;
                    }
                    else if (board_game[x][y] == board_game[x1][y])
                    {
                        board_game[x][y] *= 2;
                        board_game[x1][y] = 0;
                        game_score += board_game[x][y];
                    }
                    break;
                }
            }
        }
    }
}
void _logic::key_left(int board_game[][SIZE_GAME])
{
    for (int x = 0; x < SIZE_GAME; x++)
    {
        for (int y = 0; y < SIZE_GAME-1; y++)
        {
            for (int y1 = y + 1; y1 < SIZE_GAME; y1++)
            {
                if (board_game[x][y1] > 0)
                {
                    if (board_game[x][y] == 0)
                    {
                        board_game[x][y] = board_game[x][y1];
                        board_game[x][y1] = 0;
                        y--;
                    }
                    else if (board_game[x][y] == board_game[x][y1])
                    {
                        board_game[x][y] *= 2;
                        board_game[x][y1] = 0;
                        game_score += board_game[x][y];
                    }
                    break;
                }
            }
        }
    }
}

void _logic::key_right(int board_game[][SIZE_GAME])
{
    for (int x = 0; x < SIZE_GAME; x++)
    {
        for (int y = SIZE_GAME - 1 ; y >= 1; y--)
        {
            for (int y1 = y - 1; y1 >= 0; y1--)
            {
                if (board_game[x][y1] > 0)
                {
                    if (board_game[x][y] == 0)
                    {
                        board_game[x][y] = board_game[x][y1];
                        board_game[x][y1] = 0;
                        y++;
                    }
                    else if (board_game[x][y] == board_game[x][y1])
                    {
                        board_game[x][y] *= 2;
                        board_game[x][y1] = 0;
                        game_score += board_game[x][y];
                    }
                    break;
                }
            }
        }
    }
}

void _logic::add_val(int board_game[][SIZE_GAME])
{
    if (check_zero(board_game) == false) return;
    int x, y;
    srand(time(NULL));

    do
    {
        x = rand() % SIZE_GAME;
        y = rand() % SIZE_GAME;
    } while (board_game[x][y] != 0);

    int s = rand() % 101;
    if (s > 90) board_game[x][y] = 4;
    else board_game[x][y] = 2;
}

void _logic::create_check(int board_game[][SIZE_GAME])
{
    for (int i = 0; i < SIZE_GAME; i++)
    {
        for (int j = 0; j < SIZE_GAME; j++)
        {
            broad_check[i][j] = board_game[i][j];
        }
    }

}
bool _logic::check_move(int board_game[][SIZE_GAME])
{
    for (int i = 0; i < SIZE_GAME; i++)
    {
        for (int j = 0; j < SIZE_GAME; j++)
        {
            if (broad_check[i][j] != board_game[i][j]) return true;
        }
    }

    return false;

}
bool _logic::check_zero(int board_game[][SIZE_GAME])
{
    for (int i = 0; i < SIZE_GAME; i++) {
        for (int j = 0; j < SIZE_GAME; j++) {
            if (board_game[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}
bool _logic::check_game_over(int board_game[][SIZE_GAME])
{
    for (int i = 0; i < SIZE_GAME; i++)
    {
        for (int j = 0; j < SIZE_GAME; j++)
        {
            if (i - 1 >= 0)
            {
                if (board_game[i - 1][j] == board_game[i][j])
                {
                    return false;
                }
            }

            if (i + 1 < SIZE_GAME)
            {
                if (board_game[i + 1][j] == board_game[i][j])
                {
                    return false;
                }
            }

            if (j - 1 >= 0)
            {
                if (board_game[i][j - 1] == board_game[i][j])
                {
                    return false;
                }
            }

            if (j + 1 < SIZE_GAME)
            {
                if (board_game[i][j + 1] == board_game[i][j])
                {
                    return false;
                }
            }

            if (board_game[i][j] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

int _logic::getScore()
{
    return game_score;
}

void _logic::set_replay(int board_game[][SIZE_GAME])
{
    for (int i = 0; i < SIZE_GAME; i++)
    {
        for (int j = 0; j < SIZE_GAME; j++)
        {
            board_game[i][j] = 0;
        }
    }
    game_score = 0;
}

void _logic::write_bestScore(int game_score)
{
    fstream fileScore;
    fileScore.open("score.txt", ios::out);
    fileScore << game_score;
    fileScore.close();
}


int _logic::bestScore()
{
    int score;
    fstream fileScore;
    fileScore.open("score.txt", ios::in);
    fileScore >> score;
    fileScore.close();
    return score;
}
