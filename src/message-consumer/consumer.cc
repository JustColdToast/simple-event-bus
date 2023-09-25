#include "consumer.h"
#include <iostream>

MessageConsumer::MessageConsumer(MessageManager& manager) : _manager(manager) {
    _id = boost::uuids::random_generator()();
    _manager.registerMessageConsumer(boost::uuids::to_string(_id));
}

void MessageConsumer::poll(const std::string& topic) {
    std::vector<int> partitions = manager_.getPartitionAssignments(boost::uuids::to_string(_id), topic);

    for (int partition : partitions) {
        std::string msg = _manager.getNextMessage(boost::uuids::to_string(id_), topic, partition);
        if (!msg.empty()) {
            std::cout << "Received: " << msg << std::endl;
        }
    }
}

void MessageConsumer::commit(const std::string& topic) {
    _manager.commitOffset(boost::uuids::to_string(_id), topic);
}
