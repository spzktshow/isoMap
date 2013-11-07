//
//  MSGroup.h
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#ifndef __HelloCpp__MSGroup__
#define __HelloCpp__MSGroup__

#include "MoonSugar.h"
#include <cocos2d.h>

NS_MS_BEGIN
class MSGroupItem : public cocos2d::CCObject
{
public:
    char* name;
};

class MSGroup : public cocos2d::CCObject
{
public:
    MSGroup();
    virtual ~MSGroup();
    
    MSGroupItem* getItem(const char* name);
    MSGroupItem* getItemIndex(unsigned int index);
    
    int addItem(MSGroupItem* item);
    int addItemIndex(MSGroupItem* item, unsigned int index);
    
    MSGroupItem* removeItem(const char* name);
    MSGroupItem* removeItemIndex(unsigned int index);
protected:
    cocos2d::CCArray* items;
    //return index
    int checkItem(const char* name);
};
NS_MS_END;
#endif /* defined(__HelloCpp__MSGroup__) */
