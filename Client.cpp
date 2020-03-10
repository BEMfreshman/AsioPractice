//
// Created by wenluyang on 2020/3/9.
//

#include "Client.h"
#include "UtilityValue.h"
#include <iostream>


Client::Client(boost::asio::io_context& io,
                const string& hostip,
                short port) : socket(io)

{
    hostep = tcp::endpoint(boost::asio::ip::address::from_string(hostip),port);
    try{
        socket.connect(hostep);
    }
    catch (std::exception& e) {
        throw e;
    }

}

void Client::EchoClient()
{
    char message[MAXLINE];
    char recvline[MAXLINE];

    cout << "Please enter something:" << endl;

    boost::system::error_code ec;
    while (fgets(message,MAXLINE,stdin) != NULL) {
        size_t len = strlen(message);
        boost::asio::write(socket,boost::asio::buffer(message,len),ec);

        socket.read_some(boost::asio::buffer(recvline),ec);
        if (ec == boost::asio::error::eof){
            cerr << "Read EOF from server, Client will shutdown" << endl;
            exit(0);
        }

        cout << recvline << endl;
        cout << "Please enter something:" << endl;
    }

}