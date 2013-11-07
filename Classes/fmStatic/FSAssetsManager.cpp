#include "FSAssetsManager.h"
USING_NS_CC;

NS_FS_BEGIN
/***FSAssets**/
FSAssets::FSAssets(char* datasValue, char* nameValue)
{
	datas = datasValue;
	name = nameValue;
}

FSAssets::~FSAssets()
{
	delete datas;
	delete name;
}


NS_FS_END;