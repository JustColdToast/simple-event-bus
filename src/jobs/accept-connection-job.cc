#include "accept-connection-job.h"
#include <iostream>
#include <boost/coroutine2/all.hpp>
#include <administration/constants.h>



AcceptConnectionJob::AcceptConnectionJob(Administrator *admin, boost::asio::io_context * p_context, boost::asio::ip::tcp::acceptor *acceptor): 
    admin{admin},
    p_context{p_context},
    acceptor{acceptor},
    strand{boost::asio::make_strand(*p_context)} { }

AcceptConnectionJob::~AcceptConnectionJob() {
    // TODO: flesh out destructor
    std::cout << "AcceptConnectionJob Destructor Called" << std::endl;
    delete connection;
}

void AcceptConnectionJob::mainloop(context& suspend) {
    for (;;) {
        std::cout << "S" << std::endl;
        accept_connection();
        suspend();
        receive_client_identity();
        suspend();
        create_client();
        std::cout << "E" << std::endl;
        dispatch();
        suspend();
    }
}

void AcceptConnectionJob::dispatch() {
    boost::asio::dispatch(strand, std::bind([](CorJob* obj) { obj->operator()(); }, this));
}

void AcceptConnectionJob::accept_connection() {
    std::cout << "SA" << std::endl;
    connection = new TCP_Connection(*p_context);
    acceptor->async_accept(
        connection->socket,
        boost::asio::bind_executor(strand, std::bind([](CorJob* obj) { obj->operator()(); }, this))
    );
    std::cout << "EA" << std::endl;
}


void AcceptConnectionJob::receive_client_identity() {
    std::cout << "SB" << std::endl;
    // admin->retract_accept_handler();
    connection->buffer.resize(sizeof(char)*1024);
    connection->socket.async_receive(
        boost::asio::buffer(connection->buffer),
        boost::asio::bind_executor(strand, std::bind([](CorJob* obj) { obj->operator()(); }, this)));
    std::cout << "EB" << std::endl;
}

void AcceptConnectionJob::create_client() {
    std::cout << "SC" << std::endl;
    // TODO: agree on init data format with clients
    unsigned char client_type = connection->buffer.front();
    switch (client_type)
    {
    case Administrator::Consumer:
        // TODO: Construct and provide consumer to admin
        std::cout << "Consumer" << std::endl;
        break;
    case Administrator::Producer:
        // TODO: construct and provide producer to admin
        std::cout << "Producer" << std::endl;
        break;
    default:
        std::cout << "Default" << std::endl;
        // Unexpected Client Type
        break;
    }
    std::cout << "EC" << std::endl;
}