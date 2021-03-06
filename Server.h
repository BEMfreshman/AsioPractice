//
// Created by wenluyang on 2020/3/8.
//

#ifndef ASIOPRACTICE_SERVER_H
#define ASIOPRACTICE_SERVER_H

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>
#include <vector>

using namespace std;
using boost::asio::ip::tcp;

class Server {

public:
    Server(boost::asio::io_context& io);

    void build_and_bindep(const string& hostip, const string& port);
    void start_listen();

    ~Server() {};

private:


private:
    tcp::endpoint ep;

    tcp::acceptor acceptor;

};


#endif //ASIOPRACTICE_SERVER_H
