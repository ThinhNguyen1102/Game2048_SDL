#include "Mouse_button.h"

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}
void LButton::handleEvent(SDL_Event * e, int mWidth, int mHeight)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < mPosition.x)
		{
			inside = false;
		}
		else if (x > mPosition.x + mWidth)
		{
			inside = false;
		}
		else if (y < mPosition.y)
		{
			inside = false;
		}
		else if (y > mPosition.y + mHeight)
		{
			inside = false;
		}
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
			
		else
		{
				
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}


LButtonSprite LButton::getSprite()
{
	return mCurrentSprite;
}

void LButton::set_CurrentSprite()
{
	mCurrentSprite = BUTTON_SPRITE_TOTAL;
}