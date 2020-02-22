#include "UdpConnector.h"

using namespace boost;
using namespace boost::asio;

UdpConnector* udpConnectorInstance = nullptr;

UdpConnector::~UdpConnector()
{
    if (nullptr != this->udpSocket)
    {
        if (this->udpSocket->is_open())
        {
            this->udpSocket->close();
        }
        delete this->udpSocket;
    }
}

UdpConnector* UdpConnector::getInstance()
{
    if (nullptr == udpConnectorInstance)
    {
        udpConnectorInstance = new UdpConnector();
    }

    return udpConnectorInstance;
}

Result<bool, string> UdpConnector::connect(Server server)
{
    Result<bool, string> result;
    boost::asio::io_service io_service;
    this->udpSocket = new boost::asio::ip::udp::socket(io_service);
    this->udpSocket->open(boost::asio::ip::udp::v4());
    asio::ip::udp::resolver::query resolver_query(server.host, std::to_string(server.port), asio::ip::udp::resolver::query::numeric_service);
    asio::ip::udp::resolver resolver(io_service);
    boost::system::error_code err;
    asio::ip::udp::resolver::iterator it = resolver.resolve(resolver_query, err);
    if (err.value() != 0) {
        result.setError(err.message());
        return result;
    }

    asio::ip::udp::resolver::iterator it_end;
    for (; it != it_end; ++it) {
        this->remoteEndpoint = it->endpoint();
    }

    result.setSuccess(true);
    return result;
}

Result<bool, string> UdpConnector::send(AbstractPacket *packet)
{
    Result<bool, string> result;
    char* data = packet->toChar();


    boost::system::error_code err;
    this->udpSocket->send_to(boost::asio::buffer(data, packet->getSize()), this->remoteEndpoint, 0, err);
    if (err.value() != 0) {
        result.setError(err.message());
        return result;
    }

    char *buffer = new char[100];
    memset(buffer, '0', 100);
    this->udpSocket->receive(boost::asio::buffer(buffer, 100));
    result.setSuccess(true);
    return result;
}