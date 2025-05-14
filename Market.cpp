#include "Stronghold.h"
#include <random>
#include <iostream>

Market::Market() {
    prices["Food"] = 10;
    prices["Wood"] = 5;
    prices["Stone"] = 8;
    prices["Iron"] = 15;
}

void Market::trade(ResourceContainer<int>& res1, ResourceContainer<int>& res2, const std::string& item, int qty, bool smuggling) {
    if (qty < 0) throw std::invalid_argument("Negative trade quantity");
    int cost = prices[item] * qty;
    if (!smuggling) {
        res1.consume(item, qty);
        res2.add(item, qty);
        res2.consume("Gold", cost);
        res1.add("Gold", cost);
    } else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        if (dis(gen) < 20) {
            std::cout << "Smuggling detected! Resources confiscated.\n";
            res1.consume(item, qty);
        } else {
            res1.consume(item, qty);
            res2.add(item, qty);
        }
    }
}

void Market::save(std::ofstream& out) const {
    out << prices.size() << "\n";
    for (const auto& p : prices) {
        out << p.first << " " << p.second << "\n";
    }
}

void Market::load(std::ifstream& in) {
    size_t size;
    in >> size;
    prices.clear();
    for (size_t i = 0; i < size; ++i) {
        std::string item;
        int price;
        in >> item >> price;
        prices[item] = price;
    }
}