/*
 * =====================================================================================
 *
 *       Filename:  Sprite.h
 *
 *    Description:  2d sprite
 *
 *        Version:  1.0
 *        Created:  2012年10月31日 20时09分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _SPRITE_
#define _SPRITE_

#include "Texture.h"
#include "DisplayObject.h"

namespace Tengine {

/**
 * 精灵基类
 */
class Sprite: public DisplayObject {
public:
	string id;
	// 屏幕引用
	SDL_Surface* screen;
	Texture* texture;

	// 精灵大小
	int w, h;
	// SDL_Rect textureRect;

public:
	Sprite() {
	}

	void build(Texture* tex, SDL_Rect rect);

	inline void attachScreen(SDL_Surface* screen) {
		this->screen = screen;
	}

	void draw();
	void blitTexture(Texture* tex, SDL_Rect* rect);
};

}

#endif
