#include "Stronghold.h"
#include <algorithm>

Map::Map() : grid(10, std::vector<std::string>(10, ".")) {}

void Map::placeKingdom(const std::string& name, int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10) throw std::invalid_argument("Invalid map coordinates");
    grid[x][y] = name;
}

void Map::moveKingdom(const std::string& name, int newX, int newY) {
    if (newX < 0 || newX >= 10 || newY < 0 || newY >= 10) throw std::invalid_argument("Invalid map coordinates");
    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell == name) cell = ".";
        }
    }
    grid[newX][newY] = name;
}

int Map::getDistance(const std::string& k1, const std::string& k2) const {
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == k1) { x1 = i; y1 = j; }
            if (grid[i][j] == k2) { x2 = i; y2 = j; }
        }
    }
    if (x1 == -1 || x2 == -1) throw std::runtime_error("Kingdom not found on map");
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void Map::save(std::ofstream& out) const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            out << cell << " ";
        }
        out << "\n";
    }
}

void Map::load(std::ifstream& in) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            in >> cell;
        }
    }
}