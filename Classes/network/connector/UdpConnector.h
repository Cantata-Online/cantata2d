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

        template<typename I, typename O>
        Result<O, string> send(I requestPacket)
        {
            Result<O, string> result;
            int inputSize = sizeof(I);
            int outputSize = sizeof(O);

            char *inputData = reinterpret_cast<char*>(&requestPacket.payload);
            char outputData[outputSize];
            memset(outputData, '\0', outputSize);
            Result<int, string> sendResult = this->doSend(inputData, inputSize, outputData, outputSize);

            if (sendResult.isSucceeded)
            {
                O outPacket;
                memcpy(&outPacket.payload, outputData, outputSize);
                result.setSuccess(outPacket);
            }
            else
            {
                result.setError(sendResult.error);
            }

            return result;
        }

        static UdpConnector* getInstance();
    private:
        udp::socket *udpSocket;
        udp::endpoint remoteEndpoint;

        Result<int, string> doSend(char* input, int inputSize, char* output, int outputSize);
};

#endif