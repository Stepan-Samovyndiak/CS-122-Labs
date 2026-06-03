#include <iostream>
#include <string>
#include <random>

using namespace std;

class Hero {
private:
    int strength;
    int courage;
    string name;

public:
    Hero(string heroName) {
        name = heroName;
        
       
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> strengthDist(10, 50);
        uniform_int_distribution<> courageDist(20, 60);  
        
        strength = strengthDist(gen);
        courage = courageDist(gen);
    }

    
    string getName() const {
        return name;
    }

    int getStrength() const {
        return strength;
    }

    int getCourage() const {
        return courage;
    }

    void setCourage(int newCourage) {
        courage = newCourage;
    }

    
    void attendTraining(int hours) {
        strength += hours * 2; 
    }

    void attendTherapy() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> therapyDist(5, 15); 
        courage += therapyDist(gen);
    }
};


void sendOnQuest(Hero& hero) {
    random_device rd;
    mt19937 gen(rd());
    
    
    int maxRoll = 50 + hero.getStrength();
    uniform_int_distribution<> questDist(1, maxRoll);
    int roll = questDist(gen);

    string outcome;
    int courageLoss = 0;

    if (roll > 75) {
        outcome = "Success!";
        courageLoss = 5;
    } else if (roll > 40) {
        outcome = "Neutral Result.";
        courageLoss = 15;
    } else {
        outcome = "Failure...";
        courageLoss = 30;
    }

    
    int finalCourage = hero.getCourage() - courageLoss;
    if (finalCourage < 0) finalCourage = 0;
    hero.setCourage(finalCourage);

    cout << hero.getName() << " went on a quest. Result: " << outcome << endl;
}

int main() {
    cout << "--- Testing Hero System ---" << endl;

    
    Hero hero1("Arthur");
    Hero hero2("Beowulf");

    cout << hero1.getName() << "'s starting stats - Strength: " << hero1.getStrength() << ", Courage: " << hero1.getCourage() << endl;
    cout << hero2.getName() << "'s starting stats - Strength: " << hero2.getStrength() << ", Courage: " << hero2.getCourage() << endl;
    cout << endl;

    
    cout << "Training and therapy sessions underway..." << endl;
    hero1.attendTraining(5);
    hero1.attendTherapy();
    
    hero2.attendTraining(2);
    hero2.attendTherapy();

    cout << hero1.getName() << "'s post-prep stats - Strength: " << hero1.getStrength() << ", Courage: " << hero1.getCourage() << endl;
    cout << hero2.getName() << "'s post-prep stats - Strength: " << hero2.getStrength() << ", Courage: " << hero2.getCourage() << endl;
    cout << endl;

    
    cout << "--- Sending Heroes on Quests ---" << endl;
    sendOnQuest(hero1);
    sendOnQuest(hero1);
    sendOnQuest(hero2);
    sendOnQuest(hero2);
    
    cout << endl;
    cout << hero1.getName() << "'s final stats - Courage left: " << hero1.getCourage() << endl;
    cout << hero2.getName() << "'s final stats - Courage left: " << hero2.getCourage() << endl;

    return 0;
}