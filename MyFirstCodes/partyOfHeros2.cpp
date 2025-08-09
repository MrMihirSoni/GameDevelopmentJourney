#include <iostream>
#include <vector>

class Hero {
public :

    virtual void attack() {
        std::cout<<"Hero attacked with bare hands\n";
    }

    virtual void spAttack() = 0;

    virtual ~Hero() {};
};

class Wizard : public Hero {
public: 

    void attack() override {
        std::cout<<"Wizard casts a spell\n";
    }

    void spAttack() override {
        std::cout<<"Wizard throws a lightning strike\n";
    }
};

class Archer : public Hero {
public:

    void attack() override {
        std::cout<<"Archer shoots an arrow\n";
    }

    void spAttack() override {
        std::cout<<"Archer shoots a bomb\n";
    }
};

class Warrier : public Hero {
public:

    void attack() override {
        std::cout<<"Warrier swings his sword\n";
    }

    void spAttack() override {
        std::cout<<"Warrier becomes a giant and crushing everybody\n";
    }
};

class Dragon : public Hero {
public: 
 
    void attack() override {
        std::cout<<"Dragon blows fire\n";
    }

    void spAttack() override {
        std::cout<<"Dragon started a fire strom\n";
    }
};

void battleAll(const std::vector<Hero*> & heros) {
    std::cout<<"Battle starts\n";
    
    for (Hero* hero : heros) {
        hero->attack();
    }
}

void spBattle(const std::vector<Hero*> & heros) {
    std::cout<<"Beaware everyone gonna use their super power\n";

    for(Hero* hero : heros){
        hero->spAttack();
    }
}

int main() {
    Hero* wizard = new Wizard();
    Hero* archer = new Archer();
    Hero* warrier = new Warrier();
    Hero* dragon = new Dragon();

    std::vector<Hero*> party = {wizard, archer, warrier, dragon};

    battleAll(party);
    spBattle(party);

    for (Hero* h: party) {
        delete h;
    }

    return 0;
}