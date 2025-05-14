#include "Stronghold.h"
#include <random>
#include <iostream>

Conflict::Conflict(const std::string& a, const std::string& d, bool betrayal) : attacker(a), defender(d), isBetrayal(betrayal) {}

void Conflict::resolve(Military& atkMil, Military& defMil, ResourceContainer<int>& atkRes, ResourceContainer<int>& defRes) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    int atkStrength = atkMil.getSoldiers();
    int defStrength = defMil.getSoldiers();
    if (isBetrayal) {
        atkStrength /= 2; // Penalty for betrayal
        std::cout << "Betrayal penalty applied to " << attacker << "!\n";
    }
    if (atkStrength > defStrength || dis(gen) < 50) {
        defMil.setSoldiers(defMil.getSoldiers() / 2);
        defRes.consume("Food", defRes.get("Food") / 2);
        std::cout << attacker << " wins the battle!\n";
    } else {
        atkMil.setSoldiers(atkMil.getSoldiers() / 2);
        atkRes.consume("Food", atkRes.get("Food") / 2);
        std::cout << defender << " wins the battle!\n";
    }
}

void Conflict::save(std::ofstream& out) const {
    out << attacker << " " << defender << " " << isBetrayal << "\n";
}

void Conflict::load(std::ifstream& in) {
    in >> attacker >> defender >> isBetrayal;
}