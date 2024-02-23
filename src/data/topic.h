#ifndef SEB_S_TOPIC
#define SEB_S_TOPIC

#include <data/partition.h>
#include <string.h>

/*
A topic represents a collection of messages that are logically related, seperated into partitions.
*/
class Topic {
    std::string name;
    std::vector<Partition> partitions;

  public:
    typedef std::string TopicName; 
    


};


#endif