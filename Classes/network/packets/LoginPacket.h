#ifndef __NETWORK_PACKETS_LOGIN_H__
#define __NETWORK_PACKETS_LOGIN_H__

#include <string.h>

#include "AbstractPacket.h"

#define TEXT_MAX_LEN 30

struct LoginPacketPayload {
    unsigned short int header;
    char login[TEXT_MAX_LEN + 1];
    char password[TEXT_MAX_LEN + 1];
};

class LoginPacket: public AbstractPacket
{
    public:
        LoginPacketPayload payload;

        LoginPacket();
        char* toChar();
        unsigned short int getSize();
        void setLogin(const char *login);
        void setPassword(const char *password);
};

#endif