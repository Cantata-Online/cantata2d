#include "UdpConnector.h"

UdpConnector* udpConnectorInstance = nullptr;

UdpConnector* UdpConnector::getInstance()
{
    if (nullptr == udpConnectorInstance)
    {
        udpConnectorInstance = new UdpConnector();
    }

    return udpConnectorInstance;
}

void UdpConnector::send(AbstractPacket *packet)
{
    char* data = packet->toChar();

    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket(io_service);
    boost::asio::ip::udp::endpoint remote_endpoint;
    socket.open(boost::asio::ip::udp::v4());
    remote_endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 2300);
    boost::system::error_code err;
    socket.send_to(boost::asio::buffer(data, packet->getSize()), remote_endpoint, 0, err);
    socket.close();

    // free(data);
}