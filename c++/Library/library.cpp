
/* Library Management System */

#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;
    bool issued;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
        issued = false;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    bool getIssued() const
    {
        return issued;
    }

    void setIssued(bool status)
    {
        issued = status;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem()
    {
    }
};

// Book Class
class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        if (i.length() != 13)
        {
            throw "Invalid ISBN! ISBN must contain 13 digits.";
        }

        for (int j = 0; j < 13; j++)
        {
            if (i[j] < '0' || i[j] > '9')
            {
                throw "Invalid ISBN! Enter 13 digits.";
            }
        }

        isbn = i;
    }

    void checkOut() override
    {
        if (getIssued())
        {
            cout << "Book is already checked out!" << endl;
        }
        else
        {
            setIssued(true);
            cout << "Book checked out successfully!" << endl;
        }
    }

    void returnItem() override
    {
        if (!getIssued())
        {
            cout << "Book is not checked out!" << endl;
        }
        else
        {
            setIssued(false);
            cout << "Book returned successfully!" << endl;
        }
    }

    void displayDetails() const override
    {
        cout << "\nType: Book" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: "
             << (getIssued() ? "Checked Out" : "Available")
             << endl;
    }
};

// DVD Class
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
        {
            throw "Invalid duration! Enter a positive number.";
        }

        duration = dur;
    }

    void checkOut() override
    {
        if (getIssued())
        {
            cout << "DVD is already checked out!" << endl;
        }
        else
        {
            setIssued(true);
            cout << "DVD checked out successfully!" << endl;
        }
    }

    void returnItem() override
    {
        if (!getIssued())
        {
            cout << "DVD is not checked out!" << endl;
        }
        else
        {
            setIssued(false);
            cout << "DVD returned successfully!" << endl;
        }
    }

    void displayDetails() const override
    {
        cout << "\nType: DVD" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Status: "
             << (getIssued() ? "Checked Out" : "Available")
             << endl;
    }
};

// Magazine Class
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        if (issue <= 0)
        {
            throw "Invalid issue number! Enter a positive number.";
        }

        issueNumber = issue;
    }

    void checkOut() override
    {
        if (getIssued())
        {
            cout << "Magazine is already checked out!" << endl;
        }
        else
        {
            setIssued(true);
            cout << "Magazine checked out successfully!" << endl;
        }
    }

    void returnItem() override
    {
        if (!getIssued())
        {
            cout << "Magazine is not checked out!" << endl;
        }
        else
        {
            setIssued(false);
            cout << "Magazine returned successfully!" << endl;
        }
    }

    void displayDetails() const override
    {
        cout << "\nType: Magazine" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Status: "
             << (getIssued() ? "Checked Out" : "Available")
             << endl;
    }
};

// Main Function
int main()
{
    LibraryItem* libraryItems[MAX_ITEMS] = {};
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Search Item" << endl;
        cout << "6. Check Out Item" << endl;
        cout << "7. Return Item" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Enter a number." << endl;
            continue;
        }

        try
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                if (count >= MAX_ITEMS)
                {
                    throw "Library is full! Cannot add more items.";
                }

                string title, author, dueDate;

                cin.ignore(10000, '\n');

                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter due date: ";
                getline(cin, dueDate);

                if (title.empty() || author.empty() || dueDate.empty())
                {
                    throw "Title, author and due date cannot be empty!";
                }

                if (choice == 1)
                {
                    string isbn;

                    cout << "Enter 13-digit ISBN: ";
                    getline(cin, isbn);

                    libraryItems[count] =
                        new Book(title, author, dueDate, isbn);

                    cout << "Book added successfully!" << endl;
                }
                else if (choice == 2)
                {
                    int duration;

                    cout << "Enter DVD duration in minutes: ";

                    if (!(cin >> duration))
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Invalid duration input!";
                    }

                    libraryItems[count] =
                        new DVD(title, author, dueDate, duration);

                    cout << "DVD added successfully!" << endl;
                }
                else
                {
                    int issue;

                    cout << "Enter magazine issue number: ";

                    if (!(cin >> issue))
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw "Invalid issue number input!";
                    }

                    libraryItems[count] =
                        new Magazine(title, author, dueDate, issue);

                    cout << "Magazine added successfully!" << endl;
                }

                count++;
            }
            else if (choice == 4)
            {
                if (count == 0)
                {
                    cout << "No items available!" << endl;
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\nItem Number: " << i + 1 << endl;
                        libraryItems[i]->displayDetails();
                    }
                }
            }
            else if (choice == 5)
            {
                string searchTitle;
                bool found = false;

                cin.ignore(10000, '\n');

                cout << "Enter title to search: ";
                getline(cin, searchTitle);

                for (int i = 0; i < count; i++)
                {
                    if (libraryItems[i]->getTitle() == searchTitle)
                    {
                        libraryItems[i]->displayDetails();
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "Item not found!" << endl;
                }
            }
            else if (choice == 6 || choice == 7)
            {
                if (count == 0)
                {
                    cout << "No items available!" << endl;
                    continue;
                }

                int number;

                cout << "Enter item number (1 to " << count << "): ";

                if (!(cin >> number))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw "Invalid item number!";
                }

                if (number < 1 || number > count)
                {
                    throw "Invalid item number!";
                }

                if (choice == 6)
                {
                    libraryItems[number - 1]->checkOut();
                }
                else
                {
                    libraryItems[number - 1]->returnItem();
                }
            }
            else if (choice == 8)
            {
                cout << "Thank you for using Library Management System!"
                     << endl;
            }
            else
            {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
        catch (const char* error)
        {
            cout << "Error: " << error << endl;
        }
        catch (...)
        {
            cout << "Something went wrong!" << endl;
        }

    } while (choice != 8);

    // Release allocated memory
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}

