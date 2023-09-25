#ifndef SEB_M_MANAGER
#define SEB_M_MANAGER

#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <boost/asio.hpp>

class MessageManager {
    int _maxCapacity;
    std::unordered_map<std::string, Topic> _topics;
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<int, int>>> _offsets;
    std::unordered_map<std::string, int> _partitionCounts;
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>>> _partitionAssignments;

  public:
    MessageManager(int maxPerTopic);

    void appendMessage(const std::string& topic, const std::string& message, int partition);

    std::string getNextMessage(const std::string& subscriberId, const std::string& topic, int partition);

    void commitOffset(const std::string& subscriber, const std::string& topic);

    std::vector<int> getPartitionAssignments(const std::string& subscriber, const std::string& topic);

    void registerSubscriber(const std::string& subscriber);
    
    void rebalance();
    
};

#endif // SEB_M_MANAGER