#include "producer.h"
#include <boost/uuid/uuid_generators.hpp>

MessageProducer::MessageProducer(TCP_Connection *connection) : id{boost::uuids::random_generator()()}, connection(connection) {}

// void Publisher::publish(const std::string& topic, const std::string& message) {
//     _manager.appendMessage(topic, message, 0); // Assuming partition 0 for simplicity
// }
