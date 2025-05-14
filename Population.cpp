#include "Stronghold.h"
#include <iostream>

Population::Population(ResourceContainer<int>& res) : morale(50), employment(80), shelter(80), resources(res) {
    classes.push_back(std::make_shared<Peasant>(500));
    classes.push_back(std::make_shared<Merchant>(300));
    classes.push_back(std::make_shared<Noble>(200));
}

void Population::update() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-5, 5);
    int food = resources.get("Food");
    int totalPop = getTotalPopulation();
    if (food >= totalPop) {
        for (auto& cls : classes) {
            int newPop = cls->getPopulation() + cls->getPopulation() / 10;
            cls->setPopulation(newPop);
        }
        morale += dis(gen);
    } else {
        for (auto& cls : classes) {
            int newPop = cls->getPopulation() - cls->getPopulation() / 20;
            cls->setPopulation(newPop);
        }
        morale -= dis(gen);
    }
    if (employment < 50 || shelter < 50 || morale < 20) {
        std::cout << "Revolt! Population decreases.\n";
        for (auto& cls : classes) {
            int newPop = cls->getPopulation() - cls->getPopulation() / 10;
            cls->setPopulation(newPop);
        }
    }
    for (size_t i = 0; i < classes.size(); ++i) {
        for (size_t j = i + 1; j < classes.size(); ++j) {
            classes[i]->interact(*classes[j]);
        }
    }
    morale = std::max(0, std::min(100, morale));
}

int Population::getTotalPopulation() const {
    int total = 0;
    for (const auto& cls : classes) {
        total += cls->getPopulation();
    }
    return total;
}

void Population::save(std::ofstream& out) const {
    out << morale << " " << employment << " " << shelter << "\n";
    out << classes.size() << "\n";
    for (const auto& cls : classes) {
        cls->save(out);
    }
}

void Population::load(std::ifstream& in) {
    in >> morale >> employment >> shelter;
    size_t size;
    in >> size;
    classes.clear();
    for (size_t i = 0; i < size; ++i) {
        std::string name;
        in >> name;
        if (name == "Peasant") {
            auto cls = std::make_shared<Peasant>(0);
            cls->load(in);
            classes.push_back(cls);
        } else if (name == "Merchant") {
            auto cls = std::make_shared<Merchant>(0);
            cls->load(in);
            classes.push_back(cls);
        } else if (name == "Noble") {
            auto cls = std::make_shared<Noble>(0);
            cls->load(in);
            classes.push_back(cls);
        }
    }
}