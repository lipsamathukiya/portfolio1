/*Define a base class `Animal` with private attributes `name` and `sound`. Implement public methods for setting and getting 
these attributes. Derive two classes, `Dog` and `Cat`, from the `Animal` class. Implement methods to make each animal 
produce its specific sound. Demonstrate abstraction by calling the sound methods for both `Dog` and `Cat`.*/
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
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << getName() << " says " << getSound() << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << getName() << " says " << getSound() << endl;
    }
};

int main() {
    Dog d;
    d.setName("Dog");
    d.setSound("Bark");
    d.makeSound();

    Cat c;
    c.setName("Cat");
    c.setSound("Meow");
    c.makeSound();

    return 0;
}

