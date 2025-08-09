#include <iostream>

class Hero {
protected:
    std::string name = "";
    int level = 1;

public:
    void createHero (std::string name){
        this->name = name;
    }

    void introduce (){
        std::cout<<"Hi! I'm "<<name<<", a Level "<<level<<" hero\n";
    }
    void levelup (){
        level+=1;
        std::cout<<"Congrats "<<name<<"! You are now Level "<<level<<"!\n";
    }


};

class Warrior : public Hero{
public :
    void useSuperPower(){
        std::cout<<name<<" swings his mighty sword!\n";
    }
};
class Wizard : public Hero{
public :
    void useSuperPower(){
        std::cout<<name<<" casts a spell!\n";
    }
};
class Archer : public Hero{
public :
    void useSuperPower(){
        std::cout<<name<<" shoots an arrow!\n";
    }
};

int main(){
    std::string name1;
    std::cout<<"Enter hero 1 name: ";
    std::cin>>name1;
    std::string name2;
    std::cout<<"Enter hero 2 name: ";
    std::cin>>name2;
    std::string name3;
    std::cout<<"Enter hero 3 name: ";
    std::cin>>name3;
    std::cout<<" ";


    Warrior warrior;
    Wizard wizard;
    Archer archer;

    warrior.createHero(name1);
    wizard.createHero(name2);
    archer.createHero(name3);

    warrior.introduce();
    warrior.levelup();
    wizard.introduce();
    archer.introduce();
    archer.levelup();
    archer.levelup();
    wizard.levelup();
    wizard.levelup();

    std::cout<<"\n";

    warrior.introduce();
    wizard.introduce();
    archer.introduce();

    std::cout<<"\n";

    warrior.useSuperPower();
    wizard.useSuperPower();
    archer.useSuperPower();
}