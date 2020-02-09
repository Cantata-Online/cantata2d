#include "LoginScene.h"

#define PADDING_BOTTOM 80
#define ROW_HEIGHT 20

#define ACTION_LOGIN 1

USING_NS_CC;
using namespace cocos2d::ui;


void initTextFieldProperties(TextField* textField)
{
    textField->setAnchorPoint(Point(0.0f, 1.0f));
    textField->setCursorEnabled(true);
    textField->setColor(Color3B::GRAY);
    textField->setMaxLength(30);
    textField->setMaxLengthEnabled(true);
}

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
    labelLogin->setPosition(Vec2(labelTextSeparatorX - labelLogin->getContentSize().width - 10,
                                 origin.y + PADDING_BOTTOM + (2 * ROW_HEIGHT)));
    this->addChild(labelLogin);

    this->textLogin = TextField::create("john.doe", "Arial", 12);
    this->textLogin->setPosition(Vec2(labelTextSeparatorX,
                                origin.y + PADDING_BOTTOM + (2 * ROW_HEIGHT)));
    initTextFieldProperties(this->textLogin);
    this->addChild(this->textLogin);

    Label* labelPassword = Label::createWithTTF("Password:", "fonts/arial.ttf", 12);
    labelPassword->setAnchorPoint(Point(0.0f, 1.0f));
    labelPassword->setPosition(Vec2(labelTextSeparatorX - labelPassword->getContentSize().width - 10,
                                    origin.y + PADDING_BOTTOM + (1 * ROW_HEIGHT)));
    this->addChild(labelPassword);


    this->textPassword = TextField::create("password", "Arial", 12);
    this->textPassword->setPosition(Vec2(labelTextSeparatorX,
                                   origin.y + PADDING_BOTTOM + (1 * ROW_HEIGHT)));
    this->textPassword->setPasswordEnabled(true);
    initTextFieldProperties(this->textPassword);
    this->addChild(this->textPassword);

    Button *btnLogin = Button::create();
    btnLogin->setTitleText("Log In");
    btnLogin->setAnchorPoint(Point(0.0f, 1.0f));
    btnLogin->setPosition(Vec2(labelTextSeparatorX,
                               origin.y + PADDING_BOTTOM + (0 * ROW_HEIGHT)));
    btnLogin->setActionTag(ACTION_LOGIN);
    btnLogin->addTouchEventListener( CC_CALLBACK_2(LoginScene::buttonLoginPressed, this));
    this->addChild(btnLogin);

    this->labelStatus = Label::createWithTTF("", "fonts/arial.ttf", 8);
    this->labelStatus->setAnchorPoint(Point(0.0f, 1.0f));
    this->labelStatus->setPosition(Vec2(labelTextSeparatorX,
                                 origin.y + PADDING_BOTTOM - (1 * ROW_HEIGHT)));
    this->addChild(this->labelStatus);


    return true;
}

void LoginScene::buttonLoginPressed(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType) {
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        this->labelStatus->setString("Connecting...");

        UdpConnector *connector = UdpConnector::getInstance();

        LoginPacket login;
        login.setLogin(this->textLogin->getString().c_str());
        login.setPassword(this->textPassword->getString().c_str());

        connector->send(&login);
    }
}