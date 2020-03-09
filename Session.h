//
// Created by wenluyang on 2020/3/8.
//

#ifndef ASIOPRACTICE_SESSION_H
#define ASIOPRACTICE_SESSION_H

#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using boost::asio::ip::tcp;

class Session
        :public enable_shared_from_this<Session>
{
public:
    typedef shared_ptr<Session> pointer;

    Session(tcp::socket socket);

    void EchoMode();

    void DoReadAndSend();

private:
    string getClientIP();
    short  getClientPort();

private:
    tcp::socket socket;
};


#endif //ASIOPRACTICE_SESSION_H
