#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <random>
#include <map>

// Forward declarations
class Economy;
class Military;
class Population;
class Kingdom;

template <typename T>
class ResourceContainer
{
private:
    std::map<std::string, T> items;

public:
    void add(const std::string &name, T qty)
    {
        if (qty < 0)
            throw std::invalid_argument("Negative resource quantity");
        items[name] += qty;
    }
    void consume(const std::string &name, T qty)
    {
        if (qty < 0 || items[name] < qty)
            throw std::invalid_argument("Invalid consume quantity");
        items[name] -= qty;
    }
    T get(const std::string &name) const
    {
        return items.at(name);
    }
    const std::map<std::string, T>& getItems() const { return items; }
};

class SocialClass
{
protected:
    std::string name;
    int population;
    float productivity;

public:
    SocialClass(const std::string &n, int pop, float prod) : name(n), population(pop), productivity(prod) {}
    virtual void interact(SocialClass &other) = 0;
    virtual float getTaxContribution() const { return population * productivity; }
    int getPopulation() const { return population; }
    void setPopulation(int pop) { population = pop; }
    std::string getName() const { return name; }
    virtual void save(std::ofstream &out) const { out << name << " " << population << " " << productivity << "\n"; }
    virtual void load(std::ifstream &in) { in >> name >> population >> productivity; }
};

class Peasant : public SocialClass
{
public:
    Peasant(int pop) : SocialClass("Peasant", pop, 0.5f) {}
    void interact(SocialClass &other) override;
};

class Merchant : public SocialClass
{
public:
    Merchant(int pop) : SocialClass("Merchant", pop, 2.0f) {}
    void interact(SocialClass &other) override;
};

class Noble : public SocialClass
{
public:
    Noble(int pop) : SocialClass("Noble", pop, 5.0f) {}
    void interact(SocialClass &other) override;
};

class Population
{
private:
    std::vector<std::shared_ptr<SocialClass>> classes;
    int morale;
    int employment;
    int shelter;
    ResourceContainer<int> &resources;

public:
    Population(ResourceContainer<int> &res);
    void addClass(std::shared_ptr<SocialClass> cls) { classes.push_back(cls); }
    void update();
    int getTotalPopulation() const;
    int getMorale() const { return morale; }
    std::vector<std::shared_ptr<SocialClass>>& getClasses() { return classes; }
    const std::vector<std::shared_ptr<SocialClass>>& getClasses() const { return classes; }
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Military
{
private:
    int soldiers;
    int morale;
    int trainingLevel;
    ResourceContainer<int> &resources;
    int corruptionLevel;

public:
    Military(ResourceContainer<int> &res);
    void recruit(int amount, Economy &econ);
    void update();
    int getSoldiers() const { return soldiers; }
    void setSoldiers(int s) { soldiers = s; }
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Leader
{
private:
    std::string name;
    float taxPolicy;
    float militaryFocus;

public:
    Leader(const std::string &n, float tp, float mf);
    void applyPolicies(Economy &econ, Military &mil);
    bool holdElection(const Population &pop);
    std::string getName() const { return name; }
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Economy
{
private:
    int treasury;
    float taxRate;
    float inflation;

public:
    Economy();
    void collectTaxes(const Population &pop);
    void spend(int amount);
    int getTreasury() const { return treasury; }
    void setTaxRate(float tr);
    void update();
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Bank
{
private:
    int loans;
    float interestRate;
    int fraudLevel;

public:
    Bank();
    void issueLoan(Economy &econ, int amount);
    void audit();
    void update();
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Event
{
private:
    std::string type;
    int severity;

public:
    Event(const std::string &t, int s) : type(t), severity(s) {}
    void apply(Population &pop, Military &mil, Economy &econ, ResourceContainer<int> &res);
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Communication
{
private:
    std::vector<std::string> messages;

public:
    void sendMessage(const std::string &msg);
    std::vector<std::string> getMessages() const { return messages; }
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Alliance
{
private:
    std::string kingdom1;
    std::string kingdom2;
    bool active;

public:
    Alliance(const std::string &k1, const std::string &k2);
    void breakAlliance();
    bool isActive() const { return active; }
    std::string getOtherKingdom(const std::string &k) const;
    std::string getKingdom1() const { return kingdom1; }
    std::string getKingdom2() const { return kingdom2; }
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Market
{
private:
    std::map<std::string, int> prices;

public:
    Market();
    void trade(ResourceContainer<int> &res1, ResourceContainer<int> &res2, const std::string &item, int qty, bool smuggling);
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Conflict
{
private:
    std::string attacker;
    std::string defender;
    bool isBetrayal;

public:
    Conflict(const std::string &a, const std::string &d, bool betrayal);
    void resolve(Military &atkMil, Military &defMil, ResourceContainer<int> &atkRes, ResourceContainer<int> &defRes);
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Map
{
private:
    std::vector<std::vector<std::string>> grid;

public:
    Map();
    void placeKingdom(const std::string &name, int x, int y);
    void moveKingdom(const std::string &name, int newX, int newY);
    int getDistance(const std::string &k1, const std::string &k2) const;
    void save(std::ofstream &out) const;
    void load(std::ifstream &in);
};

class Kingdom
{
private:
    std::string name;
    std::shared_ptr<Population> population;
    std::shared_ptr<Military> military;
    std::shared_ptr<Economy> economy;
    std::shared_ptr<Leader> leader;
    std::shared_ptr<Bank> bank;
    std::shared_ptr<Communication> communication;
    std::shared_ptr<Map> map;
    ResourceContainer<int> resources;

public:
    Kingdom(const std::string &n, std::shared_ptr<Map> m);
    void update();
    void save(const std::string &filename) const;
    void load(const std::string &filename);
    Population &getPopulation() { return *population; }
    Military &getMilitary() { return *military; }
    Economy &getEconomy() { return *economy; }
    Leader &getLeader() { return *leader; }
    Bank &getBank() { return *bank; }
    Communication &getCommunication() { return *communication; }
    ResourceContainer<int> &getResources() { return resources; }
    std::string getName() const { return name; }
};

class GameEngine
{
private:
    std::vector<std::shared_ptr<Kingdom>> kingdoms;
    std::vector<std::shared_ptr<Alliance>> alliances;
    std::shared_ptr<Market> market;
    std::shared_ptr<Map> map;
    std::ofstream scoreLog;

public:
    GameEngine();
    void addKingdom(std::shared_ptr<Kingdom> kingdom) { kingdoms.push_back(kingdom); }
    void run();
    void saveGame(const std::string &filename);
    void loadGame(const std::string &filename);
    void logScore();
    void formAlliance(const std::string &k1, const std::string &k2);
    void initiateConflict(const std::string &attacker, const std::string &defender);
};