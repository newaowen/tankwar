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

Sprite::Sprite(SDL_Rect rect, Texture* tex) {
    this->texture = tex;
    this->rect = rect;
}

void Sprite::draw() { 
    glBindTexture(GL_TEXTURE_2D, texture->getId());
    float vertices[] = {
        rect.x, rect.y,
        rect.x, rect.y + rect.h,
        rect.x + rect.w, rect.y + rect.h,
        rect.x + rect.w, rect.y
    };
    // texture cood
    float fac_x = (float)texture->getSliceWidth() / texture->getWidth();
    float fac_y = (float)texture->getSliceHeight() / texture->getHeight();
    float off_x = (float)texture->getX() / texture->getWidth();
    float off_y = (float)texture->getY() / texture->getHeight();

    float texturecoords[] = {
        off_x, off_y,
        off_x, fac_y + off_y,
        fac_x + off_x, fac_y + off_y,
        fac_x + off_x, off_y
    };

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, texturecoords);
    glDrawArrays(GL_QUADS, 0, 4);
}

}
