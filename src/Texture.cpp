/*
 * =====================================================================================
 *
 *       Filename:  Texture.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月31日 21时24分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Texture.h"

/**
 * 指数计算
 */
template<class T>
T next_power_of_two(T value) {
	if ((value & (value - 1)) == 0)
		return value;
	value -= 1;
	for (size_t i = 1; i < sizeof(T) * 8; i <<= 1)
		value = value | value >> i;
	return value + 1;
}

namespace Tengine {

Texture::~Texture() {
	if (id) {
		//glDeleteTextures(1, &id);
	}
}

void Texture::load(string fileName) {
	const char* path = fileName.c_str();
	SDL_Surface *rawSurface = IMG_Load(path);
	if (rawSurface) {
		Log::i("load texture %s success", path);
		surface = SDL_DisplayFormat(rawSurface);
		if (surface) {
			Log::i("texture %s to sdl_display format success", path);
			SDL_FreeSurface(rawSurface);
		}
		//toOpenGLTexture(surface);
		// Free the SDL_Surface only if it was successfully created
		//if (surface) {
		//    SDL_FreeSurface( surface );
		//}
	} else {
		Log::e("SDL could not load %s: %s\n", path, SDL_GetError());
	}
}

/**
 * @deprecated
 */
void Texture::toOpenGLTexture(SDL_Surface* surface) {
	// Check that the image's width is a power of 2
	if ((surface->w & (surface->w - 1)) != 0) {
		Log::w("warning: surface width is not a power of 2");
	}
	// Also check if the height is a power of 2
	if ((surface->h & (surface->h - 1)) != 0) {
		Log::w("warning: surface width is not a power of 2");
	}

	/*
	 // SDL_Surface 转换为opengl surface
	 GLenum texture_format;
	 GLint  nOfColors = surface->format->BytesPerPixel;
	 if (nOfColors == 4)     // contains an alpha channel
	 {
	 if (surface->format->Rmask == 0x000000ff)
	 texture_format = GL_RGBA;
	 else
	 texture_format = GL_BGRA;
	 } else if (nOfColors == 3)     // no alpha channel
	 {
	 if (surface->format->Rmask == 0x000000ff)
	 texture_format = GL_RGB;
	 else
	 texture_format = GL_BGR;
	 } else {
	 printf("warning: the image is not truecolor..  this will probably break\n");
	 // this error should not go
	 // unhandled
	 }

	 // Have OpenGL generate a texture object handle for us
	 glEnable(GL_TEXTURE_2D);
	 glGenTextures(1, &id);
	 glBindTexture(GL_TEXTURE_2D, id);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	 // Edit the texture object's image data using the information SDL_Surface
	 glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);
	 */

	rect.w = surface->w;
	rect.h = surface->h;
}

GLuint Texture::getId() {
	return id;
}

Texture* Texture::genSlice(int x, int y, int w, int h) {
	Texture* tex = new Texture();
	tex->buildFrom(this, x, y, w, h);
	return tex;
}

Texture* Texture::genSlice(SDL_Rect rect) {
	Texture* tex = new Texture();
	tex->buildFrom(this, rect.x, rect.y, rect.w, rect.h);
	return tex;
}

// 根据索引生成子快纹理
Texture* Texture::genSlice(TextureSliceIndex sliceIndex) {
	SDL_Rect rect = computeSliceRect(sliceIndex);
	return genSlice(rect);
}

// 根据索引计算纹理矩形(子类具体实现）
SDL_Rect Texture::computeSliceRect(TextureSliceIndex sliceIndex) {
	SDL_Rect rect = this->rect;
	return rect;
}

/**
 * 构建纹理
 */
void Texture::buildFrom(Texture* tex, int x, int y, int w, int h) {
	surface = tex->surface;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

}
