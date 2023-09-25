#include "publisher.h"

Publisher::Publisher(MessageManager& manager) : _manager(manager) {}

void Publisher::publish(const std::string& topic, const std::string& message) {
    _manager.appendMessage(topic, message, 0); // Assuming partition 0 for simplicity
}
