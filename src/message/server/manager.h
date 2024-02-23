#ifndef SEB_M_MANAGER
#define SEB_M_MANAGER

#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <boost/asio.hpp>
#include <data/partition.h>
#include <data/topic.h>
#include <boost/uuid/uuid.hpp>

class MessageManager {
    unsigned int id = 0;
    std::unordered_map<Topic::TopicName, Topic> topics;

    public:
      MessageManager();
      MessageManager(unsigned int id);

    // void appendMessage(const std::string& topic, const std::string& message, int partition);

    // std::string getNextMessage(const std::string& subscriberId, const std::string& topic, int partition);

    // void commitOffset(const std::string& subscriber, const std::string& topic);

    // std::vector<int> getPartitionAssignments(const std::string& subscriber, const std::string& topic);

    void registerMessageConsumer(const std::string &consumer);
    
    // void rebalance();
    
};

#endif // SEB_M_MANAGER