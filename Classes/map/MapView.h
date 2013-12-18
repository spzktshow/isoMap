#include <cocos2d.h>
#include "MapData.h"

class MapView
{
public:
	virtual void setMapData(Map* mapData);
protected:
	Map* map;
};

class MapTileLayer : public cocos2d::CCLayer, public MapView
{
public:
	MapTileLayer();
	~MapTileLayer();

	virtual bool init();
	/***÷ÿ–¥draw***/
	virtual void draw();

	static MapTileLayer* create();

	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

class MapBackGround : public cocos2d::CCLayer, public MapView
{
public:
	virtual void setMapData(Map* mapData);
};

class MapScene : public cocos2d::CCScene, public MapView
{
public:
	MapScene();
	~MapScene();

	static MapScene* create();

	bool init();
};