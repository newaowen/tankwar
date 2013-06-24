/*
 * =====================================================================================
 *
 *       Filename:  DisplayObject.cpp
 *
 *        Version:  1.0
 *        Created:  2012年10月29日 22时51分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *
 * =====================================================================================
 */
#include "DisplayObject.h"

namespace Tengine {

DisplayObject::DisplayObject() {
	x = 0;
	y = 0;
	visible = true;
	eventHandler = NULL;
}

void DisplayObject::draw() {

}

void DisplayObject::handleEvent(SDL_Event event) {
	if (eventHandler) {
		eventHandler(this, event);
	}
}

/*
void DisplayObject::setDrawFunc(DrawFunc func) {
    drawFunc = func;
}
*/

}
