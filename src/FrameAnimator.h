/*
 * 动画物体
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#ifndef ANIMATEOBJECT_H_
#define ANIMATEOBJECT_H_

#include "Texture.h"

namespace Tengine {

/**
 * frame 贴图动画控制器
 */
class FrameAnimator {
public:
	int frameTick;
	int speedCount;
	int animateStat; // 动画播放状态 ?
	bool playOver;

	// 贴图序列数组
	// 处理块大小相同的子纹理
	TextureSliceIndex* sliceIndexes;

	// 动画序列的贴图总数
	int frameNum;
	// 当前帧索引
	int curFrameIndex;

public:
	FrameAnimator();
	// 播放动画
	void play();
	// 暂停动画
	void pause();

	// 更新　frame
	virtual void update();
	virtual void nextFrame();
	TextureSliceIndex* sliceIndexesFromArray(int* arr, int size);
	TextureSliceIndex getCurSliceIndex();
};

}

#endif /* ANIMATEOBJECT_H_ */
