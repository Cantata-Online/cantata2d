#ifndef __NETWORK_PACKETS_ABSTRACT_H__
#define __NETWORK_PACKETS_ABSTRACT_H__

class AbstractPacket
{
    public:
        virtual  unsigned short int getSize() = 0;
        virtual char *toChar() = 0;
};

#endif