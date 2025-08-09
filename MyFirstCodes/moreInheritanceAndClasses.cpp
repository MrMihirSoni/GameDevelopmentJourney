#include <iostream>

class Weapon {
protected:
    std::string weaponName;
    int level;

public:
    Weapon(){
        weaponName = "";
        level = 0;
    }

    Weapon(std::string name){
        weaponName = name;
        level = 1;
    }

    std::string getWeaponName (){
        return weaponName;
    }

    int getWeaponLevel(){
        return level;
    }

    void levelup(){
        level+=1;
        std::cout<<weaponName<<" is now Level : "<<level<<"\n";
    }

    void attack(std::string heroName){
        std::cout<<heroName<<" attacked with "<<weaponName<<"\n";
    }

};

class Hero {

protected:
    std::string name;
    int level;
    Weapon weapon;

public:
    Hero() {
        name = "unknown";
        level = 1;
    }

    Hero(std::string name){
        this->name = name;
        level = 1;
    }

    std::string getName(){
        return name;
    }

    void introduce(){
        std::cout<<"I'm "<<name<<", Level : "<<level<<"\n";
    }

    void levelup(){
        level+=1;
        std::cout<<"Congrats "<<name<<"! You are now Level : "<<level<<"!\n";
    }

    void giveWeapon(const std::string & weaponName){
        weapon = Weapon(weaponName);
    }

    void weaponIntroduce(){
        std::cout<<name<<"'s "<<weapon.getWeaponName()<<", Level : "<<weapon.getWeaponLevel()<<"!\n";
    }

    void weaponLevelup(){
        weapon.levelup();
    }

    void attack (){
        if (weapon.getWeaponName() == ""){
            std::cout<<name<<" attacking with his fist!\n";
        }
        else {
            weapon.attack(name);
        }
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

    Hero hero1(name1);
    Hero hero2(name2);
    Hero hero3(name3);

    hero1.introduce();
    hero2.introduce();
    hero3.introduce();

    hero1.attack();
    hero2.attack();
    hero3.attack();

    std::string weapon1;
    std::string weapon2;
    std::string weapon3;

    std::cout<<"Enter weapon name for "<<hero1.getName()<<" : ";
    std::cin>>weapon1;
    hero1.giveWeapon(weapon1);
    std::cout<<"Enter weapon name for "<<hero2.getName()<<" : ";
    std::cin>>weapon2;
    hero2.giveWeapon(weapon2);
    std::cout<<"Enter weapon name for "<<hero3.getName()<<" : ";
    std::cin>>weapon3;
    hero3.giveWeapon(weapon3);

    hero1.weaponIntroduce();
    hero2.weaponIntroduce();
    hero3.weaponIntroduce();

    hero1.levelup();
    hero2.weaponLevelup();
    hero3.weaponIntroduce();

    hero1.attack();
    hero2.attack();
    hero3.attack();

}

