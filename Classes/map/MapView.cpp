#include "MapView.h"
#include "MSGeometry.h"

USING_NS_CC;
USING_NS_MS;
/******************MapView**********************/
void MapView::setMapData(Map* mapData)
{
	map = mapData;
}



/******************MapTileLayer************************/
MapTileLayer::MapTileLayer()
{
	//set touchEnabled
	this->setTouchEnabled(true);
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

MapTileLayer::~MapTileLayer()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

void MapTileLayer::draw()
{
	if (map)
	{
		CHECK_GL_ERROR_DEBUG();
		CCDirector* direct = CCDirector::sharedDirector();
		int i = 0;
		CCSize mapTotalSize;
		mapTotalSize.width = map->nodeData->matrix->col * map->nodeSize->width;
		mapTotalSize.height = map->nodeData->matrix->row * map->nodeSize->height;
		for (i = 0; i <= map->nodeData->matrix->col; i ++)
		{
			MSPoint3D startP(i * map->nodeSize->width, 0, 0);
			MSPoint3D endP(i * map->nodeSize->width, 0, mapTotalSize.height);
			CCPoint sp = MapUtils::convertScreen(startP);
			CCPoint ep = MapUtils::convertScreen(endP);
			sp.y = CoordinateUtils::calculateCoordinateSystem(sp.y, direct->getWinSize());
			ep.y = CoordinateUtils::calculateCoordinateSystem(ep.y, direct->getWinSize());
			ccDrawLine(sp, ep);	
		}
		for (i = 0; i <= map->nodeData->matrix->row; i ++)
		{
			MSPoint3D startQ(0, 0, i * map->nodeSize->height);
			MSPoint3D endQ(mapTotalSize.width, 0, i * map->nodeSize->height);
			CCPoint sq = MapUtils::convertScreen(startQ);
			CCPoint eq = MapUtils::convertScreen(endQ);
			sq.y = CoordinateUtils::calculateCoordinateSystem(sq.y, direct->getWinSize());
			eq.y = CoordinateUtils::calculateCoordinateSystem(eq.y, direct->getWinSize());
			ccDrawLine(sq, eq);
		}
		CHECK_GL_ERROR_DEBUG();
	}
	else
	{
		CCLayer::draw();
	}

}

bool MapTileLayer::init()
{
	if (!CCLayer::init()) return false;
	return true;
}

MapTileLayer* MapTileLayer::create()
{
	MapTileLayer* mapTileLayer = new MapTileLayer;
	if (mapTileLayer && mapTileLayer->init())
	{
		mapTileLayer->autorelease();
		return mapTileLayer;
	}
	else
	{
		CC_SAFE_DELETE(mapTileLayer);
		return NULL;
	}
}

bool MapTileLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLog("touch began");
	return true;
}

void MapTileLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCLog("touch ended");
}

void MapTileLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCLog("touch cancelled");
}

void MapTileLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCLog("touch moved");
}

/***********************MapBackGroud********************/
void MapBackGround::setMapData(Map* mapData)
{
	//2600 * 1300;
	CCSprite* background = CCSprite::create("HelloWorld.png");
	this->addChild(background);
}

/***************************MapScene*********************/
MapScene::MapScene()
{

}

MapScene::~MapScene()
{

}

MapScene* MapScene::create()
{
	MapScene * mapScene = new MapScene();
	if (mapScene && mapScene->init())
	{
		mapScene->autorelease();
		return mapScene;
	}
	else
	{
		CC_SAFE_DELETE(mapScene);
		return NULL;
	}
}

bool MapScene::init()
{
	bool inited = false;
	do 
	{
		CCDirector * pDirector;
		CC_BREAK_IF(! (pDirector = CCDirector::sharedDirector()) );
		this->setContentSize(pDirector->getWinSize());

		inited = true;
	} while (0);
	return inited;
}
