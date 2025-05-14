#include "Stronghold.h"

void Communication::sendMessage(const std::string& msg) {
    messages.push_back(msg);
}

void Communication::save(std::ofstream& out) const {
    out << messages.size() << "\n";
    for (const auto& msg : messages) {
        out << msg << "\n";
    }
}

void Communication::load(std::ifstream& in) {
    size_t size;
    in >> size;
    in.ignore();
    messages.clear();
    for (size_t i = 0; i < size; ++i) {
        std::string msg;
        std::getline(in, msg);
        messages.push_back(msg);
    }
}