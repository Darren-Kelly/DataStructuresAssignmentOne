#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "BouncingThing.h"
#include "BouncingSquare.h"


#include <map>
#include <list>
#include <algorithm> // for STL find()

using std::list;
using std::map;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();

	void clearBucketLists();

	void registerSprite( BouncingSquare * sprite );

	list<int> getBucketId( BouncingSquare const & sprite );

	list<BouncingSquare *> getNearbySprites( BouncingSquare & sprite );

private:

	map< int, list< BouncingSquare *> > m_buckets;

		

	void addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif