/*
 * 碰撞
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include <SDL/SDL.h>

namespace Tengine {

class Collision {
public:
	 // 检测是否越边界
	 static bool testOutBorder(SDL_Rect& inBox, SDL_Rect& outBox);

	 // 检测矩形是否发生重叠(即碰撞)
	 static bool testRect(SDL_Rect& a, SDL_Rect& b);

	 static bool testLine(int xa, int xb, int ya, int yb);
};

}
#endif /* COLLISION_H_ */
