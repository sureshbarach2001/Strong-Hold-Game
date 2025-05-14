#include "Stronghold.h"

void Peasant::interact(SocialClass& other) {
    if (other.getName() == "Noble") {
        population -= population / 20; // Tension reduces peasant population
    }
}

void Merchant::interact(SocialClass& other) {
    if (other.getName() == "Peasant") {
        productivity += 0.1f; // Merchants benefit from peasant labor
    }
}

void Noble::interact(SocialClass& other) {
    if (other.getName() == "Peasant") {
        productivity += 0.2f; // Nobles exploit peasants
    }
}