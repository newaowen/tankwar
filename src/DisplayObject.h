/*
 * =====================================================================================
 *
 *       Filename:  DisplayObject.h
 *
 *    Description:  可显示物体
 *
 *        Version:  1.0
 *        Created:  2012年10月25日 23时30分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

class DisplayObject {

    public: 
        float x, y;
        Shape   shape;    
        Texture texture;
        bool  visible;
        // sprite
    public:
        render();
        setTexture();
}
