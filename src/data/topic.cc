#include "topic.h"

Topic::Topic(std::string name, unsigned int partitionCount): name{name} {
    for (unsigned int i = 0; i < partitionCount; ++i) {
        partitions.push_back(Partition());
    }
}