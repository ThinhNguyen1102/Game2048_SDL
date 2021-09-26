#include "load_photo.h"

LTexture::LTexture()
{
	mTexture = NULL;
	_rect.x = 0;
	_rect.y = 0;
	_rect.w = 0;
	_rect.h = 0;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* gRenderer)
{
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			_rect.w = loadedSurface->w;
			_rect.h = loadedSurface->h;
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::render_F(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		_rect.w = 0;
		_rect.h = 0;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(SDL_Renderer* gRenderer, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { _rect.x, _rect.y, _rect.w, _rect.h };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

SDL_Rect LTexture::getRect()
{
	return _rect;
}
int LTexture::getWidth()
{
	return mWidth;
}
int LTexture::getHeight()
{
	return mHeight;
}

void LTexture::setRect(int _x, int _y, int _w, int _h)
{
	_rect.x = _x;
	_rect.y = _y;
	_rect.w = _w;
	_rect.h = _h;
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}