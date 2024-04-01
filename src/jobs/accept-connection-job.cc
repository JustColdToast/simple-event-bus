#include "accept-connection-job.h"
#include <iostream>
#include <boost/coroutine2/all.hpp>


AcceptConnectionJob::AcceptConnectionJob(boost::asio::io_context * p_context): 
    p_context{p_context},
    strand{boost::asio::make_strand(*p_context)} { }


//  mainloop{coro_t::pull_type([this](boost::coroutines2::coroutine<void>::push_type& suspend) {
//                 std::cout << "Start" << std::endl;
//                 boost::asio::dispatch(strand, [this] { mainloop(); });
//                 suspend();
//                 std::cout << "back" << std::endl;
//             })}

// void AcceptConnectionJob::mainloop(coro_t::pull_type& suspend) {
//     std::cout << "Start" << std::endl;
//     boost::asio::dispatch(strand, [this] { accept_connection(); });
//     suspend();
//     std::cout << "back" << std::endl;

// }

// AcceptConnectionJob::coro_t AcceptConnectionJob::mainloop = 
//     return coro_t::pull_type([this](coro_t::push_type& suspend) {
//         std::cout << "Start" << std::endl;
//         boost::asio::dispatch(strand, [this, &suspend] { suspend(); });
//         std::cout << "back" << std::endl;
//     });
// }

// coro_t::pull_type AcceptConnectionJob::mainloop() {
//     return coro_t::pull_type([](coro_t::push_type& suspend) {
//         std::cout << "Start" << std::endl;
//         // boost::asio::dispatch(strand, [this, &suspend] {; });
//         suspend();
//         std::cout << "back" << std::endl;
//     });
// }

void AcceptConnectionJob::mainloop(context& suspend) {
    std::cout << "Start" << std::endl;
    // boost::asio::dispatch(strand, [this, &suspend] {; });
    suspend();
    std::cout << "back" << std::endl;
}

// void AcceptConnectionJob::mainloop(coro_t::push_type& suspend) {
//     std::cout << "Start" << std::endl;
//     suspend();
//     std::cout << "back" << std::endl;
    
// }

// void AcceptConnectionJob::accept_connection() {
//     auto thing = mainloop();
//     std::cout << "activated" << std::endl;
//     thing();
// }