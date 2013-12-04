////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "BouncingSquare.h"
  

	
BouncingSquare::BouncingSquare(float centreX, float centreY,  float velx, float vely, float angle):BouncingThing(centreX,centreY,velx,vely,angle)
{
	
	vec1.x = -20;
	vec1.y = -20;

	vec2.x =  -20;
	vec2.y = 20;

	vec3.x = 20;
	vec3.y = 20;

	vec4.x = 20;
	vec4.y = -20;

	Red = 0;
	Green =1;
	Blue = 1;

}
	

void BouncingSquare::Draw()
{

	glBegin(GL_QUADS);//draw a Triangle
            glColor3d(Red,Green,Green);//cyan
            glVertex2d(centreVec.x + vec1.x, centreVec.y + vec1.y);
            //glColor3d(1,1,0);//yellow
			glVertex2d(centreVec.x + vec2.x, centreVec.y + vec2.y);
           // glColor3d(1,0,1);//magenta
            glVertex2d(centreVec.x + vec3.x ,centreVec.y + vec3.y);
			glVertex2d(centreVec.x +vec4.x,centreVec.y +vec4.y);
			glEnd();	
}

