#include "LoginScene.h"


// using namespace ui;

USING_NS_CC;

Scene* LoginScene::createScene()
{
    return LoginScene::create();
}

// on "init" you need to initialize your instance
bool LoginScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto label = Label::createWithTTF("Cantata Online", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        return false;
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    return true;
}