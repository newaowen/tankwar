/*
 * tank 实现
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "Tank.h"

// 朝某方向移动
void Tank::move(Direction direction) {
	actionStatus = ACTION_MOVE;
	turn(direction);
	moveForward();
}

// 朝某方向移动
void Tank::stopMove() {
	actionStatus = ACTION_STOP;
}

/**
 * 前进
 * 与当前朝向有关
 */
void Tank::moveForward() {
	if (direction == UP) {
		y -= speed;
	} else if (direction == RIGHT) {
		x += speed;
	} else if (direction == DOWN) {
		y += speed;
	} else if (direction == LEFT) {
		x -= speed;
	}
	//Log::i("tank x[%f] y[%f] speed[%f]", x, y, speed);
}

/**
 * 转向
 */
void Tank::turn(Direction direction) {
	this->direction = direction;
	this->animator->setState(direction);
}

SDL_Rect Tank::getBoundRect() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	return rect;
}

void Tank::update() {
	// 更新坦克的位置，朝向，速度等计算
	if (actionStatus == ACTION_MOVE) {
		moveForward();
		// 动画控制器计算当前纹理片段
		animator->update();
	}
}

void Tank::draw() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	TextureSliceIndex sliceIndex = animator->getCurSliceIndex();
	Texture* tex = texture->genSlice(sliceIndex);
	//Log::i("blit surface: from (%d, %d, %d, %d) to (%f, %f, %d, %d)", tex->rect.x, tex->rect.y, tex->rect.w, tex->rect.h,
	//		x, y, w, h);
	// 显示坦克
	blitTexture(tex, &rect);
}

void Tank::fireBullet(Bullet* b) {
	// 发射时的初始位置与当前坦克朝向有关
	b->tank = this;
	b->x = x;
	b->y = y;
	b->w = w;
	b->h = h;
	b->speed = 0.3;

	Log::i("fire bullet at (%f, %f, %d, %d)", x, y, w, h);
	b->move(this->direction);
}

