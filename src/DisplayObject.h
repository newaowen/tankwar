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
#include "Shape.h"
#include "Texture.h"

typedef void (*Drawer)();

class DisplayObject {
public: 
    float x, y;
    bool  visible;
    Shape   shape;    
    Texture texture;
    Drawer drawer;
    //Sprite  sprite;
public:
    virtual void render();
    void setTexture(Texture& tex);
    void setDrawer(Drawer f);
};


#endif
