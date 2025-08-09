#include <iostream>
#include <vector>

class Hero {
protected:
    int coolDown = 0;

public:
    virtual void attack(){
        std::cout<<"Hero attacked with bare hands\n";
    }

    virtual void spAttack() = 0;

    virtual bool canUseSpAttack() const = 0;

    void reduceCoolDown() {
        if(coolDown>0) coolDown--;
    }

    void resetCoolDown(int n) {
        coolDown = n;
    }

    virtual ~Hero() {};
};

class Wizard : public Hero {
public:
    void attack() override {
        std::cout<<"Wizard casts a spell\n";
        reduceCoolDown();
    }

    void spAttack() override {
        if(canUseSpAttack()){
            std::cout<<"Wizard throws a lightning strike\n";
            resetCoolDown(2);
        }
        else {
            std::cout<<"Wizard: SpAttack not ready\n";
        }
    }

    bool canUseSpAttack() const override {
        return coolDown == 0;
    }
};

class Archer : public Hero {
public: 
    void attack() override {
        std::cout<<"Archer shoots an arrow\n";
        reduceCoolDown();
    }

    void spAttack() override {
        if (canUseSpAttack()){
            std::cout<<"Archer shoots a bomb\n";
            resetCoolDown(2);
        }
        else {
            std::cout<<"Archer: SpAttack not ready\n";
        }
    }

    bool canUseSpAttack() const override {
        return coolDown == 0;
    }
};

class Warrier : public Hero {
public:
    void attack() override {
        std::cout<<"Warrier swings his sword\n";
        reduceCoolDown();
    }

    void spAttack() override {
        if (canUseSpAttack()){
            std::cout<<"Warrier becomes a giant and crushes everybody\n";
            resetCoolDown(2);
        }
        else {
            std::cout<<"Warrier: SpAttack not ready\n";
        }
    }

    bool canUseSpAttack() const override {
        return coolDown == 0;
    }
};

class Dragon : public Hero {
public: 
    void attack() override {
        std::cout<<"Dragon blows fire\n";
        reduceCoolDown();
    }

    void spAttack() override {
        if (canUseSpAttack()){
            std::cout<<"Dragon started a fire strom\n";
            resetCoolDown(2);
        }
        else {
            std::cout<<"Dragon: SpAttack not ready\n";
        }
    }

    bool canUseSpAttack() const override {
        return coolDown == 0;
    }
};

void battleAll(std::vector<Hero*> & heros){
    for (Hero* hero : heros) {
        hero->attack();
    }
}

void spBattle(std::vector<Hero*> & heros){
    for (Hero* hero : heros){
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
    battleAll(party);
    spBattle(party);
    battleAll(party);
    spBattle(party);
    
    return 0;

}

