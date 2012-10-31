/*
 * =====================================================================================
 *
 *       Filename:  Texture.h
 *
 *    Description:  纹理图像（用来管理物体的图片)
 *
 *        Version:  1.0
 *        Created:  2012年10月29日 22时49分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _TEXTURE_
#define _TEXTURE_

#include <iostream>
#include <string>
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

namespace Tengine {

class Texture {
public:
    SDL_Surface* surface;
    GLuint id;
    int width;
    int height;
public:
    virtual ~Texture();
    virtual void load(string fileName);
    virtual void fromSDLSurface(SDL_Surface* surface);
    virtual Texture* slice(int x, int y, int width, int height);

    virtual GLuint getId();
    GLuint setId();

    virtual int getX() { return 0;}
    virtual int getY() { return 0;}
    virtual int getWidth() { return width;}
    virtual int getHeight() { return height;}
    virtual int getSliceWidth() { return width;}
    virtual int getSliceHeight() { return height;}
};


class TextureSlice : public Texture {
private:
    Texture* parent;
    int x, y;
public:
    TextureSlice(Texture* parent, int x, int y, int width, int height);
    ~TextureSlice() {}
    GLuint getId();

    int getX() {return x;}
    int getY() {return y;}
    int getWidth() { return parent->getWidth();}
    int getHeight() { return parent->getHeight();}
};

} 

#endif 
