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

#include "Constant.h"
#include "Texture.h"
#include "DisplayObject.h"

namespace Tengine {


/**
 * 精灵基类
 */
class Sprite: public DisplayObject {
public:
	string id;

	Texture* texture;

	// 屏幕引用
	//	SDL_Surface* screen;
	// 精灵大小
	int w, h;
	// 朝向
	Direction direction;
	// 速度
	float speed;
	// SDL_Rect textureRect;

public:
	Sprite() {}

	/*
	inline void attachScreen(SDL_Surface* screen) {
			this->screen = screen;
		}
	*/
	// 初始化参数
	void build(Texture* tex, SDL_Rect rect);

	// pending
	// 设置以贴图尺寸为准
	void useTextureSize();

	void draw();
	void blitTexture(Texture* tex, SDL_Rect* rect);
};

}

#endif
