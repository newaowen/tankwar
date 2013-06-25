/*
 * =====================================================================================
 *
 *       Filename:  Tank.h
 *
 *    Description:  tank object
 *
 *        Version:  1.0
 *        Created:  2012年10月25日 23时42分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _TANK_
#define _TANK_

#include "Sprite.h"
#include "FrameAnimator.h"
#include "EventHandler.h"
#include "Collision.h"

using namespace Tengine;

/** 
 * 子弹
 */
class Bullet: public Sprite {

};

/*
 * 武器
 */
class Weapon {
public:
	float damage;
public:
	void fire();
};

/*
 * 坦克
 */
class Tank: public Sprite {
public:
	Weapon 	weapon;
	int 	level;
	float 	health;
	float 	attack;
	float 	armor;

	// 朝向，速度
	int 	speed;

	// TODO 添加　行动控制器

	FrameAnimator* animator;

public:
	void moveLeft();
	void moveUp();
	void moveRight();
	void moveDown();

	void moveForward();
	void turn(Direction direction);

	// 位置缓存处理
	void savePos();
	void restorePos();

	virtual SDL_Rect getBoundRect();
	virtual void update();
	virtual void draw();

	bool isDead();

	// 事件处理接口
	// virtual void handleEvent(SDL_Event evt);
};

//collisionDetect(AnimateObject, Map);
//collisionDetect(AnimateObject, AnimateObject);

// 剧情

#endif
