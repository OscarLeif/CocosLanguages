/*
 * LanguageManager.h
 *
 *  Created on: Feb 1, 2015
 *      Author: OscarLeif
 */

#ifndef LANGUAGEMANAGER_H_
#define LANGUAGEMANAGER_H_

#include <string>
using std::string;

#include "cocos2d.h"
USING_NS_CC;

#include "cocos-ext.h"
using namespace rapidjson;

class LanguageManager {
	Document document;
	LanguageManager();
	static LanguageManager* _instance;
public:
	virtual ~LanguageManager();
	static LanguageManager* getInstance();
	string getStringForKey(string key);
};

#endif /* LANGUAGEMANAGER_H_ */
