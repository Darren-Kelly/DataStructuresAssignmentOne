#include "stdafx.h"
#include "BouncingThing.h"

BouncingThing::BouncingThing(float centreX, float centreY,  float velx, float vely, float angle)
{
	centreVec.x = centreX;
	centreVec.y = centreY;

	rotation.rotate(angle);
	
	collisionOccured = false;
	velocity.x = velx;
	velocity.y = vely;

	if(velocity.x > 0 && velocity.y > 0)
	{
		direction = diagonalRightUp;
	}
	else if(velocity.x < 0 && velocity.y < 0)
	{
		direction = diagonalLeftDown;
	}
	else if(velocity.x > 0 && velocity.y < 0)
	{
		direction = diagonalRightDown;
	}
	else if(velocity.x < 0 && velocity.y > 0)
	{
		direction = diagonalLeftUp;
	}


}