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

Result<int, string> UdpConnector::doSend(char* input, int inputSize, char* output, int outputSize)
{
    Result<int, string> result;
    boost::system::error_code err;
    this->udpSocket->send_to(boost::asio::buffer(input, inputSize), this->remoteEndpoint, 0, err);
    if (err.value() != 0) {
        result.setError(err.message());
        return result;
    }

    int receivedBytes = this->udpSocket->receive(boost::asio::buffer(output, outputSize));
    result.setSuccess(receivedBytes);
    return result;
}