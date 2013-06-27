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
#include "StateFrameAnimator.h"
#include "EventHandler.h"
#include "Collision.h"
#include "Bullet.h"

using namespace Tengine;



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
	Weapon weapon; // 当前武器

	int level; // 坦克级别
	float health; // 血量
	float attack; // 攻击
	float armor; // 防御

	ActionStatus actionStatus;

	// TODO 添加　行动控制器(与动画控制器区别)

	// 四个方向上的动画控制器
	StateFrameAnimator* animator;

public:
	// 朝某方向移动
	void move(Direction direction);
	// 沿着原方向向前移动
	void moveForward();
	// 停止移动
	void stopMove();
	// 朝某方向转动
	void turn(Direction direction);

	virtual SDL_Rect getBoundRect();
	virtual void update();
	virtual void draw();

	bool isDead();

	// 发射子弹
	void fireBullet(Bullet* b);

	// 事件处理接口
	// virtual void handleEvent(SDL_Event evt);
};

//collisionDetect(AnimateObject, Map);
//collisionDetect(AnimateObject, AnimateObject);

// 剧情

#endif
