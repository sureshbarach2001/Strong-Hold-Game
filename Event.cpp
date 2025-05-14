#include "Stronghold.h"
#include <iostream>

void Event::apply(Population& pop, Military& mil, Economy& econ, ResourceContainer<int>& res) {
    if (type == "Famine") {
        res.consume("Food", res.get("Food") / 2);
        std::cout << "Famine strikes! Food halved.\n";
    } else if (type == "Disease") {
        for (auto& cls : pop.getClasses()) {
            int newPop = cls->getPopulation() - cls->getPopulation() / 10;
            cls->setPopulation(newPop);
        }
        std::cout << "Disease outbreak! Population reduced.\n";
    } else if (type == "War") {
        mil.setSoldiers(mil.getSoldiers() - mil.getSoldiers() / 5);
        std::cout << "War losses! Soldiers reduced.\n";
    }
}

void Event::save(std::ofstream& out) const {
    out << type << " " << severity << "\n";
}

void Event::load(std::ifstream& in) {
    in >> type >> severity;
}