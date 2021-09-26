
#include "Load_text.h"

TextObj::TextObj()
{
	text_color_.r = 255;
	text_color_.g = 255;
	text_color_.b = 255;

	t_texture = NULL;
}

TextObj::~TextObj()
{

}

bool TextObj::loadFromRenderText( TTF_Font* t_font, SDL_Renderer* gRenderer)
{
	SDL_Surface* t_surface = TTF_RenderText_Solid(t_font, str_val.c_str(), text_color_);
	if (t_surface)
	{
		t_texture = SDL_CreateTextureFromSurface(gRenderer, t_surface);
		t_width = t_surface->w;
		t_height = t_surface->h;

		SDL_FreeSurface(t_surface);
	}

	return t_texture != NULL;
}

void TextObj::free()
{
	if (t_texture != NULL)
	{
		SDL_DestroyTexture(t_texture);
		t_texture = NULL;
	}
}

void TextObj::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	text_color_.r = red;
	text_color_.g = green;
	text_color_.b = blue;
}

void TextObj::SetColor(int type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color_ = { 255 ,0 ,0 };
		text_color_ = color_;
	}else
	if (type == WHILE_TEXT)
	{
		SDL_Color color_ = { 255 ,255 ,255 };
		text_color_ = color_;
	}else
	if (type == BLACK_TEXT)
	{
		SDL_Color color_ = { 0 ,0 ,0 };
		text_color_ = color_;
	}else
	if (type == BROWN_TEXT)
	{
		SDL_Color color_ = { 100 ,0 ,0 };
		text_color_ = color_;
	}
}

void TextObj::RenderText(SDL_Renderer* gRenderer, int xp, int yp, SDL_Rect* clip /*= NULL*/)
{
	SDL_Rect renderQuad = { xp, yp, t_width, t_height };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, t_texture, clip, &renderQuad);
}

void TextObj::write_number(TTF_Font* gFont, SDL_Renderer* gRenderer, _logic _game, int xp, int yp, int write_number)
{
	SetColor(TextObj::BROWN_TEXT);
	setText(to_string(write_number));
	loadFromRenderText(gFont, gRenderer);
	RenderText(gRenderer, xp, yp);

}