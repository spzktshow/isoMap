#ifndef __AssetsManager_FSAssetsManager__
#define __AssetsManager_FSAssetsManager__
#include "fmStatic.h"
#include <cocos2d.h>
#include "MSGroup.h"
NS_FS_BEGIN
class FSAssets : public moonSugar::MSGroupItem
{
public:
	FSAssets(char* datasValue, char* nameValue);
	~FSAssets();
protected:
	char* datas;
};

class FSAssetsCache : public moonSugar::MSGroup
{
public:
	FSAssetsCache();
	~FSAssetsCache();

	static FSAssetsCache* getInstance();
};

class FSAssetsManager : public moonSugar::MSGroup
{
public:
	FSAssetsManager();
	~FSAssetsManager();
	
	static FSAssetsManager* getInstance();
};

NS_FS_END;
#endif