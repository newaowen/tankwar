/*
 * 动画物体
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#ifndef ANIMATEOBJECT_H_
#define ANIMATEOBJECT_H_

namespace Tengine {

class AnimateObject : DisplayObject {
protected:
	float speed;
	float direction;
	int animateStat;
	bool playOver;

public:
	AnimateObject();
	virtual ~AnimateObject();
	void move();
	void playAnimate();
};

}

#endif /* ANIMATEOBJECT_H_ */
