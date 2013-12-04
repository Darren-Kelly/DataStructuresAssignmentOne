#ifndef __BouncingThing_h_
#define __BouncingThing_h_

#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
 
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>

class BouncingThing
{
	public:

	sf::Vector2f centreVec;
	sf::Vector2f vec1;
	sf::Vector2f vec2;
	sf::Vector2f vec3;
	sf::Vector2f vec4;
	
	sf::Vector2f point;

	sf::Transform rotation;

	sf::Vector2f velocity;

	int Red;
	int Green;
	int Blue;

	bool collisionOccured;

	BouncingThing::BouncingThing(float vec1x, float vec1y,  float velx, float vely, float angle);
	
	void Draw();
	

	enum Direction {diagonalRightUp, diagonalRightDown, diagonalLeftUp, diagonalLeftDown} direction;
	
	sf::Vector2f BouncingThing::getVec1()
	{
		return vec1;
	}
	sf::Vector2f BouncingThing::getVec2()
	{
		return vec2;

	}
	sf::Vector2f BouncingThing::getVec3()
	{
		return vec3;
	}
	sf::Vector2f BouncingThing::getVec4()
	{
		return vec4;
	}


	void BouncingThing::Update()
	{
		if(direction == diagonalRightUp)
		{
		velocity.x = 0.5;
		velocity.y = 0.5;
		}
		else if(direction == diagonalLeftDown)
		{
		velocity.x = -0.5;
		velocity.y = -0.5;
		}
		else if(direction == diagonalLeftUp)
		{
		velocity.x = -0.5;
		velocity.y = 0.5;
		}
		else if(direction == diagonalRightDown)
		{
		velocity.x = 0.5;
		velocity.y = -0.5;
		}

		
	
		vec1 = rotation.transformPoint(vec1);
		vec2 = rotation.transformPoint(vec2);
		vec3 = rotation.transformPoint(vec3);
		vec4 = rotation.transformPoint(vec4);
		


		centreVec += velocity;
		
		
		if(centreVec.y + vec1.y >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalRightDown;
		}
		else if(centreVec.y + vec1.y >= 798 && direction == diagonalLeftUp)
		{
		direction = diagonalLeftDown;
		}
		if(centreVec.y + vec2.y >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalRightDown;
		}
		else if(centreVec.y + vec2.y >= 798 && direction == diagonalLeftUp)
		{
		direction = diagonalLeftDown;
		}
		if(centreVec.y + vec3.y >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalRightDown;
		}
		else if(centreVec.y + vec3.y >= 798 && direction == diagonalLeftUp)
		{
		direction = diagonalLeftDown;
		}
		if(centreVec.y + vec4.y >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalRightDown;
		}
		else if(centreVec.y + vec4.y >= 799 && direction == diagonalLeftUp)
		{
		direction = diagonalLeftDown;
		}


		if(centreVec.x + vec1.x >= 798 && direction == diagonalRightDown)
		{
		direction = diagonalLeftDown;
		}
		else if(centreVec.x + vec1.x >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalLeftUp;
		}
		if(centreVec.x + vec2.x >= 798 && direction == diagonalRightDown)
		{
		direction = diagonalLeftDown;
		}
		else if(centreVec.x + vec2.x >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalLeftUp;
		}
		if(centreVec.x + vec3.x >= 798 && direction == diagonalRightDown)
		{
		direction = diagonalLeftDown;
		}
		else if(centreVec.x + vec3.x >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalLeftUp;

		}
		if(centreVec.x + vec4.x >= 798 && direction == diagonalRightDown)
		{
		direction = diagonalLeftDown;
		}
		else if(centreVec.x + vec4.x >= 798 && direction == diagonalRightUp)
		{
		direction = diagonalLeftUp;

		}



		if(centreVec.y + vec1.y <= 2 && direction == diagonalLeftDown)
		{
		direction = diagonalLeftUp;
		}
		else if(centreVec.y + vec1.y <= 2 && direction == diagonalRightDown)
		{
		direction = diagonalRightUp;
		}
		if(centreVec.y + vec2.y <= 2 && direction == diagonalLeftDown)
		{
		direction = diagonalLeftUp;
		}
		else if(centreVec.y + vec2.y <= 2 && direction == diagonalRightDown)
		{
		direction = diagonalRightUp;
		}
		if(centreVec.y + vec3.y <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalLeftUp;
		}
		else if(centreVec.y + vec3.y <= 2 && direction == diagonalRightDown)
		{
			direction = diagonalRightUp;
		}
		if(centreVec.y + vec4.y <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalLeftUp;
		}
		else if(centreVec.y + vec4.y <= 2 && direction == diagonalRightDown)
		{
			direction = diagonalRightUp;
		}




		if(centreVec.x + vec1.x <= 2 && direction == diagonalLeftUp)
		{
			direction = diagonalRightUp;
		}
		else if(centreVec.x + vec1.x <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalRightDown;
		}
		if(centreVec.x + vec2.x <= 2 && direction == diagonalLeftUp)
		{
			direction = diagonalRightUp;
		}
		else if(centreVec.x + vec2.x <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalRightDown;
		}
		if(centreVec.x + vec3.x <= 2 && direction == diagonalLeftUp)
		{
			direction = diagonalRightUp;
		}
		else if(centreVec.x + vec3.x <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalRightDown;
		}
		if(centreVec.x + vec4.x <= 2 && direction == diagonalLeftUp)
		{
			direction = diagonalRightUp;
		}
		else if(centreVec.x + vec4.x <= 2 && direction == diagonalLeftDown)
		{
			direction = diagonalRightDown;
		}


		

}


};
#endif