// collisionTriangle.cpp : Defines the entry point for the console application.
//
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
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
#include "bouncingTriangle.h"
#include "bouncingSquare.h"
#include "CheckCollision.h"
#include "DemoConstants.h"
#include "MapManager.h"

#include <list>
#include <random>
#include <vector>
using namespace std;

int main()
{
	std::list<BouncingTriangle*> triangleList;
	std::list<BouncingSquare*> squareList;

	list<BouncingTriangle*>::iterator myIntVectorIterator;
	list<BouncingSquare*>::iterator mySquareVectorIterator;
	CheckCollision collision;
	MapManager mapManager;
	list<BouncingSquare *> nonNearbySprites;


	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distrX(100, 700); // define the range
	uniform_int_distribution<> distrY(100, 500); // define the range
	uniform_real_distribution<> distVel(-0.05,0.05);
	uniform_real_distribution<> distAngle(-1,1);

	

	vector<BouncingSquare*> squares;
		//BouncingSquare square1 = BouncingSquare (distrX(eng),distrY(eng),  (float)distVel(eng), (float)distVel(eng), distAngle(eng));
		//BouncingSquare square2 = BouncingSquare (distrX(eng),distrY(eng),  (float)distVel(eng), (float)distVel(eng), distAngle(eng));

	

	sf::VertexArray lines(sf::Lines, 20); 
	{ 

		//horizontal
		lines[0].position = sf::Vector2f(0, 0); 
		lines[1].position = sf::Vector2f(800, 0); 
		lines[2].position = sf::Vector2f(0, 200); 
		lines[3].position = sf::Vector2f(800, 200); 
		lines[4].position = sf::Vector2f(0, 400); 
		lines[5].position = sf::Vector2f(800, 400); 
		lines[6].position = sf::Vector2f(0, 600); 
		lines[7].position = sf::Vector2f(800, 600); 
		lines[8].position = sf::Vector2f(0, 799); 
		lines[9].position = sf::Vector2f(800, 799); 

		//vertical
		lines[10].position = sf::Vector2f(1, 1); 
		lines[11].position = sf::Vector2f(1, 800); 
		lines[12].position = sf::Vector2f(DemoConstants::CELLSIZE, 0); 
		lines[13].position = sf::Vector2f(200, 800); 
		lines[14].position = sf::Vector2f(400, 0); 
		lines[15].position = sf::Vector2f(400, 800); 
		lines[16].position = sf::Vector2f(600, 0); 
		lines[17].position = sf::Vector2f(600, 800); 
		lines[18].position = sf::Vector2f(800, 0); 
		lines[19].position = sf::Vector2f(800, 800); 

		/*lines[6].position = sf::Vector2f(0, 300); 
		lines[7].position = sf::Vector2f(800, 300); */
	};

	squares.resize(10);
	for(int i = 0; i < 10; i++)
	{
		squares[i] = new BouncingSquare(distrX(eng),distrY(eng),  (float)distVel(eng), (float)distVel(eng), distAngle(eng));
	}
	
		for(int i = 0; i <10; i++)
		{
			
			nonNearbySprites.push_back(squares[i]);
		}
	//BouncingTriangle Triangle1(50,50,100,-100*cos(60),150,50,-0.05,0.05);
	//BouncingTriangle Triangle2(400,400,450,-450*cos(60),500,400,-0.05,-0.05);
	//BouncingTriangle Triangle3(50,50,100,-100*cos(60),150,50,-0.05,-0.05);
	//BouncingTriangle Triangle4(50,50,100,-100*cos(60),150,50,0.05,0.05);
	bool colour = true;
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 800, 32), "SFML OpenGL");
   
    // Create a clock for measuring time elapsed    
    sf::Clock Clock;
    
    //prepare OpenGL surface for HSR
    glClearDepth(1.f);
    glClearColor(0.3f, 0.3f, 0.3f, 0.f); //background colour
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
   
    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     
    //set up a 3D Perspective View volume
    //gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar

    //set up a  orthographic projection same size as window
    //this mease the vertex coordinates are in pixel space
    glOrtho(0,800,0,600,0,1); // use pixel coordinates
   
	 while (App.isOpen())
    {	
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();
  	
            // Escape key : exit
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                App.close();
        }

	

		for(int i = 0; i < 10; i++)
		{
			mapManager.registerSprite(squares[i]);
		}

		

		list<BouncingSquare *> nearbySprites = mapManager.getNearbySprites(*squares[9]);
		//list<BouncingSquare *> nearbySprites = nonNearbySprites;
		list<BouncingSquare *>::iterator iter = nearbySprites.begin();
		list<BouncingSquare *>::iterator iter2 = nearbySprites.begin();
		list<BouncingSquare *>::iterator iter3 = nearbySprites.begin();
		list<BouncingSquare *>::iterator nonIter = nonNearbySprites.begin();


		while(nonIter != nonNearbySprites.end())
		{
			BouncingSquare *square = *nonIter;
			square->Red = 0;
			square->Green = 1;
			square->Blue = 1;
			nonIter++;
		}

		squares[9]->Red = 1;
		squares[9]->Green = 1;
		squares[9]->Blue = 1;

      for(;iter2 != nearbySprites.end(); iter2++) 
	  {
		  if(*iter2 != squares[9])
		  {
				BouncingSquare *square = *iter2;
				square->Red = 1;
				square->Green = 0;
				square->Blue = 1;
		  }

		 for(iter3 = iter2;iter3 != nearbySprites.end(); iter3++)
		 {


			if(*iter2 != *iter3)
			{
			    if(collision.checkForCollisions(*iter2,*iter3) == true)
			    {

					BouncingSquare *square = *iter2;
					BouncingSquare *square2 = *iter3;
					if(square->direction == square->diagonalLeftDown)
					{
						square->direction = square->diagonalRightUp;
					}
					else if(square->direction == square->diagonalRightUp)
					{
						square->direction = square->diagonalLeftDown;
					}
					else if(square->direction ==square->diagonalLeftUp)
					{
						square->direction = square->diagonalRightDown;
					}
					else if(square->direction == square->diagonalRightDown)
					{
						square->direction = square->diagonalLeftUp;
					}

					if(square2->direction == square2->diagonalLeftDown)
					{
						square2->direction = square2->diagonalRightUp;
					}
					else if(square2->direction == square2->diagonalRightUp)
					{
						square2->direction = square2->diagonalLeftDown;
					}
					else if(square2->direction == square2->diagonalLeftUp)
					{
						square2->direction = square2->diagonalRightDown;
					}
					else if(square2->direction == square2->diagonalRightDown)
					{
						square2->direction = square2->diagonalLeftUp;
					}
					
				 }
			 }

		  }

	  }
	  

	  






		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		 for(int i = 0; i < 10; i++)
		{
		squares[i]->Update();
		squares[i]->Draw();


		//collsion
		/*for(int j = 0; j < 10; j++)
		{
			if(squares[i] != squares[j])
			{
			   if(collision.checkForCollisions(squares[i],squares[j]) == true)
			   {
					if(squares[i]->direction == squares[i]->diagonalLeftDown)
			   {
				   squares[i]->direction = squares[i]->diagonalRightUp;
			   }
			   else if(squares[i]->direction == squares[i]->diagonalRightUp)
			   {
				   squares[i]->direction = squares[i]->diagonalLeftDown;
			   }
			   else if(squares[i]->direction == squares[i]->diagonalLeftUp)
			   {
				   squares[i]->direction = squares[i]->diagonalRightDown;
			   }
			    else if(squares[i]->direction == squares[i]->diagonalRightDown)
			   {
				   squares[i]->direction = squares[i]->diagonalLeftUp;
			   }

			    if(squares[j]->direction == squares[j]->diagonalLeftDown)
			   {
				   squares[j]->direction = squares[j]->diagonalRightUp;
			   }
			   else if(squares[j]->direction == squares[j]->diagonalRightUp)
			   {
				   squares[j]->direction = squares[j]->diagonalLeftDown;
			   }
			   else if(squares[j]->direction == squares[j]->diagonalLeftUp)
			   {
				   squares[j]->direction = squares[j]->diagonalRightDown;
			   }
			    else if(squares[j]->direction == squares[j]->diagonalRightDown)
			   {
				   squares[j]->direction = squares[j]->diagonalLeftUp;
			   }
			}
			}
		}*/
		 

		App.draw(lines);
	
		mapManager.clearBucketLists();
		
		}

		  

	/*	for(myIntVectorIterator = triangleList.begin(); myIntVectorIterator != triangleList.end(); myIntVectorIterator++)
		{
			(*myIntVectorIterator)->Update();
			(*myIntVectorIterator)->Draw();
		}*/

		/*for(mySquareVectorIterator = squareList.begin(); mySquareVectorIterator != squareList.end(); mySquareVectorIterator++)
		{
			(*mySquareVectorIterator)->Update();
			(*mySquareVectorIterator)->Draw();
		
		}*/
		 
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

			   App.display();
	 }

	    return EXIT_SUCCESS;
}

