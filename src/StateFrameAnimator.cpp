/*
 * StateFrameAnimator.cpp
 *
 *  by zhanqu
 *  date 2013-6-25
 */

#include "StateFrameAnimator.h"

namespace Tengine {

StateFrameAnimator::StateFrameAnimator() {
	curFrameIndex = 0;
}

void StateFrameAnimator::init() {
	//stateSliceIndexes = new map<int, TextureSliceIndex*>();
}

void StateFrameAnimator::setState(int state) {
	savedState = curState;
	curState = state;

	if(stateSliceIndexes.find(state) != stateSliceIndexes.end()){
		sliceIndexes = stateSliceIndexes[state];
		// 状态实际变化时才更新frame index
		if (curState != state) {
			curFrameIndex = 0;
		}
	}
}

void StateFrameAnimator::addStateFrame(int state, int *arr, int size) {
	TextureSliceIndex* indexes = sliceIndexesFromArray(arr, size);
	stateSliceIndexes[state] = indexes;
}

} /* namespace Tengine */
