#ifndef __NETWORK_PACKETS_LOGIN_RESPONSE_H__
#define __NETWORK_PACKETS_LOGIN_RESPONSE_H__

// #include <string.h>

#include "AbstractPacket.h"


struct LoginResponsePacketPayload {
    unsigned short int header;
    bool status;
    char token[16 + 1];
};

class LoginResponsePacket: public AbstractPacket
{
    public:
        LoginResponsePacketPayload payload;

        LoginResponsePacket();
        char* toChar();
        unsigned short int getSize();
};

#endif