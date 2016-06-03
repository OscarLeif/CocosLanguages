//
// Created by OscarLeif on 6/1/2016.
//

#ifndef PROJ_ANDROID_STUDIO_LANGUAGEMANAGER_H
#define PROJ_ANDROID_STUDIO_LANGUAGEMANAGER_H


#include <string>
using std::string;

#include "../cocos2d/external/json/document.h"
#include "../cocos2d/external/json/rapidjson.h"

using namespace rapidjson;

class LanguageManager
{
    Document _document;
    LanguageManager();
    static LanguageManager* _instance;
public:
    static LanguageManager* getInstance();
    string getStringForKey(string key) const;
};


#endif //PROJ_ANDROID_STUDIO_LANGUAGEMANAGER_H
