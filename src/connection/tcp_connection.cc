#include "tcp_connection.h"
#include <iostream>

const unsigned int BASE_BUFFER_SIZE = 256;  // Store 256 characters

TCP_Connection::TCP_Connection(io_context &context):
    context{context},
    socket{ip::tcp::socket(context)} {
        // Reserve the base-buffer size
        buffer.reserve(sizeof(char)*BASE_BUFFER_SIZE);
        // socket.set_option(boost::asio::socket_base::keep_alive(true));
}

TCP_Connection::~TCP_Connection() {
    std::cout << "tcpDesteuct" << std::endl;
    buffer.clear();
}

// ip::tcp::socket &TCP_Connection::get_socket() {
//     return socket;
// }

// std::vector<char> TCP_Connection::get_buffer() {
//     return buffer;
// }
