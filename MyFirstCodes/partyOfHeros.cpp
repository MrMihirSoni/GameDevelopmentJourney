#include <iostream>
#include <vector>

class Hero{
public:
    virtual void attack (){
        std::cout<<"Hero attacked with his bare hands\n";
    }

    virtual ~ Hero(){}
};

class Wizard : public Hero{
public:
    void attack() override{
        std::cout<<"Wizard casts a spell\n";
    }
};

class Archer : public Hero{
public:
    void attack() override{
        std::cout<<"Archer shots an arrow\n";
    }
};

class Warrier : public Hero{
public:
    void attack() override{
        std::cout<<"Warrier swings his sword\n";
    }
};

class Dragon : public Hero{
public: 
    void attack() override{
        std::cout<<"Dragon blows fire\n";
    }
};

void battleAll(const std::vector<Hero*> & heroes){
    std::cout<<"Battle starts\n";
    for(Hero* hero: heroes){
        hero->attack();
    }
}

int main(){
    Hero* wizard = new Wizard();
    Hero* archer = new Archer();
    Hero* warrier = new Warrier();
    Hero* dragon = new Dragon();

    std::vector<Hero*> party = {wizard, archer, warrier, dragon};

    battleAll(party);

    for(Hero* h: party){
        delete h;
    }

    return 0;
}