#ifndef __NETWORK_CONNECTOR_CONNECTOR_H__
#define __NETWORK_CONNECTOR_CONNECTOR_H__

#include <boost/asio.hpp>

#include "../packets/AbstractPacket.h"

/**
@brief Responsible for client-server UDP connection.
*/
class UdpConnector
{
    public:
        static UdpConnector* getInstance();
        void send(AbstractPacket *packet);
};

#endif