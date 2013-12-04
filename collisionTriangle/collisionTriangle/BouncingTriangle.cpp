////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "BouncingTriangle.h"
  

	
BouncingTriangle::BouncingTriangle(float centreX, float centreY,  float velx, float vely, float angle):BouncingThing(centreX,centreY,velx,vely,angle)
{
	
	vec1.x = -50;
	vec1.y = -50;

	vec2.x =  0;
	vec2.y = 50;

	vec3.x = 50;
	vec3.y = -50;

}
	

void BouncingTriangle::Draw()
{
	

	glBegin(GL_LINE_LOOP);//draw a Triangle
            glColor3d(0,1,1);//cyan
            glVertex2d(centreVec.x + vec1.x, centreVec.y + vec1.y);
            glColor3d(1,1,0);//yellow
			glVertex2d(centreVec.x + vec2.x, centreVec.y + vec2.y);
            glColor3d(1,0,1);//magenta
            glVertex2d(centreVec.x + vec3.x ,centreVec.y + vec3.y);
			glEnd();	
}

