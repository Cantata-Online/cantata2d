#ifndef __NETWORK_CONNECTOR_CONNECTOR_H__
#define __NETWORK_CONNECTOR_CONNECTOR_H__

#include <string>

#include <boost/asio.hpp>

#include "../packets/AbstractPacket.h"
#include "../../system/Result.h"
#include "Server.h"

using namespace boost::asio::ip;

/**
@brief Responsible for client-server UDP connection.
*/
class UdpConnector
{
    public:
        ~UdpConnector();

        Result<bool, string> connect(Server server);
        Result<bool, string> send(AbstractPacket *packet);

        static UdpConnector* getInstance();
    private:
        udp::socket *udpSocket;
        udp::endpoint remoteEndpoint;
};

#endif