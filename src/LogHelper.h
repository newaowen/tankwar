/*
 * 基本log之上的工具
 *
 *  by zhanqu
 *  date 2013-6-24
 */

#ifndef LOGHELPER_H_
#define LOGHELPER_H_

#include <SDL/SDL.h>

namespace Tengine {

class LogHelper {
public:
	static char* rectMsg(SDL_Rect* rect);
};

}

#endif /* LOGHELPER_H_ */
