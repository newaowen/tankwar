/*
 * tank 实现
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "Tank.h"

/**
 * 移动
 */
void Tank::move() {

}

/**
 * 转向
 */
void Tank::turn() {

}

/**
 * 事件处理
 */
void Tank::handleEvent(SDL_Event event) {
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			break;
		case SDLK_RIGHT:
			break;
		case SDLK_DOWN:
			break;
		case SDLK_LEFT:
			break;
		default:
			break;
		}
		break;
		default:
			break;
	}
}

void Tank::draw() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	// 坦克的位置，朝向，速度等计算

	// 动画控制器计算当前纹理片段
	animator->update();
	TextureSliceIndex sliceIndex = animator->getCurSliceIndex();
	Texture* tex = texture->genSlice(sliceIndex);
	Log::i("blit surface: from (%d, %d, %d, %d)", rect.x, rect.y, rect.w, rect.h);
	// 显示坦克
	blitTexture(tex, &rect);
}
