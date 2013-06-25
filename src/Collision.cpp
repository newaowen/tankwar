/*
 * 碰撞
 *
 *  by zhanqu
 *  date 2013-6-25
 */
#include "Collision.h"

namespace Tengine {

// 检测是否越边界
bool Collision::testOutBorder(SDL_Rect& inBox, SDL_Rect& outBox) {
	if (inBox.x < outBox.x || inBox.y < outBox.y || (inBox.x + inBox.w) > (outBox.x + outBox.w)
			|| (inBox.y + inBox.h) > (outBox.y + outBox.h)) {
		return true;
	} else {
		return false;
	}
}

// 检测是否发生重叠(即碰撞)
bool Collision::testRect(SDL_Rect& a, SDL_Rect& b) {
	return testLine(a.x, a.x + a.w, b.x, b.x + b.w) && testLine(a.y, a.y + a.h, b.y, b.y + b.h);
}

// 单向碰撞
bool Collision::testLine(int aFrom, int aTo, int bFrom, int bTo) {
	if ((aFrom == bFrom) || (aFrom < bFrom && bFrom < aTo) || (aFrom > bFrom && aFrom < bTo)) {
		return true;
	} else {
		return false;
	}
}


} /* namespace Tengine */
