#ifndef SEB_A_WORK_HELPERS
#define SEB_A_WORK_HELPERS

#include "administrator.h"
#include <connection/tcp_connection.h>
#include <iostream>
#include <thread>
#include "constants.h"
#include <message/client/consumer.h>
#include <message/client/producer.h>
#include <stdlib.h>     /* srand, rand */


/*
This file defines the handlers that workers will use to execute operations across SEB
*/

namespace seb {

    namespace tcp {
        using namespace boost::asio;
        

        /*
        create_client(connection, admin, context) establishes the "connection" client identity, and relays this information
            to the "admin"
        */
        void create_client(TCP_Connection *connection, Administrator *admin) {
            // TODO: agree on init data format with clients
            unsigned char client_type = connection->buffer.front();
            switch (client_type)
            {
            case Administrator::Consumer:
                // TODO: Construct and provide consumer to admin
                break;
            case Administrator::Producer:
                // TODO: construct and provide producer to admin
                break;
            default:
                
                // Unexpected Client Type
                break;
            }
        }

        /*
        receive_client_identity(connection, admin, context) will communicate with the tcp "connection" to identify the client
        */
        void receive_client_identity(TCP_Connection *connection, Administrator *admin) {
            admin->retract_accept_handler();
            connection->buffer.resize(sizeof(char)*1024);
            connection->socket.async_receive(
                boost::asio::buffer(connection->buffer),
                std::bind(create_client, connection, admin));
        }

        /*
        accept_connection() is a handler that will allocate memory for a TCP connection, then wait for it to
            be fulfillfed
        */
        void accept_connection(Administrator *admin, ip::tcp::acceptor *acceptor ,boost::asio::io_context *context) {
            TCP_Connection *connection = new TCP_Connection(*context);
            acceptor->async_accept(connection->socket,
            std::bind(receive_client_identity, connection, admin));
        }
    }
}

#endif