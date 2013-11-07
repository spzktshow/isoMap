//
//  MSMvc.cpp
//  HelloCpp
//
//  Created by RockLee on 13-9-29.
//
//

#include "MSMvc.h"

USING_NS_CC;
NS_MS_BEGIN

/*****************model****************/
MSModel* MSModel::model;

MSModel* MSModel::getInstance()
{
    if (NULL == model)
    {
        model = new MSModel;
    }
    return model;
}

void MSModel::release()
{
    delete model;
}

void MSModel::registerModel(MSModelData* modelData)
{
	int index = this->addItem(modelData);
	if (index != -1)
	{
		modelData->init();
	}
}

void MSModel::removeModel(MSModelData* modelData)
{
	modelData = (MSModelData*) this->removeItem(modelData->name);
	modelData->dispose();

	delete modelData;
}
/***************modelData***************/

MSModelData::MSModelData()
{
	notificationCenter = CCNotificationCenter::sharedNotificationCenter();
}

MSModelData::~MSModelData()
{
	notificationCenter = NULL;
}

void MSModelData::init()
{


}

void MSModelData::dispose()
{

}


MSModelData* MSModel::createModelData()
{
	return NULL;
}
NS_MS_END;