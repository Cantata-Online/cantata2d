#ifndef __UI_SCENES_MAIN_MENU_SCENE_H__
#define __UI_SCENES_MAIN_MENU_SCENE_H__

#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"

/**
 * Login screen
 */
class LoginScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(LoginScene);
};

#endif