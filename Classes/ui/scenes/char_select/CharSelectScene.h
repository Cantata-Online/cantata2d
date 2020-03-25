#ifndef __UI_SCENES_CHAR_SELECT_SCENE_H__
#define __UI_SCENES_CHAR_SELECT_SCENE_H__

#include "cocos2d.h"
#include "ui/fonts.h"
#include "ui/CocosGUI.h"

using namespace std;
USING_NS_CC;
using namespace cocos2d::ui;

/**
 * CharacterSelection
 */
class CharSelectScene : public cocos2d::Scene
{
public:
    static CharSelectScene* createScene();

    virtual bool init();
    
    CREATE_FUNC(CharSelectScene);
};

#endif