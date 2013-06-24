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

#include "Log.h"

using namespace std;

namespace Tengine {

struct TextureSliceIndex  {
        int i, j;
};

class Texture {
public:
    SDL_Surface* surface;
    GLuint id;
    // 纹理源矩形
    SDL_Rect  rect;
public:
    virtual ~Texture();
    virtual void load(string fileName);
    virtual void toOpenGLTexture(SDL_Surface* surface);

    virtual GLuint getId();
    GLuint setId();

    inline SDL_Surface* getSurface() {return surface;};

    void buildFrom(Texture* tex, int x, int y, int w, int h);

    int getX() { return rect.x;}
    int getY() { return rect.y;}
    int getWidth() { return rect.w;}
    int getHeight() { return rect.h;}
    //virtual int getSliceWidth() { return width;}
    //virtual int getSliceHeight() { return height;}

    // 生成子块纹理
    Texture* genSlice(int x, int y, int width, int height);
    Texture* genSlice(SDL_Rect rect);
    Texture* genSlice(TextureSliceIndex sliceIndex);

    // 根据索引计算纹理矩形(子类具体实现）
    virtual SDL_Rect computeSliceRect(TextureSliceIndex sliceIndex);

};

} 

#endif 
