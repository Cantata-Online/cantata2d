#include "UdpConnector.h"

using namespace boost;
using namespace boost::asio;

UdpConnector* udpConnectorInstance = nullptr;

UdpConnector* UdpConnector::getInstance()
{
    if (nullptr == udpConnectorInstance)
    {
        udpConnectorInstance = new UdpConnector();
    }

    return udpConnectorInstance;
}

Result<int, string> UdpConnector::send(AbstractPacket *packet)
{
    Result<int, string> result;
    char* data = packet->toChar();

    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket socket(io_service);
    boost::asio::ip::udp::endpoint remote_endpoint;
    socket.open(boost::asio::ip::udp::v4());

    asio::ip::udp::resolver::query resolver_query("localhost", "2300", asio::ip::udp::resolver::query::numeric_service);
    asio::ip::udp::resolver resolver(io_service);
    boost::system::error_code err;
    asio::ip::udp::resolver::iterator it = resolver.resolve(resolver_query, err);
    if (err.value() != 0) {
        result.setError(err.message());
        return result;
    }

    asio::ip::udp::resolver::iterator it_end;
    for (; it != it_end; ++it) {
        remote_endpoint = it->endpoint();
    }

    socket.send_to(boost::asio::buffer(data, packet->getSize()), remote_endpoint, 0, err);
    if (err.value() != 0) {
        result.setError(err.message());
        return result;
    }

    socket.close();
    result.setSuccess(0);
    return result;
}