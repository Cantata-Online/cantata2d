#ifndef __NETWORK_CONNECTOR_SERVER_H__
#define __NETWORK_CONNECTOR_SERVER_H__

#include <string>

using namespace std;

class Server
{
    public:
        string cerfificatePath;
        string certificate;
        string host;
        string name;
        int port;
};

#endif