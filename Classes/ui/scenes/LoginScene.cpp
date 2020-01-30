#include "LoginScene.h"

USING_NS_CC;

Scene* LoginScene::createScene()
{
    return LoginScene::create();
}

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

    Label* labelLogin = Label::createWithTTF("Login:", "fonts/arial.ttf", 12);
    labelLogin->setPosition(Vec2(origin.x + visibleSize.width/4,
                                 origin.y + visibleSize.height - labelLogin->getContentSize().height - 40));
    this->addChild(labelLogin);


    cocos2d::ui::TextField* textLogin = cocos2d::ui::TextField::create("john.doe", "Arial", 12);
    textLogin->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - textLogin->getContentSize().height - 40));
    textLogin->setTextHorizontalAlignment(TextHAlignment::LEFT);
    this->addChild(textLogin);

    Label* labelPassword = Label::createWithTTF("Password:", "fonts/arial.ttf", 12);
    labelPassword->setPosition(Vec2(origin.x + visibleSize.width/4,
                                 origin.y + visibleSize.height - labelPassword->getContentSize().height - 60));
    this->addChild(labelPassword);


    cocos2d::ui::TextField* textPassword = cocos2d::ui::TextField::create("john.doe", "Arial", 12);
    textPassword->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - textPassword->getContentSize().height - 60));
    textPassword->setTextHorizontalAlignment(TextHAlignment::LEFT);
    textPassword->setPasswordEnabled(true);
    this->addChild(textPassword);


    return true;
}