#include "Stronghold.h"
#include <iostream>

int main() {
    try {
        GameEngine engine;
        auto map = std::make_shared<Map>();
        auto k1 = std::make_shared<Kingdom>("Kingdom1", map);
        auto k2 = std::make_shared<Kingdom>("Kingdom2", map);
        map->placeKingdom("Kingdom1", 2, 2);
        map->placeKingdom("Kingdom2", 7, 7);
        engine.addKingdom(k1);
        engine.addKingdom(k2);
        std::cout << "Stronghold Game Started\n";
        engine.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}