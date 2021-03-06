/*
 * Rope.h
 *
 *  Created on: 2013-4-1
 *      Author: cske
 */

#ifndef ROPE_H_
#define ROPE_H_
#include "cocos2d.h"
#include "Box2D/Box2D.h"
USING_NS_CC;
class Rope: public CCLayer, b2ContactListener  {
	enum GameState
		{
		    inited	= 0,
		    running	= 1,
			paused	= 2,
			over	= 3
		};
public:
	Rope();
	virtual ~Rope();
};

#endif /* ROPE_H_ */
