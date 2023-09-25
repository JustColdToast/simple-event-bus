#ifndef SEB_M_CONSUMER
#define SEB_M_CONSUMER

#include "../message-manager/manager.h"
#include <boost/uuid/uuid.hpp>

class MessageConsumer {
    MessageManager& _manager;
    boost::uuids::uuid id;

  public:
    MessageConsumer(MessageManager& manager);

    void poll(const std::string& topic);
    
    void commit(const std::string& topic);
};

#endif // SEB_M_CONSUMER
