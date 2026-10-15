
/* Vehicle Registry System */

#include <iostream>
#include <cstring>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    char manufacturer[30];
    char model[30];
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        strcpy(manufacturer, "Unknown");
        strcpy(model, "Unknown");
        year = 0;
        totalVehicles++;
    }

    void getData()
    {
        cout << "\nEnter Vehicle ID: ";
        cin >> vehicleID;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;
    }

    int getID()
    {
        return vehicleID;
    }

    virtual void display()
    {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }

    virtual ~Vehicle()
    {
        totalVehicles--;
    }
};

int Vehicle::totalVehicles = 0;


// Single Inheritance
class Car : public Vehicle
{
protected:
    char fuelType[20];

public:
    Car()
    {
        strcpy(fuelType, "Unknown");
    }

    void getCarData()
    {
        getData();

        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void display()
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};


// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar()
    {
        batteryCapacity = 0;
    }

    void getElectricData()
    {
        getCarData();

        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }

    void display()
    {
        Car::display();
        cout << "\nBattery Capacity: "
             << batteryCapacity << " kWh";
    }
};


// Multilevel Inheritance
class SportsCar : public ElectricCar
{
protected:
    int topSpeed;

public:
    SportsCar()
    {
        topSpeed = 0;
    }

    void getSportsData()
    {
        getElectricData();

        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};


// Hierarchical Inheritance
class Sedan : public Car
{
public:
    void display()
    {
        cout << "\n--- Sedan Details ---";
        Car::display();
    }
};


// Hierarchical Inheritance
class SUV : public Car
{
public:
    void display()
    {
        cout << "\n--- SUV Details ---";
        Car::display();
    }
};


// Base Class for Multiple Inheritance
class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    void getFlightData()
    {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }

    void displayFlight()
    {
        cout << "\nFlight Range: " << flightRange << " km";
    }
};


// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    void getFlyingData()
    {
        getCarData();
        getFlightData();
    }

    void display()
    {
        cout << "\n--- Flying Car Details ---";
        Car::display();
        displayFlight();
    }
};


// Vehicle Registry Class
class VehicleRegistry
{
private:
    Vehicle *v[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;

        for (int i = 0; i < 100; i++)
        {
            v[i] = NULL;
        }
    }

    void addVehicle()
    {
        int choice;

        if (count >= 100)
        {
            cout << "\nRegistry is Full!";
            return;
        }

        cout << "\n1. Car";
        cout << "\n2. Electric Car";
        cout << "\n3. Sports Car";
        cout << "\n4. Sedan";
        cout << "\n5. SUV";
        cout << "\n6. Flying Car";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                v[count] = new Car;
                ((Car*)v[count])->getCarData();
                break;

            case 2:
                v[count] = new ElectricCar;
                ((ElectricCar*)v[count])->getElectricData();
                break;

            case 3:
                v[count] = new SportsCar;
                ((SportsCar*)v[count])->getSportsData();
                break;

            case 4:
                v[count] = new Sedan;
                ((Sedan*)v[count])->getCarData();
                break;

            case 5:
                v[count] = new SUV;
                ((SUV*)v[count])->getCarData();
                break;

            case 6:
                v[count] = new FlyingCar;
                ((FlyingCar*)v[count])->getFlyingData();
                break;

            default:
                cout << "\nInvalid Choice!";
                return;
        }

        count++;
        cout << "\nVehicle Added Successfully!";
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "\nNo Vehicles Available!";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n\n--------------------";
            v[i]->display();
        }
    }

    void searchVehicle()
    {
        int id;

        cout << "\nEnter Vehicle ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (v[i]->getID() == id)
            {
                cout << "\nVehicle Found!";
                v[i]->display();
                return;
            }
        }

        cout << "\nVehicle Not Found!";
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete v[i];
        }
    }
};


// Main Function
int main()
{
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle";
        cout << "\n4. Total Vehicles";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                vr.addVehicle();
                break;

            case 2:
                vr.displayAll();
                break;

            case 3:
                vr.searchVehicle();
                break;

            case 4:
                cout << "\nTotal Vehicles: "
                     << Vehicle::totalVehicles;
                break;

            case 5:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 5);

    return 0;
}

