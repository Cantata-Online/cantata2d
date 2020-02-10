#ifndef __NETWORK_CONNECTOR_CONNECTOR_H__
#define __NETWORK_CONNECTOR_CONNECTOR_H__

#include <string>
#include <boost/asio.hpp>

#include "../packets/AbstractPacket.h"
#include "../../system/Result.h"

/**
@brief Responsible for client-server UDP connection.
*/
class UdpConnector
{
    public:
        static UdpConnector* getInstance();
        Result<int, string> send(AbstractPacket *packet);
};

#endif