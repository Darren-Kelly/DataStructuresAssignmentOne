#include "stdafx.h"
#include "CheckCollision.h"


CheckCollision::CheckCollision()
{
	maxVecA = 0;
	minVecA = 0;
	maxVecB = 0;
	minVecB = 0;


	projectVecA1 = 0;
	projectVecA2 = 0;
	projectVecA3 = 0;
	projectVecA4 = 0;
	projectVecB1 = 0;
	projectVecB2 = 0;
	projectVecB3 = 0;
	projectVecB4 = 0;
	normalVec = sf::Vector2f(0,0);
	facesIntersecting = 0;
	initialised = false;

}
bool CheckCollision::checkForCollisions(BouncingSquare* shapeA,BouncingSquare* shapeB)
{
	//if(shape.vec4 != NULL)
	//{
	for(int i = 0; i<4; i++)
	{
		if(i == 0)
		{
			normVec1 = shapeA->vec1;
			normVec2 = shapeA->vec2;
		}
		if(i == 1)
		{
			normVec1 = shapeA->vec2;
			normVec2 = shapeA->vec3;
		}
		else if(i == 2)
		{
			normVec1 = shapeB->vec1;
			normVec2 = shapeB->vec2;
		}
		else if(i == 3)
		{
			normVec1 = shapeB->vec2;
			normVec2 = shapeB->vec3;
		}

		normalVec = getNormal(normVec1,normVec2);
		projectVecA1 = getProjVec(shapeA->vec1);
		projectVecA2 = getProjVec(shapeA->vec2);
		projectVecA3 = getProjVec(shapeA->vec3);
		projectVecA4 = getProjVec(shapeA->vec4);
		projectVecA1 += getProjVec(shapeA->centreVec);
		projectVecA2 += getProjVec(shapeA->centreVec);
		projectVecA3 += getProjVec(shapeA->centreVec);
		projectVecA4 += getProjVec(shapeA->centreVec);

		projectVecB1 = getProjVec(shapeB->vec1);
		projectVecB2 = getProjVec(shapeB->vec2);
		projectVecB3 = getProjVec(shapeB->vec3);
		projectVecB4 = getProjVec(shapeB->vec4);
		projectVecB1 += getProjVec(shapeB->centreVec);
		projectVecB2 += getProjVec(shapeB->centreVec);
		projectVecB3 += getProjVec(shapeB->centreVec);
		projectVecB4 += getProjVec(shapeB->centreVec);

		getMinMax();

		if (maxVecA < minVecB || maxVecB < minVecA)
		{
		return false;
		}
	
	
	
	}
	
	return true;
	//}
}

sf::Vector2f CheckCollision::getNormal(sf::Vector2f p1,sf::Vector2f p2)
{
	sf::Vector2f axis;

	 axis.x = p2.y - p1.y;
     axis.y = p1.x - p2.x;


	float temp = sqrt(axis.x * axis.x + axis.y * axis.y);
               axis.x = axis.x / temp;
              axis.y = axis.y / temp;

	return axis; 
}

float CheckCollision::getProjVec(sf::Vector2f vec)
{
	float temp = (normalVec.x *vec.x + normalVec.y *vec.y);
	
	return temp;
}

void CheckCollision::getMinMax()
{
	minVecA = maxVecA = projectVecA1;

	if(maxVecA < projectVecA2)
	{
		maxVecA = projectVecA2;
	}
	if(maxVecA < projectVecA3)
	{
		maxVecA = projectVecA3;
	}
	if(maxVecA < projectVecA4)
	{
		maxVecA = projectVecA4;
	}

	if(minVecA > projectVecA2)
	{
		minVecA = projectVecA2;
	}
	if(minVecA > projectVecA3)
	{
		minVecA = projectVecA3;
	}
	if(minVecA > projectVecA4)
	{
		minVecA = projectVecA4;
	}

		minVecB = maxVecB = projectVecB1;

	if(maxVecB < projectVecB2)
	{
		maxVecB = projectVecB2;
	}
	if(maxVecB < projectVecB3)
	{
		maxVecB = projectVecB3;
	}
	if(maxVecB < projectVecB4)
	{
		maxVecB = projectVecB4;
	}

	if(minVecB > projectVecB2)
	{
		minVecB = projectVecB2;
	}
	if(minVecB > projectVecB3)
	{
		minVecB = projectVecB3;
	}
	if(minVecB > projectVecB4)
	{
		minVecB = projectVecB4;
	}
}



