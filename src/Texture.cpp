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

template <class T>
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
        glDeleteTextures(1, &id);
    }
}

void Texture::load(string fileName) {
    const char* path = fileName.c_str();
    SDL_Surface *rawSurface = IMG_Load(path);
    if (rawSurface) {
    	surface = SDL_DisplayFormat(rawSurface);
    	if (surface) {
    		SDL_FreeSurface(rawSurface);
    	}
    	//toOpenGLTexture(surface);
        // Free the SDL_Surface only if it was successfully created
        //if (surface) {
        //    SDL_FreeSurface( surface );
        //}
    } else {
        printf("SDL could not load %s: %s\n", path, SDL_GetError());
    }    
}

void Texture::toOpenGLTexture(SDL_Surface* surface) {
    // Check that the image's width is a power of 2
    if ((surface->w & (surface->w - 1)) != 0) {
        printf("warning: surface width is not a power of 2\n");
    }
    // Also check if the height is a power of 2
    if ((surface->h & (surface->h - 1)) != 0 ) {
        printf("warning: surface height is not a power of 2\n");
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

    width = surface->w;
    height = surface->h;
}

GLuint Texture::getId() {
    return id;
}

Texture* Texture::slice(int x, int y, int width, int height) {
    return new TextureSlice(this, x, y, width, height);     
}

TextureSlice::TextureSlice(Texture* tex, int x, int y, int width, int height) {
    this->parent = tex;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

GLuint TextureSlice::getId() {
    return parent->getId();
}

}
