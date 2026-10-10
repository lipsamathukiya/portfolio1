/* Railway Reservation System */

#include<iostream>
#include<cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");

        trainCount++;
    }

    Train(int number, const char name[], const char src[], const char dest[],const char time[])
    {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(const char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(const char src[])
    {
        strcpy(source, src);
    }

    void setDestination(const char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char time[])
    {
        strcpy(trainTime, time);
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    const char* getTrainName()
    {
        return trainName;
    }

    const char* getSource()
    {
        return source;
    }

    const char* getDestination()
    {
        return destination;
    }

    const char* getTrainTime()
    {
        return trainTime;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> ws;
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;


class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "Train records are full!" << endl;
            return;
        }

        trains[totalTrains].inputTrainDetails();
        totalTrains++;

        cout << "Train record added successfully!" << endl;
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records found!" << endl;
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " details:" << endl;
            trains[i].displayTrainDetails();
        }

        cout << "\nTotal Train Records: "
             << totalTrains << endl;
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain record found!" << endl;
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train with number " << number
             << " not found!" << endl;
    }
};


int main()
{
    RailwaySystem railway;
    int choice, number;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                railway.addTrain();
                break;

            case 2:
                railway.displayAllTrains();
                break;

            case 3:
                cout << "Enter Train Number to search: ";
                cin >> number;
                railway.searchTrainByNumber(number);
                break;

            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
