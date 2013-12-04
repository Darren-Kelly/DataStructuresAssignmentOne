#ifndef __BouncingTriangle_h_
#define __BouncingTriangle_h_

#include "BouncingThing.h"

class BouncingTriangle: public BouncingThing
{
public:
	BouncingTriangle(float centreX, float centreY,  float velx, float vely, float angle);
	virtual void Draw();
};
#endif
