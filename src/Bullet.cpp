/*
 * Bullet.cpp
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#include "Bullet.h"

Bullet::Bullet() {

}

// 朝某方向移动
void Bullet::move(Direction direction) {
	actionStatus = ACTION_MOVE;
	setDirection(direction);
	moveForward();
}

// 朝某方向移动
void Bullet::stopMove() {
	actionStatus = ACTION_STOP;
}

/**
 * 前进
 * 与当前朝向有关
 */
void Bullet::moveForward() {
	if (direction == UP) {
		y -= speed;
	} else if (direction == RIGHT) {
		x += speed;
	} else if (direction == DOWN) {
		y += speed;
	} else if (direction == LEFT) {
		x -= speed;
	}
}

/**
 * 调整朝向
 */
void Bullet::setDirection(Direction direction) {
	this->direction = direction;
	this->animator->setState(direction);
}

Bullet* Bullet::create(Texture* tex) {
	Bullet* b = new Bullet();
	b->texture = tex;

	// 元素贴图索引数组
	int tankSeqLen = 2;
	int tankOneSeq[] = {
			//上
			3, 0,
			// 右
			5, 0,
			// 下
			6, 0,
			// 左
			4, 0, };
	// 动画控制器
	StateFrameAnimator* animator = new StateFrameAnimator();
	animator->init();
	animator->frameTick = 100;
	animator->addStateFrame(UP, tankOneSeq, tankSeqLen);
	animator->addStateFrame(RIGHT, tankOneSeq + tankSeqLen, tankSeqLen);
	animator->addStateFrame(DOWN, tankOneSeq + tankSeqLen * 2, tankSeqLen);
	animator->addStateFrame(LEFT, tankOneSeq + tankSeqLen * 3, tankSeqLen);
	b->animator = animator;
	return b;
}

void Bullet::update() {
	// 更新坦克的位置，朝向，速度等计算
	if (actionStatus == ACTION_MOVE) {
		moveForward();
		// 动画控制器计算当前纹理片段
		animator->update();
	}
}


void Bullet::draw() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	TextureSliceIndex sliceIndex = animator->getCurSliceIndex();
	Log::i("get cur slice index %d, %d", sliceIndex.i, sliceIndex.j);
	Texture* tex = texture->genSlice(sliceIndex);
	//Log::i("bullet blit surface: to (%d, %d, %d, %d)", rect.x, rect.y, rect.w, rect.h);
	// 显示
	blitTexture(tex, &rect);
}
