#ifndef __NETWORK_PACKETS_LOGIN_H__
#define __NETWORK_PACKETS_LOGIN_H__

#include <string.h>

#define TEXT_MAX_LEN 30

class PacketLogin
{
    public:
        unsigned short int header;
        char login[TEXT_MAX_LEN + 1];
        char password[TEXT_MAX_LEN + 1];

        PacketLogin();
        char* toChar();
        void setLogin(const char *login);
        void setPassword(const char *password);
};

#endif