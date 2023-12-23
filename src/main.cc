#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <boost/beast/websocket.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;
namespace websocket = beast::websocket;
using tcp = asio::ip::tcp;

int main() {
    try {
        // Create an io_context and a resolver
        asio::io_context io_context;
        tcp::resolver resolver(io_context);

        // Resolve the WebSocket endpoint
        auto const results = resolver.resolve("localhost", "80");

        // Create a WebSocket stream
        websocket::stream<tcp::socket> ws(io_context);

        // Connect to the WebSocket server
        asio::connect(ws.next_layer(), results.begin(), results.end());
        ws.handshake("localhost", "/");

        // Send a message
        ws.write(asio::buffer("Hello, WebSocket!"));

        // Receive the echo reply
        beast::flat_buffer buffer;
        ws.read(buffer);

        // Print the echoed message
        std::cout << beast::buffers_to_string(buffer.data()) << std::endl;

        // Close the WebSocket connection
        ws.close(websocket::close_code::normal);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
