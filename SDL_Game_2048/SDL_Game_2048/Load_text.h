
#ifndef LOAD_TEXT_H
#define LOAD_TEXT_H

#include "commonFunc.h"
#include "logic_game.h"

class TextObj
{
public:
	TextObj();
	~TextObj();

	enum text_color
	{
		RED_TEXT = 0,
		WHILE_TEXT = 1,
		BLACK_TEXT = 2,
		BROWN_TEXT = 3,
	};

	bool loadFromRenderText(TTF_Font* t_font, SDL_Renderer* gRenderer);
	void free();
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetColor(int type);
	void RenderText(SDL_Renderer* gRenderer, int xp, int yp, SDL_Rect* clip = NULL);
	void setText(const string& text) { str_val = text; }
	void write_number(TTF_Font* gFont, SDL_Renderer* gRenderer, _logic _game, int xp, int yp, int write_number);

	int getWidth() { return t_width; }
	int getHeight() { return t_height; }
	string GetText() const { return str_val; }

private:
	string str_val;
	SDL_Color text_color_;
	SDL_Texture* t_texture;
	int t_width;
	int t_height;
};


#endif // !LOAD_TEXT_H

