#include "Login.h"

#include <iostream>

PacketLogin::PacketLogin()
{
    this->header = 0x0010;
}

char* PacketLogin::toChar()
{
    char data[sizeof(PacketLogin)] = "";
    memcpy(&data, this, sizeof(PacketLogin));
    char *ptr = data;
    return ptr;
}

void PacketLogin::setLogin(const char *login)
{
    strncpy(this->login, login, TEXT_MAX_LEN * sizeof(char));
}

void PacketLogin::setPassword(const char *password)
{
    strncpy(this->password, password, TEXT_MAX_LEN * sizeof(char));
}