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
#include "EventHandler.h"

namespace Tengine {

typedef void (*DrawFunc)();

/**
 * 可渲染物体封装
 */
class DisplayObject {
public: 
    // 位置
    int x, y;
    // 是否可见
    bool  visible;
    //DrawFunc drawFunc;

    // 可由外部动态修改事件处理器
    EventHandler eventHandler;

    // bound box 用于碰撞检测

public:
    DisplayObject();
    // 事件处理接口
    virtual void handleEvent(SDL_Event evt);
    // 绘制接口
    virtual void draw();
};

}

#endif

