#ifndef __UI_SCENES_MAIN_MENU_SCENE_H__
#define __UI_SCENES_MAIN_MENU_SCENE_H__

#include <string>
#include <vector>

#include <boost/asio.hpp>
#include <yaml-cpp/yaml.h>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "network/connector/Server.h"
#include "network/connector/UdpConnector.h"
#include "network/packets/LoginPacket.h"
#include "network/packets/LoginResponsePacket.h"
#include "system/Result.h"

using namespace std;
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

    vector<Server> servers;

    void initServerList();

    void buttonLoginPressed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
};

#endif