#include "Stronghold.h"

Kingdom::Kingdom(const std::string& n, std::shared_ptr<Map> m) : name(n), map(m) {
    resources.add("Food", 5000);
    resources.add("Wood", 2000);
    resources.add("Stone", 1500);
    resources.add("Iron", 1000);
    resources.add("Gold", 1000);
    population = std::make_shared<Population>(resources);
    military = std::make_shared<Military>(resources);
    economy = std::make_shared<Economy>();
    leader = std::make_shared<Leader>("King", 0.1f, 0.5f);
    bank = std::make_shared<Bank>();
    communication = std::make_shared<Communication>();
}

void Kingdom::update() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    if (dis(gen) < 10) {
        std::vector<std::string> eventTypes = {"Famine", "Disease", "War"};
        Event evt(eventTypes[dis(gen) % 3], 50);
        evt.apply(*population, *military, *economy, resources);
    }
    population->update();
    military->update();
    economy->update();
    bank->update();
    if (!leader->holdElection(*population)) {
        leader = std::make_shared<Leader>("NewKing", 0.15f, 0.6f);
    }
    leader->applyPolicies(*economy, *military);
}

void Kingdom::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Failed to save game");
    out << name << "\n";
    population->save(out);
    military->save(out);
    economy->save(out);
    leader->save(out);
    bank->save(out);
    communication->save(out);
    out << resources.getItems().size() << "\n";
    for (const auto& res : resources.getItems()) {
        out << res.first << " " << res.second << "\n";
    }
    out.close();
}

void Kingdom::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Failed to load game");
    std::getline(in, name);
    population->load(in);
    military->load(in);
    economy->load(in);
    leader->load(in);
    bank->load(in);
    communication->load(in);
    size_t resSize;
    in >> resSize;
    resources = ResourceContainer<int>();
    for (size_t i = 0; i < resSize; ++i) {
        std::string resName;
        int qty;
        in >> resName >> qty;
        resources.add(resName, qty);
    }
    in.close();
}