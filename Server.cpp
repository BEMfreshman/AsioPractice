//
// Created by wenluyang on 2020/3/8.
//

#include "Server.h"
#include "Session.h"

Server::Server(boost::asio::io_context& io,
                const string& hostip,
                short port)
        :ep(tcp::endpoint(boost::asio::ip::address::from_string(hostip),
                          port)),
         acceptor(io)
{
    acceptor.bind(ep);
}

Server::Server(boost::asio::io_context& io):acceptor(io)
{

}

Server::Server(boost::asio::io_context& io,short port)
    :ep(tcp::endpoint(tcp::v4(),port)),
    acceptor(io)
{
    acceptor.bind(ep);
}

void Server::build_and_bindep(const string &hostip, short port) {
    if (hostip.empty()) {
        ep = tcp::endpoint(tcp::v4(),port);
    }
    else {
        ep = tcp::endpoint(boost::asio::ip::address::from_string(hostip),port);
    }

    acceptor.bind(ep);
}

void Server::start_listen()
{
    while(1) {
        Session newSession(acceptor.accept());
        thread thrd(bind(&Session::DoReadAndSend,&newSession));
        thrd.detach();
    }
}