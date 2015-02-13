/*
 * LanguageManager.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: OscarLeif
 */

#include "LanguageManager.h"

LanguageManager* LanguageManager::_instance = 0;

LanguageManager::~LanguageManager() {
	// TODO Auto-generated destructor stub
}

LanguageManager::LanguageManager()
{
    string fileName;
    // detect current language
    switch(Application::getInstance()->getCurrentLanguage())
    {
    case LanguageType::ENGLISH:
        fileName = "en.json";
        break;
    case LanguageType::RUSSIAN:
        fileName = "ru.json";
        break;
	case LanguageType::SPANISH:
		fileName = "es.json";
		break;
    default:
        CCLOG("Unknown language. Use english");
        fileName = "en.json";
        break;
    };

    // below we open, read and parse language data file with rapidjson library
    string clearContent = FileUtils::getInstance()->getStringFromFile(fileName);

    document.Parse<0>(clearContent.c_str());
    if(document.HasParseError())
    {
        CCLOG("Language file parsing error!");
        return;
    }
}

LanguageManager* LanguageManager::getInstance()
{
    if(!_instance)
        _instance = new LanguageManager();
    return _instance;
}

string LanguageManager::getStringForKey(string key)
{
	return document[key.c_str()].GetString();
}
