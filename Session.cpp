//
// Created by wenluyang on 2020/3/8.
//

#include "Session.h"
#include "UtilityValue.h"

Session::Session(tcp::socket socket_)
    :socket(std::move(socket_))
{

}

void Session::DoReadAndSend(){

}

void Session::EchoMode() {
    char message[MAXLINE];

    boost::system::error_code ec;
    socket.read_some(boost::asio::buffer(message),ec);
    if (ec == boost::asio::error::eof) {
        cout << "Read EOF from Client" << getClientIP() << ":" << getClientPort() << endl;
    }

    boost::asio::write(socket,boost::asio::buffer(message,strlen(message)));
}

string Session::getClientIP() {
    return socket.remote_endpoint().address().to_string();
}

short Session::getClientPort() {
    return socket.remote_endpoint().port();
}