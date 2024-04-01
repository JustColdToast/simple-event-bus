#ifndef SEB_A_ADMINISTRATOR
#define SEB_A_ADMINISTRATOR

#include <semaphore>
#include <boost/asio.hpp>
#include <iostream>


/*
The Administrator is responsible for orchestrating workers across the SEB. It's primary responsibility is to choose what type of work
    needs to be performed at any given time, and distributing said work.
*/
class Administrator {
    boost::asio::io_context * p_context;      // pointer to stack io_context
    const unsigned int processor_count;

    /*
    Reflects the stats monitored by Administrators. Shared between all Admins.
    */
    struct Stats {
      std::atomic<unsigned int> open_accept_handlers = 0;
      std::atomic<unsigned int> active_connections = 0;
    } stats;

    /*
    efficient_mode() is an alternative Administrator mainloop for systems with a lower core count
    */
    void efficient_mode();

    /*
    Worker represents a generic worker that may execute a variety of tasks on behalf of the administrator
    */
    struct Worker {
      unsigned int id;        // numerical id for the worker
      Administrator &admin;   // Parent administrator of the worker
      Worker(unsigned int id, Administrator &admin);
      void operator() ();   // Worker mainloop
    };

    

  public:
    enum ClientType { Consumer = 0, Producer };
    
    Administrator();

    void operator() ();                 // Administrator mainloop

    /*
    wait_and_work() is a method called workers to wait for and recieve a task from the Administrator.
    NOTE: May cause the calling thread to block.
    */
    void wait_and_work();

    /*
    submit_consumer
    */
   void submit_consumer();

   /*
   
   */
  void submit_producer();

  unsigned int get_open_accept_handlers();

  bool is_connection_slot_available();

  void declare_accept_handler();

  void retract_accept_handler();
};

#endif