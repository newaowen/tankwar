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

public:
    DisplayObject();

    // 绘制接口
    virtual void draw();
};

}

#endif

