#ifndef __UI_SCENES_MAIN_MENU_SCENE_H__
#define __UI_SCENES_MAIN_MENU_SCENE_H__

#include <boost/asio.hpp>
#include <iostream>
#include <string>

#include "cocos2d.h"
#include "network/connector/UdpConnector.h"
#include "network/packets/LoginPacket.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

/**
 * Login screen
 */
class LoginScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(LoginScene);

private:
    Label* labelStatus;
    TextField* textLogin;
    TextField* textPassword;

    void buttonLoginPressed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
};

#endif