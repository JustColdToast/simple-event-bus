#include "partition.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

void create_file(const std::string& filename) {
    std::ofstream file (filename);
    file.close();
}

void Partition::init_reader() {
    create_file(filename);
    reader = std::ifstream(filename, std::ios::in);
    reader.open(filename);
}

Partition::Partition(std::string filename): filename{filename}, size{0} {
    create_file(filename);
}

Partition::Partition(): size{0} {
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();
    filename = boost::uuids::to_string(uuid);
}

void Partition::append(const std::string& message) {
    std::ofstream file (filename, std::ios::app);
    file << message << std::endl;
    file.close();
    size += 1;
}

std::string Partition::read(unsigned int idx) {
    std::ifstream file(filename);
    std::string line;
    for (unsigned int i = 0; i < idx; ++i) {
        std::getline(file, line);
    }
    file.close();
    return line;
}