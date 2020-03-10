//
// Created by wenluyang on 2020/3/8.
//

#include "Session.h"
#include "UtilityValue.h"

Session::Session(tcp::socket socket_)
    :socket(std::move(socket_))
{
    socket.set_option(tcp::socket::reuse_address(true));
    cout << "connect Client with IP: " << getClientIP() << " and Port: " << getClientPort() << endl;
}

void Session::run() {
    EchoMode();
}

void Session::DoReadAndSend(){

}

void Session::EchoMode() {
    char message[MAXLINE] = "";

    while(1) {
        boost::system::error_code ec;
        memset(message,0,MAXLINE);
        size_t len = socket.read_some(boost::asio::buffer(message),ec);
        if (ec == boost::asio::error::eof) {
            cout << "Read EOF from Client" << getClientIP() << ":" << getClientPort() << endl;
            break;
        }
        message[len] = '\0';
        boost::asio::write(socket,boost::asio::buffer(message,len+1));
    }
}

string Session::getClientIP() {
    return socket.remote_endpoint().address().to_string();
}

size_t Session::getClientPort() {
    return socket.remote_endpoint().port();
}