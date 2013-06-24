/*
 * tank texture
 *
 *  by zhanqu
 *  date 2013-6-23
 */

#ifndef TANKTEXTURE_H_
#define TANKTEXTURE_H_

#include "Texture.h"

using namespace Tengine;

class TankTexture: public Texture {
public:
	int startX;
	int startY;
	int sliceWidth;
	int sliceHeight;

public:
	TankTexture();

	virtual SDL_Rect computeSliceRect(TextureSliceIndex sliceIndex);
};

#endif /* TANKTEXTURE_H_ */
