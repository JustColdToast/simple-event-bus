#include "manager.h"

MessageManager::MessageManager(int maxPerTopic) : _maxCapacity(maxPerTopic) {}

// void MessageManager::appendMessage(const std::string& topic, const std::string& message, int partition) {
//     _topics[topic].append(message, partition);
// }

// std::string MessageManager::getNextMessage(const std::string& subscriberId, const std::string& topic, int partition) {
//     int& offset = _offsets[subscriberId][topic][partition];
//     return _topics[topic].getNextMessage(partition, offset);
// }

// void MessageManager::commitOffset(const std::string& subscriber, const std::string& topic) {
//     for (auto& offset : _offsets[subscriber][topic]) {
//         if (offset.second < _topics[topic].size()) {
//             offset.second += 1;
//         }
//     }
// }

// std::vector<int> MessageManager::getPartitionAssignments(const std::string& subscriber, const std::string& topic) {
//     return _partitionAssignments[subscriber][topic];
// }

void MessageManager::registerMessageConsumer(const std::string &consumer) {
    for (const auto& topic : _topics) {
        _partitionAssignments[consumer][topic.first] = std::vector<int>();
    }
    // rebalance();
}

// void MessageManager::rebalance() {
//     std::vector<std::string> knownSubscribers;
//     for (const auto& assignment : _partitionAssignments) {
//         knownSubscribers.push_back(assignment.first);
//     }

//     for (auto& topic : _topics) {
//         int partitions = _partitionCounts[topic.first];
//         for (size_t i = 0; i < knownSubscribers.size(); ++i) {
//             auto& assignments = _partitionAssignments[knownSubscribers[i]][topic.first];
//             assignments.clear();
//             for (int j = i; j < partitions; j += knownSubscribers.size()) {
//                 assignments.push_back(j);
//             }
//         }
//     }
// }
