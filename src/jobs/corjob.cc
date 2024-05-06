#include "corjob.h"
#include <iostream>

CorJob::CorJob() { }

// void CorJob::handler() {
//     this->operator()();
// }

// TODO: this doesn't work as expected: resumption causes null pointer exception
CorJob::coro_t::pull_type* CorJob::init() {
    return new boost::coroutines2::detail::pull_coroutine<void>([this](context& suspend) {
        mainloop(suspend);
    });
}

void CorJob::operator()() {
    if (coroutine == nullptr) {
        // New coroutine auto-starts
        coroutine = init();
    } else {
        (*coroutine)();
    }
}

CorJob::coro_t::pull_type* CorJob::handler() {
    return coroutine;
}

CorJob::~CorJob() {
    std::cout << "CorJob Destructor Called" << std::endl;
    if (coroutine != nullptr) {
        delete coroutine;
    }
}
