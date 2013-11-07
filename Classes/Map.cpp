//
//  Map.cpp
//  HelloCpp
//
//  Created by RockLee on 13-10-4.
//
//

#include "Map.h"

Map::Map()
{
    mapScene = CCScene::create();
    
    //
}

Map::~Map()
{
    mapScene = NULL;
    nodesLayer = NULL;
}