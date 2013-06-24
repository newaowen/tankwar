/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  sprite
 *
 *        Version:  1.0
 *        Created:  2012年10月31日 23时01分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Sprite.h"

namespace Tengine {

/**
 * 以贴图中某矩形区域初始化sprite
 */
void Sprite::build(Texture* tex, SDL_Rect rect) {
	// random number
	id = "xxx";
	texture = tex;
	x = rect.x;
	y = rect.y;
	w = rect.w;
	h = rect.h;
}

void Sprite::blitTexture(Texture* tex, SDL_Rect* rect) {
	SDL_Rect src = tex->rect;
	SDL_Rect dest = *rect;
	//Log::i("blit surface: from (%d, %d, %d, %d) to (%d, %d, %d, %d)", src.x, src.y, src.w, src.h,
	//		dest.x, dest.y, dest.w, dest.h);
	SDL_BlitSurface(tex->getSurface(), &(tex->rect), screen, rect);
}

/**
 * pending
 * 使用贴图大小表示精灵大小
 */
void Sprite::useTextureSize() {
	if (texture) {
		w = texture->rect.w;
		h = texture->rect.h;
	}
}

void Sprite::draw() {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	blitTexture(texture, &dest);

	/*
	 //glBindTexture(GL_TEXTURE_2D, texture->getId());
	 float vertices[] = { rect.x, rect.y, rect.x, rect.y + rect.h, rect.x
	 + rect.w, rect.y + rect.h, rect.x + rect.w, rect.y };

	 // texture cood
	 float fac_x = (float) texture->getSliceWidth() / texture->getWidth();
	 float fac_y = (float) texture->getSliceHeight() / texture->getHeight();
	 float off_x = (float) texture->getX() / texture->getWidth();
	 float off_y = (float) texture->getY() / texture->getHeight();

	 float textureCoords[] = { off_x, off_y, off_x, fac_y + off_y, fac_x + off_x,
	 fac_y + off_y, fac_x + off_x, off_y };

	 SDL_Rect dest;
	 dest.x = rect.x;
	 dest.y = rect.y;
	 dest.w = rect.w; //texture->getSliceWidth();
	 dest.h = rect.h; //texture->getSliceHeight();

	 // 获取game surface
	 SDL_BlitSurface(texture->getSurface(), &rect, screen, &dest);

	 //　使用sdl显示图片
	 //SDL_blit();
	 //glVertexPointer(2, GL_FLOAT, 0, vertices);
	 //glTexCoordPointer(2, GL_FLOAT, 0, texturecoords);
	 //glDrawArrays(GL_QUADS, 0, 4);
	 */
}

}
