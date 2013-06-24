/*
 * tank 实现
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "Tank.h"

// tank播放动画
void Tank::move() {

}

void Tank::turn() {

}

void Tank::draw() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	// 坦克的位置，朝向，速度等计算

	// 动画控制器计算当前纹理片段

	TextureSliceIndex sliceIndex = animator->getCurSliceIndex();
	//SDL_Rect sliceRect = texture->getSliceRect();
	Texture* tex = texture->genSlice(sliceIndex);
	// 显示坦克
	blitTexture(tex, &rect);
	//SDL_BlitSurface(texture->getSurface(), &sliceRect, screen, &rect);
}
