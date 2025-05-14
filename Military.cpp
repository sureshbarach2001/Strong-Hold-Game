#include "Stronghold.h"
#include <iostream>

Military::Military(ResourceContainer<int>& res) : soldiers(100), morale(50), trainingLevel(1), resources(res), corruptionLevel(0) {}

void Military::recruit(int amount, Economy& econ) {
    if (amount < 0) throw std::invalid_argument("Negative recruitment amount");
    resources.consume("Food", amount * 2);
    econ.spend(amount * 10);
    soldiers += amount;
    trainingLevel = std::max(1, trainingLevel - 1); // New recruits lower training
    corruptionLevel += amount / 100; // Large recruitment increases corruption risk
}

void Military::update() {
    morale = std::min(100, morale + trainingLevel);
    if (corruptionLevel > 50) {
        std::cout << "Corruption detected in military! Soldiers desert.\n";
        soldiers -= soldiers / 10;
        corruptionLevel = 0;
    }
}

void Military::save(std::ofstream& out) const {
    out << soldiers << " " << morale << " " << trainingLevel << " " << corruptionLevel << "\n";
}

void Military::load(std::ifstream& in) {
    in >> soldiers >> morale >> trainingLevel >> corruptionLevel;
}