//
//  Map.h
//  HelloCpp
//
//  Created by RockLee on 13-10-4.
//
//

#ifndef __HelloCpp__Map__
#define __HelloCpp__Map__

#include <cocos2d.h>

USING_NS_CC;

class MapNodeLayer : public CCLayer
{
public:
    virtual void draw();
};

class Map
{
public:
    Map();
    ~Map();
protected:
    // 场景
    CCScene* mapScene;
    //地图节点层
    MapNodeLayer* nodesLayer;
};
#endif /* defined(__HelloCpp__Map__) */
