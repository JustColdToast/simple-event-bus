#ifndef SEB_C_TCPCONNECTION
#define SEB_C_TCPCONNECTION

#include <boost/asio.hpp>
#include <vector>
#include <string>

using namespace boost::asio;

/*
A TCP_Connection represents an open TCP socket and related monitoring data
*/
struct TCP_Connection {
    io_context &context;           // Ref to io_context that the TCP_Connection exists under
    ip::tcp::socket socket;        // The socket corresponding to a TCP Connection
    std::vector<unsigned char> buffer;        // Represents a data buffer
    
    TCP_Connection(io_context &context);
    ~TCP_Connection();
    
};

#endif