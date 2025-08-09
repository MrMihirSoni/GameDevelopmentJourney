#include <iostream>

class Hero {
private:
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

    Hero hero1, hero2, hero3;

    hero1.createHero(name1);
    hero2.createHero(name2);
    hero3.createHero(name3);
    hero1.introduce();
    hero1.levelup();
    hero2.introduce();
    hero3.introduce();
    hero2.levelup();
    hero2.levelup();
}