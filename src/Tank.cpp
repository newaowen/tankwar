/*
 * tank 实现
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#include "Tank.h"

// 转向移动
void Tank::moveLeft() {
	turn(LEFT);
	moveForward();
}

void Tank::moveUp() {
	turn(UP);
	moveForward();
}

void Tank::moveRight() {
	turn(RIGHT);
	moveForward();
}

void Tank::moveDown() {
	turn(DOWN);
	moveForward();
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
}


/**
 * 转向
 */
void Tank::turn(Direction direction) {
	this.direction = direction;
}



void Tank::draw() {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	savePos();

	// 坦克的位置，朝向，速度等计算

	// 碰撞检测


	// 如果发生碰撞，则还原位置
	if (true) {
		restorePos();
	}

	// 动画控制器计算当前纹理片段
	animator->update();
	TextureSliceIndex sliceIndex = animator->getCurSliceIndex();
	Texture* tex = texture->genSlice(sliceIndex);

	//Log::i("blit surface: from (%d, %d, %d, %d)", tex->rect.x, tex->rect.y, tex->rect.w, tex->rect.h);
	// 显示坦克
	blitTexture(tex, &rect);
}

bool Tank::collisionDetect() {
	return false;
}

void Tank::savePos() {
	savedX = x;
	savedY = y;
}

void Tank::restorePos() {
	x = savedX;
	y = savedY;
}
