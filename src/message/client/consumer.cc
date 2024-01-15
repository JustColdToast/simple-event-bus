#include "consumer.h"
#include <iostream>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

MessageConsumer::MessageConsumer(TCP_Connection *connection) : id{boost::uuids::random_generator()()}, connection(connection) {}

// void MessageConsumer::poll(const std::string& topic) {
//     std::vector<int> partitions = manager_.getPartitionAssignments(boost::uuids::to_string(_id), topic);

//     for (int partition : partitions) {
//         std::string msg = _manager.getNextMessage(boost::uuids::to_string(id_), topic, partition);
//         if (!msg.empty()) {
//             std::cout << "Received: " << msg << std::endl;
//         }
//     }
// }

// void MessageConsumer::commit(const std::string& topic) {
//     _manager.commitOffset(boost::uuids::to_string(_id), topic);
// }
