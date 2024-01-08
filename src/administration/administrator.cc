#include "administrator.h"
#include <thread>
#include <assert.h>
#include "work.h"
#include "constants.h"


Administrator::Administrator(): processor_count{std::thread::hardware_concurrency()} {}

void Administrator::efficient_mode() {
    assert(false); // Unimplemented
}

void Administrator::wait_and_work() {
    // Rely on IO-Context to provide work
    p_context->run();   // commit thread to running
    // std::cout << "woke" << std::endl;
}

unsigned int Administrator::get_open_accept_handlers() {
    return stats.open_accept_handlers;
}

void Administrator::declare_accept_handler() {
    stats.open_accept_handlers++;
}

void Administrator::retract_accept_handler() {
    stats.open_accept_handlers--;
}

bool Administrator::is_connection_slot_available() {
    return stats.active_connections < ADMIN_MAX_CONNECTIONS;
}

void Administrator::operator()() {
    // Start of Administrator mainLoop;
    if (processor_count <= 2) { efficient_mode(); }

    boost::asio::io_context context;
    // set guard for context to stop it from hitting stop state
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> guard = boost::asio::make_work_guard(context);
    p_context = &context;   // share context

    // Set up acceptors and endpoint
    ip::tcp::endpoint base_endpoint(ip::tcp::v4(), ACCEPT_BASE_PORT);
    ip::tcp::acceptor acceptor(context, base_endpoint);

    // Set up threads
    std::thread threads[processor_count - 1];   
    for (unsigned int i = 0; i < processor_count - 1; i++) {
        threads[i] = std::thread(Worker(i, *this));
    }

    // Set up mainloop
    for (;;) {
        // TODO: Administrator must monitor system and decide what work to add to io_context

        // check if new connections need to be made
        if (stats.active_connections < ADMIN_MAX_CONNECTIONS && !stats.open_accept_handlers) {
            /*
                The above formulation only allows true positives, true negatives, and false positives. We will only create
                handlers that are actually needed, or excess handlers, never fail to create a needed handler. This is because
                open_accept_handlers may decrease in the time between it and checking active_connections.
            */
        //    std::cout << "dispatching" << std::endl;
           stats.open_accept_handlers++;
            boost::asio::dispatch(
                context,
                std::bind(seb::tcp::accept_connection, this, &acceptor, p_context));
        }
    }

}


Administrator::Worker::Worker(unsigned int id, Administrator &admin):
    id{id},
    admin{admin} {}

void Administrator::Worker::operator()() {
    // Worker Mainloop
    // std::cout << "start " << id << std::endl;
    for (;;) {
        admin.wait_and_work(); // Await work from admin
    }
}