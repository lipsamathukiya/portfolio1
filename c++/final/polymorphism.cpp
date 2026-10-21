/*Extend the `Animal` hierarchy from Question 3 to include a virtual function `displayDetails()`. Implement the `
displayDetails()` function in each derived class to print information specific to the animal. Create an array of `Animal`
 pointers, pointing to objects of different animals. Demonstrate polymorphism by calling the `displayDetails()` function for 
 each object.*/
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    string sound;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setSound(string s) {
        sound = s;
    }

    string getSound() {
        return sound;
    }

    virtual void displayDetails() {
        cout << "Animal Name: " << name << endl;
        cout << "Animal Sound: " << sound << endl;
    }
};

class Dog : public Animal {
public:
    void displayDetails() override {
        cout << "Animal: " << getName() << endl;
        cout << "Sound: " << getSound() << endl;
        cout << "Type: Domestic Animal" << endl;
    }
};

class Cat : public Animal {
public:
    void displayDetails() override {
        cout << "Animal: " << getName() << endl;
        cout << "Sound: " << getSound() << endl;
        cout << "Type: Pet Animal" << endl;
    }
};

int main() {
    Dog d;
    d.setName("Dog");
    d.setSound("Bark");

    Cat c;
    c.setName("Cat");
    c.setSound("Meow");

    Animal* animals[2];
    animals[0] = &d;
    animals[1] = &c;

    for (int i = 0; i < 2; i++) {
        animals[i]->displayDetails();
        cout << endl;
    }

    return 0;
}

