/*Create a class representing a `Book` with attributes like `title`, `author`, and `publishedYear`. 
Demonstrate the instantiation of objects using array and accessing their attributes.*/
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    int publishedYear;
};

int main() {
    Book books[3] = {
        {"Harry Potter", "J.K. Rowling", 1997},
        {"Wings of Fire", "A.P.J. Abdul Kalam", 1999},
        {"The Alchemist", "Paulo Coelho", 1988}
    };

    for (int i = 0; i < 3; i++) {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Published Year: " << books[i].publishedYear << endl;
        cout << endl;
    }

    return 0;
}

