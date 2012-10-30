/*
 * =====================================================================================
 *
 *       Filename:  Tank.h
 *
 *    Description:  tank object
 *
 *        Version:  1.0
 *        Created:  2012年10月25日 23时42分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _TANK_
#define _TANK_

#include "DisplayObject.h"

class AnimateObject : DisplayObject {
    public :
        float speed;
        float direction; 
        int animateStat;
        bool playOver;
    public :
        void move();
        void playAnimate();

};

class Bullet : AnimateObject {

};

class Weapon {
    public:
        float damage;
    public:
        void fire();
};

class Tank : AnimateObject {
    public: 
        Weapon weapon;
        int level;
        float health;
        float attack;
        float armor;

    public: 
        bool isDead();
};


// 
class MapElement : DisplayObject {

};


class Map  {
    public: 
        //HashMap<Vector2, MapElement> elements;

};

//collisionDetect(AnimateObject, Map);
//collisionDetect(AnimateObject, AnimateObject);

// 剧情


#endif