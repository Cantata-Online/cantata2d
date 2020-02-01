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


    Label* labelLogo = Label::createWithTTF("Cantata Online", "fonts/Marker Felt.ttf", 24);
    labelLogo->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - labelLogo->getContentSize().height));
    this->addChild(labelLogo, 1);

    Label* labelLogin = Label::createWithTTF("Login:", "fonts/arial.ttf", 12);
    labelLogin->setPosition(Vec2(origin.x + visibleSize.width/4 + labelLogin->getContentSize().width/2,
                                 origin.y + 120));
    this->addChild(labelLogin);


    cocos2d::ui::TextField* textLogin = cocos2d::ui::TextField::create("john.doe", "Arial", 12);
    textLogin->setPosition(Vec2(origin.x + visibleSize.width/2 + textLogin->getContentSize().width/2,
                                origin.y + 120));
    textLogin->setColor(Color3B::GRAY);
    textLogin->setMaxLength(30);
    textLogin->setMaxLengthEnabled(true);
    textLogin->setTextHorizontalAlignment(TextHAlignment::LEFT);
    textLogin->setCursorEnabled(true);
    textLogin->setTextAreaSize(Size(100, 15));
    textLogin->setContentSize(Size(100, 15));
    this->addChild(textLogin);

    Label* labelPassword = Label::createWithTTF("Password:", "fonts/arial.ttf", 12);
    labelPassword->setPosition(Vec2(origin.x + visibleSize.width/4 + labelPassword->getContentSize().width/2,
                                    origin.y + 100));
    this->addChild(labelPassword);


    cocos2d::ui::TextField* textPassword = cocos2d::ui::TextField::create("password", "Arial", 12);
    textPassword->setPosition(Vec2(origin.x + visibleSize.width/2 + textPassword->getContentSize().width/2,
                                   origin.y + 100));
    textPassword->setCursorEnabled(true);
    textPassword->setPasswordEnabled(true);
    textPassword->setColor(Color3B::GRAY);
    textPassword->setMaxLength(30);
    textPassword->setMaxLengthEnabled(true);
    textPassword->setTextHorizontalAlignment(TextHAlignment::LEFT);
    textPassword->setTextAreaSize(Size(100, 15));
    textPassword->setContentSize(Size(100, 15));
    this->addChild(textPassword);

    cocos2d::ui::Button *btnLogin = cocos2d::ui::Button::create();
    btnLogin->setTitleText("Log In");
    btnLogin->setPosition(Vec2(origin.x + visibleSize.width/2 + btnLogin->getContentSize().width/2,
                                   origin.y + 80));

    this->addChild(btnLogin);


    return true;
}