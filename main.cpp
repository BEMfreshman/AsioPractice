#include <iostream>
#include <boost/asio.hpp>
#include <gflags/gflags.h>

#include "Server.h"
#include "Client.h"

using namespace std;
using namespace boost;


DEFINE_string(type,"Server,Client","Type");
DEFINE_string(ip,"","remote host ip");
DECLARE_int32(port);
DEFINE_int32(port,8000,"listen port");

int main(int argc, char* argv[])
{
    boost::asio::io_context io;
    google::ParseCommandLineFlags(&argc,&argv,true);
    if (FLAGS_type == "Server") {
        // start server
        Server server(io);
        server.build_and_bindep(FLAGS_ip, FLAGS_port);
        server.start_listen();
    }
    else if (FLAGS_type == "Client") {
        // start Client
        if (FLAGS_ip.empty()) {
            cerr << "remote host ip is empty, exit" << endl;
            exit(0);
        }
        Client client(io,FLAGS_ip,FLAGS_port);

    }
    else {
        cerr << "Unknown Type, EXIT" << endl;
        exit(0);
    }
}

