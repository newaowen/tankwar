/*
 * {file_name}
 *
 *  by zhanqu
 *  date 2013-6-24
 */

#include "LogHelper.h"

namespace Tengine {

char* LogHelper::rectMsg(SDL_Rect* rect) {
	char buf[1024];
	sprintf(buf, "(%d, %d, %d, %d)", rect->x, rect->y, rect->w, rect->h);
	return buf;
}

}
