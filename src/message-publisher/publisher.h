#ifndef SEB_M_PUBLISHER
#define SEB_M_PUBLISHER

#include "../message-manager/manager.h"

class MessagePublisher {
    MessageManager &_manager;
    
public:
    MessagePublisher(MessageManager& manager);

    void publish(const std::string& topic, const std::string& message);

};

#endif // SEB_M_PUBLISHER
