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
	float x, y;
	// 缓存位置
	float savedX, savedY;

	// 屏幕引用
	 SDL_Surface* screen;

	// 是否可见
	bool visible;
	//DrawFunc drawFunc;

	// 可由外部动态修改事件处理器
	EventHandler eventHandler;

public:
	DisplayObject();


	inline void attachScreen(SDL_Surface* screen) {
		this->screen = screen;
	}


	// 事件处理接口
	virtual void handleEvent(SDL_Event evt);

	// 位置缓存处理
	virtual void savePos();
	virtual void restorePos();

	// bound box 用于碰撞检测
	virtual SDL_Rect getBoundRect();
	// 更新接口
	virtual void update();
	// 绘制接口
	virtual void draw();
};

}

#endif

