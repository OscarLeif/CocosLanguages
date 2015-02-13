/*//
 * LanguageManager.h
 *
 *  Created on: Feb 1, 2015
 *      Author: OscarLeif
 */

#ifndef LANGUAGEMANAGER_H_
#define LANGUAGEMANAGER_H_

//#include "cocos-ext.h"
//#include <string>

#include "cocos2d.h"
#include "json\rapidjson.h"
#include "json\document.h"

using std::string;
USING_NS_CC;

using namespace rapidjson;

class LanguageManager{
public:
	Document document;
	LanguageManager();
	virtual ~LanguageManager();
	static LanguageManager* _instance;
	static LanguageManager* getInstance();
	string getStringForKey(string key);
};

#endif /* LANGUAGEMANAGER_H_ */
