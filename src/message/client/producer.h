#ifndef SEB_M_PRODUCER
#define SEB_M_PRODUCER

#include <message/server/manager.h>
#include <connection/tcp_connection.h>

class MessageProducer {
    const TCP_Connection *connection;
    const MessageManager *manager = nullptr;
    
    
public:
    MessageProducer(TCP_Connection *connection);

    // void publish(const std::string& topic, const std::string& message);

};

#endif // SEB_M_PRODUCER
