#ifndef __BouncingSquare_h_
#define __BouncingSquare_h_


#include "BouncingThing.h"

class BouncingSquare: public BouncingThing
{
public:
	BouncingSquare(float centreX, float centreY,  float velx, float vely, float angle);
	virtual void Draw();
};
#endif