/*
 * =====================================================================================
 *
 *       Filename:  Sprite.h
 *
 *    Description:  2d sprite
 *
 *        Version:  1.0
 *        Created:  2012年10月31日 20时09分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _SPRITE_
#define _SPRITE_

#include "Texture.h"

namespace Tengine {

class Sprite {
private:
    Texture* texture;   
    SDL_Rect rect;
public:
    Sprite(SDL_Rect rect, Texture* tex);
    void setTexture(Texture* tex);
    void draw();
};

} 

#endif
