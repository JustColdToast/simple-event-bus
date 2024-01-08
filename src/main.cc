#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <administration/administrator.h>
#include <connection/tcp_connection.h>
// #include <administration/work.h>

using namespace boost::asio;

// bool done = false;

// void handler() {
//     std::cout << "handled" << std::endl;
//     done = true;
// }

// void tLocal() {
//     io_context context;
//     Administrator admin{};
//     try {
//         seb::tcp::accept_connection(admin, context);
//         // TCP_Connection *connection = new TCP_Connection(context);
//         // ip::tcp::socket socket(context);
//         // ip::tcp::endpoint endpoint(ip::address::from_string("127.0.0.1"), 12345);
//         // ip::tcp::acceptor acceptor(*&context, endpoint);
//         // std::cout << "s1" << std::endl;
//         // acceptor.async_accept(connection->get_socket(),
//         // std::bind(handler));

//         context.run();

//         // while (!done);
        
//     } catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

int main() {
    // tLocal();
    unsigned int processors = std::thread::hardware_concurrency(); // get logical processor count
    std::cout << "count: " << processors << std::endl;
    Administrator admin{};
    std::thread t_admin(std::ref(admin));
    t_admin.join();

    // Threadpool t(processors);
    // try {
    //     io_context context;

        
    //     // Connect to the server in a loop
    //     // ip::tcp::endpoint endpoint(ip::address::from_string("127.0.0.1"), 1234);
    //     ip::tcp::endpoint endpoint(ip::tcp::v4(), 12345);
    //     ip::tcp::acceptor acceptor(context, endpoint); // blocking?

    //     // Create a TCP socket
    //     ip::tcp::socket socket(context);

    //     // Wait for a client to connect: blocking
    //     acceptor.accept(socket);
        
    //     // for (;;) {
    //     //     try {
    //     //         socket.open(boost::asio::ip::tcp::v4());
    //     //         socket.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 12345));
    //     //         break;
    //     //     } catch (boost::system::system_error &ec) {
    //     //         if (ec.code() != boost::asio::error::connection_refused) {
    //     //             std::cerr << "Unexpected error" << std::endl;
    //     //             throw; // rethrow unexpected
    //     //         }
    //     //         std::cerr << "Connect Failed, Retry" << std::endl;
    //     //         break;
    //     //         socket.close(); // must close socket; in a broken connected state
    //     //     }
    //     // }
        
    //     // socket.wait(ip::tcp::socket::wait_write);

    //     // Send data to the client
    //     std::string message = "Hello, client!";
    //     socket.send(buffer(message));

    //     // Read data from the client
    //     char data[1024];
    //     size_t length = socket.read_some(buffer(data));
    //     std::cout << "Received data from client: " << data << std::endl;
    // } catch (std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // return 0;
}
