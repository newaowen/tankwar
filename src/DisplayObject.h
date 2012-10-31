/*
 * =====================================================================================
 *
 *       Filename:  DisplayObject.h
 *
 *    Description:  可显示物体
 *
 *        Version:  1.0
 *        Created:  2012年10月25日 23时30分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _DISPLAY_OBJECT_
#define _DISPLAY_OBJECT_

#include <SDL/SDL.h>
#include "Sprite.h"
#include "Texture.h"

namespace Tengine {

typedef void (*DrawFunc)();
class DisplayObject {
public: 
    float x, y;
    bool  visible;
    Sprite*  sprite;
    DrawFunc drawFunc;
public:
    DisplayObject(Sprite* sprite);
    virtual void render();
    void setDrawFunc(DrawFunc);
};

}

#endif
