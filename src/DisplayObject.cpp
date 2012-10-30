/*
 * =====================================================================================
 *
 *       Filename:  DisplayObject.cpp
 *
 *        Version:  1.0
 *        Created:  2012年10月29日 22时51分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *
 * =====================================================================================
 */
#include "DisplayObject.h"

void DisplayObject::render() {
    this->drawer();
}

void DisplayObject::setDrawer(Drawer d) {
    this->drawer = d;
}

void DisplayObject::setTexture(Texture& tex) {
    this->texture = tex;
}

