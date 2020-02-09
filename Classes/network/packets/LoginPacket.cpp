#include "LoginPacket.h"

#include <iostream>

#define PACKET_CODE_LOGIN 0x0010

LoginPacket::LoginPacket()
{
    this->payload.header = PACKET_CODE_LOGIN;
}

char* LoginPacket::toChar()
{
    return reinterpret_cast<char*>(&this->payload);
}

unsigned short int LoginPacket::getSize()
{
    return sizeof(LoginPacket);
}

void LoginPacket::setLogin(const char *login)
{
    strncpy(this->payload.login, login, TEXT_MAX_LEN * sizeof(char));
}

void LoginPacket::setPassword(const char *password)
{
    strncpy(this->payload.password, password, TEXT_MAX_LEN * sizeof(char));
}