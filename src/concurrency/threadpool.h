// #ifndef SEB_C_THREADPOOL
// #define SEB_C_THREADPOOL

// #include <thread>

// class Threadpool {
//   public:
//     enum ThreadState { Free = 0, Busy };
//     Threadpool(unsigned int processor_count);
//     ~Threadpool();
//   private:
//     struct ManagedThread {
//         std::thread thread;
//         ThreadState state = Free;
//         ManagedThread();
//         std::thread& get();
//     };

//     const unsigned int size;
//     const ManagedThread *threads;
  
// };

// #endif