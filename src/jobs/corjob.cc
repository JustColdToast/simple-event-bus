#include "corjob.h"
#include <iostream>

CorJob::CorJob() { }


CorJob::coro_t::pull_type* CorJob::init() {
    return new coro_t::pull_type([this](context& suspend) {
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

CorJob::~CorJob() {
    if (coroutine != nullptr) {
        delete coroutine;
    }
}
