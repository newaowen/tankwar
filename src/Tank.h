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
#include "Animator.h"

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
	Weapon weapon;
	int level;
	float health;
	float attack;
	float armor;

	Animator* animator;

public:
	void move();

	void turn();
	void draw();
	bool isDead();
};


//collisionDetect(AnimateObject, Map);
//collisionDetect(AnimateObject, AnimateObject);

// 剧情

#endif
