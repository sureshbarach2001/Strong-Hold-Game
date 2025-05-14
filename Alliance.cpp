#include "Stronghold.h"
#include <iostream>

Alliance::Alliance(const std::string& k1, const std::string& k2) : kingdom1(k1), kingdom2(k2), active(true) {}

void Alliance::breakAlliance() {
    active = false;
    std::cout << "Alliance between " << kingdom1 << " and " << kingdom2 << " broken!\n";
}

std::string Alliance::getOtherKingdom(const std::string& k) const {
    return (k == kingdom1) ? kingdom2 : kingdom1;
}

void Alliance::save(std::ofstream& out) const {
    out << kingdom1 << " " << kingdom2 << " " << active << "\n";
}

void Alliance::load(std::ifstream& in) {
    in >> kingdom1 >> kingdom2 >> active;
}