/*Define a class `Person` with private attributes `name`, `age`, and `address`. Encapsulate these attributes using getter 
and setter methods. Implement a parameterized constructor for the `Person` class. Create N number of objects using this 
constructor and display the details.*/
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }

    void setAddress(string addr) {
        address = addr;
    }

    string getAddress() {
        return address;
    }

    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

int main() {
    Person p[3] = {
        Person("Lipsa", 20, "Ahmedabad"),
        Person("Pinal", 21, "Surat"),
        Person("Dharmi", 22, "Rajkot")
    };

    for (int i = 0; i < 3; i++) {
        cout << "\nPerson " << i + 1 << endl;
        p[i].display();
    }

    return 0;
}

