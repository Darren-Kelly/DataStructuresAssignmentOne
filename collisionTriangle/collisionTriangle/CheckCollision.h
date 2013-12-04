 #ifndef __CheckCollision_h_
#define __CheckCollision_h_

#include "stdafx.h"

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>
#include "BouncingThing.h"
#include "BouncingSquare.h"

class CheckCollision
{
	public:
	CheckCollision::CheckCollision();
	sf::Vector2f getNormal(sf::Vector2f p1,sf::Vector2f p2);
	
	float getProjVec(sf::Vector2f vec);
	void getMinMax();
	bool checkForCollisions(BouncingSquare*,BouncingSquare*);


	float projectVecA1,projectVecA2,projectVecA3,projectVecA4;
	float projectVecB1,projectVecB2,projectVecB3,projectVecB4;
	sf::Vector2f normVec1;
	sf::Vector2f normVec2;
	sf::Vector2f normalVec;

	int facesIntersecting;
	bool initialised;
	float minVecA,maxVecA,minVecB,maxVecB;
	float dotProduct;



};

//float CheckCollision::projectVecA1;
//float CheckCollision::projectVecA2;
//float CheckCollision::projectVecA3;
//float CheckCollision::projectVecA4;
//float CheckCollision::projectVecB1;
//float CheckCollision::projectVecB2;
//float CheckCollision::projectVecB3;
//float CheckCollision::projectVecB4;
//bool CheckCollision::initialised;
//float CheckCollision::minVecA;
//float CheckCollision::maxVecA;
//float CheckCollision::minVecB;
//float CheckCollision::maxVecB;
//sf::Vector2f CheckCollision::normalVec;
//float CheckCollision::dotProduct;
#endif