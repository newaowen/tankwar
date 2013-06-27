/*
 * EventHandler.h
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include <SDL/SDL.h>

namespace Tengine {

	class DisplayObject;

	typedef void (*EventHandler)(DisplayObject* o, SDL_Event event);

}

#endif /* EVENTHANDLER_H_ */
