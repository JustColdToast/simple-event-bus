#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <administration/administrator.h>
#include <connection/tcp_connection.h>
#include <jobs/accept-connection-job.h>

using namespace boost::asio;


int main() {
    // AcceptConnectionJob job{new io_context()};
    // job();
    // job();
    // job();
    unsigned int processors = std::thread::hardware_concurrency(); // get logical processor count
    std::cout << "count: " << processors << std::endl;
    Administrator admin{};
    admin();
}
