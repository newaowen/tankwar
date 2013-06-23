/*
 * 地图
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#ifndef MAP_H_
#define MAP_H_

#include "DisplayObject.h"

namespace Tengine {

class Map {
protected:
	//HashMap<Vector2, MapElement> elements;

public:

	Map();
	virtual ~Map();
};

/*
 * 地图元素
 */
class MapElement: DisplayObject {

};

}

#endif /* MAP_H_ */
