#include <iostream>
class Hero;
class Monster;

class Hero {
protected:
    int cooldown = 0;
    int health = 100;

public:
    virtual void attack(Monster &monster) = 0;

    virtual void spAttack(Monster &monster) = 0;

    virtual bool canUseSpAttack() = 0;

    void takeDamage(int amount) {
        health-=amount;
        if (health < 0) health = 0;
        std::cout << "Hero takes: " << amount << " damage, Health now: " << health << std::endl;
    }

    void reduceCooldown() {
        if (cooldown > 0) cooldown--;
    }

    void resetCoolDown(int n) {
        cooldown = n;
    }

    int getHealth() {
        return health;
    }

    virtual ~Hero() {};
};

class Monster {
protected:
    int health = 250;

public:
    void attack(Hero* &hero) {
        std::cout << "Monster attack with its claw!" << std::endl;
        hero->takeDamage(10);
    }

    void takeDamage(int amount) {
        health-=amount;
        if (health < 0) health = 0;
        std::cout << "Monster takes: " << amount << " damage, Health now: " << health << std::endl;
    }
    int getHealth() {
        return health;
    }
};

class Wizard : public Hero {
public: 
    void attack(Monster &monster) override {
        std::cout << "Wizzard cast a magic spell" << std::endl;
        monster.takeDamage(15);
        reduceCooldown();
    }

    void spAttack(Monster &monster) override {
        if (canUseSpAttack()) {
            std::cout << "Wizzard throws a lightning strick!" << std::endl;
            monster.takeDamage(30);
            resetCoolDown(2);
        }
        else std::cout << "Sp attack not ready" << std::endl;
    }

    bool canUseSpAttack() override{
        return cooldown == 0;
    }
};

int main() {
    Wizard wiz;
    Monster mon;

    while ((wiz.getHealth() > 0) && (mon.getHealth() > 0)) {
        wiz.attack(mon);
        if (mon.getHealth() <= 0) {
            std::cout << "Hero Wins!!" << std::endl;
            break;
        }
        wiz.spAttack(mon);

        if (mon.getHealth() <= 0) {
            std::cout << "Hero Wins!!" << std::endl;
            break;
        }

        Hero* heroPtr = &wiz;
        mon.attack(heroPtr);

        if (wiz.getHealth() <= 0) {
            std::cout << "Monster Wins!!" << std::endl;
            break;
        }

        std::cout << "Next Round ------------- >" << std::endl;

    }

    std::cout << "Wizard's health remaining: " << wiz.getHealth() << std::endl;
    
    std::cout << "Monster's health remaining: " << mon.getHealth() << std::endl;
}