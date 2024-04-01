#ifndef SEB_S_PARTITION
#define SEB_S_PARTITION

#include <string>
#include <fstream>      // std::ofstream

/*
A partition represents an abstraction on top of an associated file, that defines the subset of the messages on a topic
*/
class Partition {
    std::string filename;
    unsigned int size;
    std::ifstream reader;

    void init_reader();

  public:
    Partition(std::string filename);
    Partition();        // anonymous partition
    void append(const std::string& message);
    std::string read(unsigned int idx);
};


#endif