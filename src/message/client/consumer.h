#ifndef SEB_M_CONSUMER
#define SEB_M_CONSUMER

#include "message/server/manager.h"
#include <connection/tcp_connection.h>
#include <boost/uuid/uuid.hpp>

class MessageConsumer {
    const boost::uuids::uuid id;
    const TCP_Connection *connection;
    MessageManager *manager = nullptr;

  public:
    MessageConsumer(TCP_Connection *connection);
    // MessageConsumer(MessageManager &manager);

    // void poll(const std::string& topic);
    
    // void commit(const std::string& topic);
};

#endif // SEB_M_CONSUMER
