/*
 * StateFrameAnimator.h
 * 含多个状态的动画序列
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#ifndef STATEFRAMEANIMATOR_H_
#define STATEFRAMEANIMATOR_H_

#include <map>
#include "FrameAnimator.h"

using namespace std;

namespace Tengine {

class StateFrameAnimator : public FrameAnimator {
public:
	int curState;
	// 原状态
	int savedState;
	map<int, TextureSliceIndex*> stateSliceIndexes;

public:
	StateFrameAnimator();

	void init();
	// 设置状态
	void setState(int state);
	// 增加状态frame
	void addStateFrame(int state, int *arr, int size);

};

} /* namespace Tengine */
#endif /* STATEFRAMEANIMATOR_H_ */
