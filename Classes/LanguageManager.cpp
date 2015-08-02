#include "LanguageManager.h"

#include "cocos2d.h"
using namespace cocos2d;

LanguageManager* LanguageManager::_instance = 0;

LanguageManager::LanguageManager()
{
	string fileName;
	// detect current language
	switch (Application::getInstance()->getCurrentLanguage())
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

	_document.Parse<0>(clearContent.c_str());
	if (_document.HasParseError())
	{
		CCLOG("Language file parsing error!");
		log("Language file parsing error!");
		return;
	}
}

LanguageManager* LanguageManager::getInstance()
{
	if (!_instance)
		_instance = new LanguageManager();
	return _instance;
}

string LanguageManager::getStringForKey(string key) const
{
	return _document[key.c_str()].GetString();
}
