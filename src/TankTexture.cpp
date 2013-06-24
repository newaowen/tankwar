/*
 * {file_name}
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "TankTexture.h"

TankTexture::TankTexture() {
	startX = 32;
	startY = 32;
	sliceWidth = 32;
	sliceHeight = 32;
}

SDL_Rect TankTexture::computeSliceRect(TextureSliceIndex sliceIndex) {
	SDL_Rect rect;

	// 注意计算边框厚度
	rect.x = startX + 1 + sliceIndex.i * (sliceWidth + 1);
	rect.y = startY + 1 + sliceIndex.j * (sliceHeight + 1);
	rect.w = sliceWidth;
	rect.h = sliceHeight;

	Log::i("compute slice rect: x[%d] y[%d] w[%d] h[%d]", rect.x, rect.y,
			rect.w, rect.h);

	return rect;
}
