/*
 * {file_name}
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#include "Animator.h"

namespace Tengine {

Animator::Animator() {
	frameTick = 200;
	speedCount = 0;
	curSliceIndex = 0;
	playOver = true;
}

void Animator::play() {

}

void Animator::pause() {

}

void Animator::update() {
	speedCount++;
	if (speedCount >= frameTick) {
		nextFrame();
		speedCount = 0;
	}
}

void Animator::nextFrame() {
	// 更新帧
	curSliceIndex++;
	if (curSliceIndex >= sliceNum) {
		curSliceIndex = 0;
	}
}

TextureSliceIndex Animator::getCurSliceIndex() {
	TextureSliceIndex sliceIndex;
	sliceIndex = sliceIndexes[curSliceIndex];
	return sliceIndex;
}

/**
 * 从数组中拷贝索引
 */
void Animator::sliceIndexesFromArray(int* arr, int size) {
	sliceNum = size / 2;
	sliceIndexes = new TextureSliceIndex[sliceNum];

	Log::i("new TextureSliceIndex %d", sliceNum);

	for (int index = 0; index < sliceNum; index += 1) {
		sliceIndexes[index].i = arr[index * 2];
		sliceIndexes[index].j = arr[index * 2 + 1];
	}
}

}
