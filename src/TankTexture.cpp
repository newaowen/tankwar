/*
 * {file_name}
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "TankTexture.h"

TankTexture::TankTexture() {
	startX = 0;
	startY = 0;
}

SDL_Rect TankTexture::computeSliceRect(TextureSliceIndex sliceIndex) {
	SDL_Rect rect;

	// 注意计算边框厚度
	rect.x = startX + 1 + sliceIndex.i * (sliceWidth + 1);
	rect.y = startY + 1 + sliceIndex.j * (sliceHeight + 1);
	rect.w = sliceWidth;
	rect.h = sliceHeight;

	return rect;
}
