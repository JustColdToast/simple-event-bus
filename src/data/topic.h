#ifndef SEB_S_TOPIC
#define SEB_S_TOPIC

#include <data/partition.h>
#include <string>

/*
A topic represents a collection of messages that are logically related, seperated into partitions.
*/
class Topic {
    std::string name;
    std::vector<Partition> partitions;

  public:
    typedef std::string TopicName;
    Topic(std::string name, unsigned int partitionCount);

    void append(const std::string& message, int partition);
    std::string read(int partition, int idx);
    
};


#endif