#include "LoginResponsePacket.h"

#define PACKET_CODE_LOGIN_RESPONSE 0x0011

LoginResponsePacket::LoginResponsePacket()
{
    this->payload.header = PACKET_CODE_LOGIN_RESPONSE;
}

char* LoginResponsePacket::toChar()
{
    return reinterpret_cast<char*>(&this->payload);
}

unsigned short int LoginResponsePacket::getSize()
{
    return sizeof(LoginResponsePacket);
}