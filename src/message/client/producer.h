#ifndef SEB_M_PRODUCER
#define SEB_M_PRODUCER

#include <message/server/manager.h>
#include <connection/tcp_connection.h>
#include <boost/uuid/uuid.hpp>

class MessageProducer {
    const boost::uuids::uuid id;
    const TCP_Connection *connection;
    MessageManager *manager = nullptr;
    
public:
    MessageProducer(TCP_Connection *connection);

    // void publish(const std::string& topic, const std::string& message);

};

#endif // SEB_M_PRODUCER
