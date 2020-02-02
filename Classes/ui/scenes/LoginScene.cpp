#include "LoginScene.h"

#define PADDING_BOTTOM 80
#define ROW_HEIGHT 20

USING_NS_CC;
using namespace cocos2d::ui;

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

    float labelTextSeparatorX = origin.x + visibleSize.width/2.5;

    Label* labelLogo = Label::createWithTTF("Cantata Online", "fonts/Marker Felt.ttf", 24);
    labelLogo->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - labelLogo->getContentSize().height));
    this->addChild(labelLogo, 1);

    Label* labelLogin = Label::createWithTTF("Login:", "fonts/arial.ttf", 12);
    labelLogin->setAnchorPoint(Point(0.0f, 1.0f));
    labelLogin->setHorizontalAlignment(TextHAlignment::LEFT);
    labelLogin->setPosition(Vec2(labelTextSeparatorX - labelLogin->getContentSize().width - 10,
                                 origin.y + PADDING_BOTTOM + (2 * ROW_HEIGHT)));
    this->addChild(labelLogin);


    TextField* textLogin = TextField::create("john.doe", "Arial", 12);
    textLogin->setAnchorPoint(Point(0.0f, 1.0f));
    textLogin->setPosition(Vec2(labelTextSeparatorX,
                                origin.y + PADDING_BOTTOM + (2 * ROW_HEIGHT)));
    textLogin->setColor(Color3B::GRAY);
    textLogin->setMaxLength(30);
    textLogin->setMaxLengthEnabled(true);
    textLogin->setCursorEnabled(true);
    this->addChild(textLogin);

    Label* labelPassword = Label::createWithTTF("Password:", "fonts/arial.ttf", 12);
    labelPassword->setAnchorPoint(Point(0.0f, 1.0f));
    labelPassword->setPosition(Vec2(labelTextSeparatorX - labelPassword->getContentSize().width - 10,
                                    origin.y + PADDING_BOTTOM + (1 * ROW_HEIGHT)));
    this->addChild(labelPassword);


    TextField* textPassword = TextField::create("password", "Arial", 12);
    textPassword->setAnchorPoint(Point(0.0f, 1.0f));
    textPassword->setPosition(Vec2(labelTextSeparatorX,
                                   origin.y + PADDING_BOTTOM + (1 * ROW_HEIGHT)));
    textPassword->setCursorEnabled(true);
    // textPassword->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    textPassword->setPasswordEnabled(true);
    textPassword->setColor(Color3B::GRAY);
    textPassword->setMaxLength(30);
    textPassword->setMaxLengthEnabled(true);
    this->addChild(textPassword);

    Button *btnLogin = Button::create();
    btnLogin->setTitleText("Log In");
    btnLogin->setAnchorPoint(Point(0.0f, 1.0f));
    btnLogin->setPosition(Vec2(labelTextSeparatorX,
                               origin.y + PADDING_BOTTOM + (0 * ROW_HEIGHT)));

    this->addChild(btnLogin);


    return true;
}