#include <boost/asio/strand.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/coroutine2/all.hpp>


class CorJob {
  public:
    typedef boost::coroutines2::coroutine<void> coro_t;
    typedef coro_t::push_type context;

  private:
    coro_t::pull_type* init();
    coro_t::pull_type* coroutine = nullptr;
    virtual void mainloop(context& suspend) = 0;

  public:
    CorJob();
    ~CorJob();

    // CorJob() Accesses Coroutine mainloop
    void operator()();

    // handler acts as an explicit function serving same purpose as operator()
    CorJob::coro_t::pull_type* handler();
};