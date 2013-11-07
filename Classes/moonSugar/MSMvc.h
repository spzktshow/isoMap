//
//  MSMvc.h
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#ifndef __HelloCpp__MSMvc__
#define __HelloCpp__MSMvc__

#include <cocos2d.h>
#include "MoonSugar.h"
#include "MSGroup.h"

NS_MS_BEGIN
/********model********/
class MSModelData : public MSGroupItem
{
public:
    MSModelData();
    ~MSModelData();

	virtual void init();
	virtual void dispose();
protected:
    cocos2d::CCNotificationCenter* notificationCenter;
};

class MSModel : public MSGroup
{
public:
    static MSModel* getInstance();
    static void release();

	virtual void registerModel(MSModelData* modelData);
	virtual void removeModel(MSModelData* modelData);

	virtual MSModelData* createModelData();
protected:
    static MSModel* model;
};

/********controller******/
class MSCommand : public cocos2d::CCObject
{
public:
    virtual void execute(const char* type, CCObject* data);
};

/********view***********/
//class MSMediator : public MSGroupItem
//{
//public:
//    MSMediator();
//    ~MSMediator();
//protected:
//    CCNotificationCenter* notificationCenter;
//    
//    void addListener(const char* eventType, SEL_CallFuncO handler);
//    void removeListener(const char* eventType);
//};

NS_MS_END;

#endif /* defined(__HelloCpp__MSMvc__) */
