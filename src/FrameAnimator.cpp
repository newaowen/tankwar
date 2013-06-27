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
	curFrameIndex = 0;
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
	curFrameIndex++;
	if (curFrameIndex >= frameNum) {
		curFrameIndex = 0;
	}
}

TextureSliceIndex FrameAnimator::getCurSliceIndex() {
	TextureSliceIndex sliceIndex;
	sliceIndex = sliceIndexes[curFrameIndex];
	return sliceIndex;
}

/**
 * 从数组中拷贝索引
 */
TextureSliceIndex* FrameAnimator::sliceIndexesFromArray(int* arr, int size) {
	frameNum = size / 2;
	TextureSliceIndex* indexes = new TextureSliceIndex[frameNum];

	Log::i("new TextureSliceIndex %d", frameNum);
	for (int index = 0; index < frameNum; index += 1) {
		indexes[index].i = arr[index * 2];
		indexes[index].j = arr[index * 2 + 1];
	}

	return indexes;
}

}
