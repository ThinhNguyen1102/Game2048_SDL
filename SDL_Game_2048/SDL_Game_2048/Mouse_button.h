#ifndef MOUSE_BUTTON_H
#define MOUSE_BUTTON_H

#include "commonFunc.h"

class LButton
{
public:
	LButton();

	void setPosition(int x, int y);
	void handleEvent(SDL_Event* e, int mWidth, int mHeight);
	LButtonSprite getSprite();
	void set_CurrentSprite();


private:
	SDL_Point mPosition;
	LButtonSprite mCurrentSprite;
};
#endif // !MOUSE_BUTTON_H

