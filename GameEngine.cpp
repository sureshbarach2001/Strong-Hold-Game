#include "Stronghold.h"
#include <iostream>
#include <limits>

GameEngine::GameEngine() {
    scoreLog.open("score.txt", std::ios::app);
    if (!scoreLog) throw std::runtime_error("Failed to open score log");
    market = std::make_shared<Market>();
    map = std::make_shared<Map>();
}

void GameEngine::run() {
    while (true) {
        for (auto& kingdom : kingdoms) {
            std::cout << "\nTurn for " << kingdom->getName() << ":\n";
            std::cout << "Population: " << kingdom->getPopulation().getTotalPopulation() << ", Morale: " << kingdom->getPopulation().getMorale() << "\n";
            std::cout << "Soldiers: " << kingdom->getMilitary().getSoldiers() << "\n";
            std::cout << "Treasury: " << kingdom->getEconomy().getTreasury() << ", Leader: " << kingdom->getLeader().getName() << "\n";
            std::cout << "Resources: Food=" << kingdom->getResources().get("Food") << ", Wood=" << kingdom->getResources().get("Wood")
                      << ", Stone=" << kingdom->getResources().get("Stone") << ", Iron=" << kingdom->getResources().get("Iron") << "\n";
            std::cout << "Options: [1] Set Tax Rate [2] Recruit Soldiers [3] Send Message [4] Form Alliance [5] Trade [6] Attack [7] Save Game [8] Exit\n";
            int choice;
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            try {
                if (choice == 1) {
                    std::cout << "Enter tax rate (0-1): ";
                    float taxRate;
                    std::cin >> taxRate;
                    kingdom->getEconomy().setTaxRate(taxRate);
                } else if (choice == 2) {
                    std::cout << "Enter number of soldiers to recruit: ";
                    int soldiers;
                    std::cin >> soldiers;
                    kingdom->getMilitary().recruit(soldiers, kingdom->getEconomy());
                } else if (choice == 3) {
                    std::cout << "Enter message: ";
                    std::string msg;
                    std::getline(std::cin, msg);
                    kingdom->getCommunication().sendMessage(msg);
                    for (const auto& other : kingdoms) {
                        if (other != kingdom) {
                            other->getCommunication().sendMessage(kingdom->getName() + ": " + msg);
                        }
                    }
                } else if (choice == 4) {
                    std::cout << "Enter kingdom to ally with: ";
                    std::string ally;
                    std::cin >> ally;
                    formAlliance(kingdom->getName(), ally);
                } else if (choice == 5) {
                    std::cout << "Enter kingdom to trade with, item, quantity, smuggling (0/1): ";
                    std::string target;
                    std::string item;
                    int qty;
                    int smug;
                    std::cin >> target >> item >> qty >> smug;
                    for (const auto& other : kingdoms) {
                        if (other->getName() == target) {
                            market->trade(kingdom->getResources(), other->getResources(), item, qty, smug != 0);
                            break;
                        }
                    }
                } else if (choice == 6) {
                    std::cout << "Enter kingdom to attack: ";
                    std::string target;
                    std::cin >> target;
                    initiateConflict(kingdom->getName(), target);
                } else if (choice == 7) {
                    saveGame("game_save.txt");
                } else if (choice == 8) {
                    logScore();
                    return;
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
            kingdom->update();
            logScore();
        }
    }
}

void GameEngine::formAlliance(const std::string& k1, const std::string& k2) {
    for (const auto& ally : alliances) {
        if ((ally->getKingdom1() == k1 && ally->getKingdom2() == k2) || (ally->getKingdom1() == k2 && ally->getKingdom2() == k1)) {
            if (ally->isActive()) {
                ally->breakAlliance();
                return;
            }
        }
    }
    alliances.push_back(std::make_shared<Alliance>(k1, k2));
    std::cout << "Alliance formed between " << k1 << " and " << k2 << "!\n";
}

void GameEngine::initiateConflict(const std::string& attacker, const std::string& defender) {
    bool betrayal = false;
    for (const auto& ally : alliances) {
        if (ally->isActive() && ((ally->getKingdom1() == attacker && ally->getKingdom2() == defender) || (ally->getKingdom1() == defender && ally->getKingdom2() == attacker))) {
            betrayal = true;
            ally->breakAlliance();
            break;
        }
    }
    for (auto& atk : kingdoms) {
        if (atk->getName() == attacker) {
            for (auto& def : kingdoms) {
                if (def->getName() == defender) {
                    Conflict conflict(attacker, defender, betrayal);
                    conflict.resolve(atk->getMilitary(), def->getMilitary(), atk->getResources(), def->getResources());
                    break;
                }
            }
            break;
        }
    }
}

void GameEngine::saveGame(const std::string& filename) {
    for (size_t i = 0; i < kingdoms.size(); ++i) {
        kingdoms[i]->save(filename + std::to_string(i));
    }
    std::ofstream out(filename + "_global");
    if (!out) throw std::runtime_error("Failed to save alliances");
    out << alliances.size() << "\n";
    for (const auto& ally : alliances) {
        ally->save(out);
    }
    market->save(out);
    map->save(out);
    out.close();
}

void GameEngine::loadGame(const std::string& filename) {
    for (size_t i = 0; i < kingdoms.size(); ++i) {
        kingdoms[i]->load(filename + std::to_string(i));
    }
    std::ifstream in(filename + "_global");
    if (!in) throw std::runtime_error("Failed to load alliances");
    size_t allySize;
    in >> allySize;
    alliances.clear();
    for (size_t i = 0; i < allySize; ++i) {
        auto ally = std::make_shared<Alliance>("", "");
        ally->load(in);
        alliances.push_back(ally);
    }
    market->load(in);
    map->load(in);
    in.close();
}

void GameEngine::logScore() {
    for (const auto& kingdom : kingdoms) {
        scoreLog << kingdom->getName() << ": Population=" << kingdom->getPopulation().getTotalPopulation()
                 << ", Soldiers=" << kingdom->getMilitary().getSoldiers()
                 << ", Treasury=" << kingdom->getEconomy().getTreasury() << "\n";
    }
}