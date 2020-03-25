#include "CharSelectScene.h"

USING_NS_CC;
using namespace cocos2d::ui;

CharSelectScene* CharSelectScene::createScene()
{
    return CharSelectScene::create();
}

bool CharSelectScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    float labelTextSeparatorX = origin.x + visibleSize.width/2.5;

    Label* labelLogo = Label::createWithTTF("Character selection", UI_FONT_TRADITIO, 24);
    labelLogo->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - labelLogo->getContentSize().height));
    this->addChild(labelLogo, 1);

    return true;
}