#include <boost/asio/strand.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/coroutine2/all.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include "corjob.h"

class AcceptConnectionJob: public CorJob {
    boost::asio::io_context * p_context;
    boost::asio::strand<boost::asio::io_context::executor_type> strand;
    
    void mainloop(context& suspend);

public:
    AcceptConnectionJob(boost::asio::io_context * p_context);

};