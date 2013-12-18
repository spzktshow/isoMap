#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MapView.h"
#include "MSMvc.h"

USING_NS_CC;
USING_NS_MS;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	MSModel* model = MSModel::getInstance();
	//
	/*****在程序生命周期内持续存在,直到从model中remove时才delete***/
	MapModel* mapModel = new MapModel();
	model->registerModel(mapModel);
	MapScene* scene = MapScene::create();
	MapTileLayer* mapTileLayer = MapTileLayer::create();
	CCLayer* mapBackgroundLayer = CCLayer::create();
	CCSprite* bg = CCSprite::create("map.png");
	bg->setPosition(ccp(-100, 0));
	mapBackgroundLayer->addChild(bg);

	scene->addChild(mapBackgroundLayer);
	scene->addChild(mapTileLayer);

	mapTileLayer->setMapData(mapModel->map);

    // run
    pDirector->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
