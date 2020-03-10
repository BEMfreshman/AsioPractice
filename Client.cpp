//
// Created by wenluyang on 2020/3/9.
//

#include "Client.h"
#include "UtilityValue.h"
#include <iostream>
#include <stdlib.h>


Client::Client(boost::asio::io_context& io,
                const string& hostip,
                const string& port) : socket(io)

{
    hostep = tcp::endpoint(boost::asio::ip::address::from_string(hostip),atoi(port.c_str()));
    try{
//        socket.connect(hostep);
        tcp::resolver resolver(io);
        boost::asio::connect(socket,resolver.resolve(hostip,port));
    }
    catch (std::exception& e) {
        throw e;
    }

}

void Client::EchoClient()
{
    char message[MAXLINE] = "";
    char recvline[MAXLINE] = "";

    cout << "Please enter something:" << endl;

    boost::system::error_code ec;
    while (fgets(message,MAXLINE,stdin) != NULL) {
        size_t len = strlen(message);

        boost::asio::write(socket,boost::asio::buffer(message,len));

        socket.read_some(boost::asio::buffer(recvline),ec);
        if (ec == boost::asio::error::eof){
            break;
        }
        else if (ec) {
            throw boost::system::system_error(ec);
        }

        fputs(recvline,stdout);
        cout << "Please enter something:" << endl;
    }

}