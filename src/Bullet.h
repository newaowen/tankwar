/*
 * Bullet.h
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Constant.h"
#include "Sprite.h"
#include "StateFrameAnimator.h"


using namespace Tengine;

class Tank;

/**
 * 子弹
 */
class Bullet: public Sprite {
public:
	Tank* tank; // 表示子弹是哪个坦克发射的
	// 四个方向上的动画控制器
	StateFrameAnimator* animator;

	ActionStatus actionStatus;
public:
	Bullet();
	// 子弹不会转弯!
	// 朝某方向移动
	void move(Direction direction);
	// 沿着原方向向前移动
	void moveForward();
	// 停止移动
	void stopMove();

	void setDirection(Direction direction);

	void update();

	// 朝某方向转动
	// void turn(Direction direction);
	void explode();

	// 工厂方法
	static Bullet* create(Texture* tex);
	virtual void  draw();
};

#endif /* BULLET_H_ */
