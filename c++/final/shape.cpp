/*Define an abstract class `Shape` with pure virtual functions `area()` and `draw()`. Implement concrete classes `Circle` 
and `Rectangle` that inherit from `Shape`. Demonstrate polymorphism by creating an array of `Shape` pointers pointing to
 objects of both `Circle` and `Rectangle`. Call the `area()` and `draw()` functions for each object.*/
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void area() override {
        cout << "Area of Circle: "
             << 3.14 * radius * radius << endl;
    }

    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    void area() override {
        cout << "Area of Rectangle: "
             << length * width << endl;
    }

    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);

    Shape* shapes[2];
    shapes[0] = &c;
    shapes[1] = &r;

    for (int i = 0; i < 2; i++) {
        shapes[i]->area();
        shapes[i]->draw();
        cout << endl;
    }

    return 0;
}

