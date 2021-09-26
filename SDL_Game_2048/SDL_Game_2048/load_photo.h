
#ifndef LOAD_PHOTO_H_
#define LOAD_PHOTO_H_

#include "commonFunc.h"

class LTexture
{
public:
	LTexture();
	~LTexture();

	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);
	void free();
	void setRect( int _x, int _y, int _w , int _h);
	void render(SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);
	void render_F(int x, int y,SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	SDL_Rect getRect();
	int getWidth();
	int getHeight();

private:
	SDL_Texture* mTexture;
	SDL_Rect _rect;
	int mWidth;
	int mHeight;
};

#endif // !LOAD_PHOTO_H_




