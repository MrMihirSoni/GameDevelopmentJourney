#include <iostream>

class Hero {
public:
    virtual void attack(){
        std::cout<<"Hero attack with bare hands\n";
    }
};

class Wizard : public Hero{
public:
    void attack() override{
        std::cout<<"Wizard cast a spell\n";
    }
};

class Archer : public Hero{
public:
    void attack() override{
        std::cout<<"Archer shot an arrow\n";
    }
};

void battle(Hero* h){
    h->attack();
}

int main(){
    Wizard w;
    Archer a;

    battle(&w);
    battle(&a);
}