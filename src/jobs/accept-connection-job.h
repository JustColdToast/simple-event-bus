#ifndef SEB_J_ACCEPT_CONNECTION_JOB
#define SEB_J_ACCEPT_CONNECTION_JOB

#include <boost/asio/strand.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/coroutine2/all.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include "corjob.h"
#include <administration/administrator.h>
#include <connection/tcp_connection.h>

class AcceptConnectionJob: public CorJob {
    Administrator *admin;
    boost::asio::io_context * p_context;
    boost::asio::ip::tcp::acceptor *acceptor;

    boost::asio::strand<boost::asio::io_context::executor_type> strand;
    TCP_Connection *connection = nullptr;

    /*
    accept_connection() is a handler that will allocate memory for a TCP connection, then wait for it to
        be fulfillfed
    */
    void accept_connection();

    /*
    receive_client_identity(connection, admin, context) will communicate with the tcp "connection" to identify the client
    */
    void receive_client_identity();

    /*
    create_client(connection, admin, context) establishes the "connection" client identity, and relays this information
        to the "admin"
    */
    void create_client();
    
    void mainloop(context& suspend);
public:
    AcceptConnectionJob(Administrator *admin, boost::asio::io_context * p_context, boost::asio::ip::tcp::acceptor *acceptor);
    ~AcceptConnectionJob();
    // dispatches the job on the provided io_context object in a thread-safe manner in regard to subjobs in the job
    void dispatch();

};

#endif