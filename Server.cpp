//
// Created by wenluyang on 2020/3/8.
//

#include "Server.h"
#include "Session.h"

Server::Server(boost::asio::io_context& io):acceptor(io)
{

}


void Server::build_and_bindep(const string &hostip, const string& port) {
    if (hostip.empty()) {
        ep = tcp::endpoint(tcp::v4(),atoi(port.c_str()));
    }
    else {
        ep = tcp::endpoint(boost::asio::ip::address::from_string(hostip),atoi(port.c_str()));
    }

    acceptor.open(ep.protocol());
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    acceptor.bind(ep);
    acceptor.listen();
}

void Server::start_listen()
{
    while(1) {
//        Session newSession(acceptor.accept());
//        thread thrd(bind(&Session::run,&newSession));
//        thrd.detach();

        Session newSession(acceptor.accept());
        newSession.run();
    }
}