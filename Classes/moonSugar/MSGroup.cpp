//
//  MSGroup.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#include "MSGroup.h"
USING_NS_CC;
NS_MS_BEGIN
/**************Group******/
MSGroup::MSGroup()
{
    items = new CCArray;
}

MSGroup::~MSGroup()
{
    delete items;
}

MSGroupItem* MSGroup::getItem(const char *name)
{
    int index = checkItem(name);
    if (index != -1)
    {
        return (MSGroupItem*) items->objectAtIndex(index);
    }
    return NULL;
}

MSGroupItem* MSGroup::getItemIndex(unsigned int index)
{
    if (index < items->count())
    {
        return (MSGroupItem*) items->objectAtIndex(index);
    }
    return NULL;
}

int MSGroup::addItem(moonSugar::MSGroupItem *item)
{
    if (checkItem(item->name) == -1)
    {
        items->addObject(item);
        return items->count() - 1;
    }
    return -1;
}

int MSGroup::addItemIndex(moonSugar::MSGroupItem *item, unsigned int index)
{
    if (checkItem(item->name) == -1)
    {
        items->insertObject(item, index);
        return index;
    }
    return -1;
}

MSGroupItem* MSGroup::removeItem(const char *name)
{
    int index = checkItem(name);
    if (index != -1) {
        return removeItemIndex(index);
    }
    return NULL;
}

MSGroupItem* MSGroup::removeItemIndex(unsigned int index)
{
    if (index < items->count())
    {
        MSGroupItem* item = (MSGroupItem*) items->objectAtIndex(index);
        items->removeObjectAtIndex(index);
        return item;
    }
    return NULL;
}

int MSGroup::checkItem(const char *name)
{
    CCObject* arrObject;
    int index = 0;
    CCARRAY_FOREACH(items, arrObject)
    {
        MSGroupItem* groupItem = (MSGroupItem*)arrObject;
        if (!groupItem) continue;
        if (strcmp(groupItem->name, name) == 0)
        {
            return index;
        }
        index ++;
    }
    return -1;
}

NS_MS_END;