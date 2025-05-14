#include "Stronghold.h"
#include <iostream>
#include <random>

Leader::Leader(const std::string& n, float tp, float mf) : name(n), taxPolicy(tp), militaryFocus(mf) {}

void Leader::applyPolicies(Economy& econ, Military& mil) {
    econ.setTaxRate(taxPolicy);
    mil.recruit(static_cast<int>(militaryFocus * 50), econ);
}

bool Leader::holdElection(const Population& pop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    if (pop.getMorale() < 50 && dis(gen) < 30) {
        std::cout << "Coup! Leader replaced.\n";
        return false;
    }
    return true;
}

void Leader::save(std::ofstream& out) const {
    out << name << " " << taxPolicy << " " << militaryFocus << "\n";
}

void Leader::load(std::ifstream& in) {
    in >> name >> taxPolicy >> militaryFocus;
}