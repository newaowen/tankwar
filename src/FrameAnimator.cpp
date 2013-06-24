/*
 * {file_name}
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#include "FrameAnimator.h"

namespace Tengine {

FrameAnimator::FrameAnimator() {
	frameTick = 1;
	speedCount = 0;
	curSliceIndex = 0;
	playOver = true;
}

void FrameAnimator::play() {

}

void FrameAnimator::pause() {

}

void FrameAnimator::update() {
	speedCount++;
	if (speedCount >= frameTick) {
		nextFrame();
		speedCount = 0;
	}
}

void FrameAnimator::nextFrame() {
	// 更新帧
	curSliceIndex++;
	if (curSliceIndex >= sliceNum) {
		curSliceIndex = 0;
	}
}

TextureSliceIndex FrameAnimator::getCurSliceIndex() {
	TextureSliceIndex sliceIndex;
	sliceIndex = sliceIndexes[curSliceIndex];
	return sliceIndex;
}

/**
 * 从数组中拷贝索引
 */
void FrameAnimator::sliceIndexesFromArray(int* arr, int size) {
	sliceNum = size / 2;
	sliceIndexes = new TextureSliceIndex[sliceNum];

	Log::i("new TextureSliceIndex %d", sliceNum);
	for (int index = 0; index < sliceNum; index += 1) {
		sliceIndexes[index].i = arr[index * 2];
		sliceIndexes[index].j = arr[index * 2 + 1];
	}
}

}
