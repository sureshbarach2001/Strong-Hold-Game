#include "Stronghold.h"

Economy::Economy() : treasury(1000), taxRate(0.1f), inflation(0.02f) {}

void Economy::collectTaxes(const Population& pop) {
    int totalTax = 0;
    for (const auto& cls : pop.getClasses()) {
        totalTax += static_cast<int>(cls->getTaxContribution() * taxRate);
    }
    treasury += totalTax;
}

void Economy::spend(int amount) {
    if (amount > treasury) throw std::runtime_error("Insufficient funds");
    treasury -= amount;
}

void Economy::setTaxRate(float tr) {
    if (tr < 0 || tr > 1) throw std::invalid_argument("Invalid tax rate");
    taxRate = tr;
}

void Economy::update() {
    treasury = static_cast<int>(treasury * (1 + inflation));
}

void Economy::save(std::ofstream& out) const {
    out << treasury << " " << taxRate << " " << inflation << "\n";
}

void Economy::load(std::ifstream& in) {
    in >> treasury >> taxRate >> inflation;
}