#include "Stronghold.h"
#include <iostream>

Bank::Bank() : loans(0), interestRate(0.05f), fraudLevel(0) {}

void Bank::issueLoan(Economy& econ, int amount) {
    if (amount < 0) throw std::invalid_argument("Negative loan amount");
    econ.spend(-amount);
    loans += amount;
    fraudLevel += amount / 1000;
}

void Bank::audit() {
    if (fraudLevel > 50) {
        std::cout << "Fraud detected! Loans reduced.\n";
        loans /= 2;
        fraudLevel = 0;
    }
}

void Bank::update() {
    loans = static_cast<int>(loans * (1 + interestRate));
}

void Bank::save(std::ofstream& out) const {
    out << loans << " " << interestRate << " " << fraudLevel << "\n";
}

void Bank::load(std::ifstream& in) {
    in >> loans >> interestRate >> fraudLevel;
}