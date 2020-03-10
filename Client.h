//
// Created by wenluyang on 2020/3/9.
//

#ifndef ASIOPRACTICE_CLIENT_H
#define ASIOPRACTICE_CLIENT_H

#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;


class Client {

public:
    Client(boost::asio::io_context& io,
            const string& hostip,
            const string& port);
    void EchoClient();

private:
    tcp::socket socket;
    tcp::endpoint hostep;
};


#endif //ASIOPRACTICE_CLIENT_H
