//Vehicle system
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    Vehicle(int id, string m, string mo, int y)
    {
        vehicleID = id;
        manufacturer = m;
        model = mo;
        year = y;
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    void setModel(string mo)
    {
        model = mo;
    }

    void setYear(int y)
    {
        year = y;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    virtual void display()
    {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

int Vehicle::totalVehicles = 0;

// Single Inheritance
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "";
    }

    Car(int id, string m, string mo, int y, string f)
        : Vehicle(id, m, mo, y)
    {
        fuelType = f;
    }

    void setFuelType(string f)
    {
        fuelType = f;
    }

    string getFuelType()
    {
        return fuelType;
    }

    void display() override
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    float batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string m, string mo, int y,
                string f, float b)
        : Car(id, m, mo, y, f)
    {
        batteryCapacity = b;
    }

    void display() override
    {
        Car::display();
        cout << "\nBattery Capacity: "
             << batteryCapacity << " kWh";
    }
};

// Multiple Inheritance Base Class
class Aircraft
{
protected:
    float flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(float range)
    {
        flightRange = range;
    }

    virtual ~Aircraft()
    {
    }

    void setFlightRange(float range)
    {
        flightRange = range;
    }

    float getFlightRange()
    {
        return flightRange;
    }

    void displayAircraft()
    {
        cout << "\nFlight Range: "
             << flightRange << " km";
    }
};

// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft()
    {
    }

    FlyingCar(int id, string m, string mo, int y,
              string f, float range)
        : Car(id, m, mo, y, f), Aircraft(range)
    {
    }

    void display() override
    {
        Car::display();
        displayAircraft();
    }
};

// Multilevel Inheritance
class SportsCar : public ElectricCar
{
private:
    float topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(int id, string m, string mo, int y,
              string f, float b, float speed)
        : ElectricCar(id, m, mo, y, f, b)
    {
        topSpeed = speed;
    }

    void display() override
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};

// Hierarchical Inheritance
class Sedan : public Car
{
public:
    Sedan() : Car()
    {
    }

    Sedan(int id, string m, string mo, int y, string f)
        : Car(id, m, mo, y, f)
    {
    }

    void display() override
    {
        cout << "\nType: Sedan";
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV() : Car()
    {
    }

    SUV(int id, string m, string mo, int y, string f)
        : Car(id, m, mo, y, f)
    {
    }

    void display() override
    {
        cout << "\nType: SUV";
        Car::display();
    }
};

// Vehicle Registry Class
class VehicleRegistry
{
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;

        for (int i = 0; i < 100; i++)
        {
            vehicles[i] = NULL;
        }
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }

    void addVehicle()
    {
        if (count >= 100)
        {
            cout << "\nRegistry is full!";
            return;
        }

        int type, id, year;
        string manufacturer, model, fuel;
        float battery, speed, range;

        cout << "\n1. Car";
        cout << "\n2. Electric Car";
        cout << "\n3. Flying Car";
        cout << "\n4. Sports Car";
        cout << "\n5. Sedan";
        cout << "\n6. SUV";
        cout << "\nEnter vehicle type: ";
        cin >> type;

        if (type < 1 || type > 6)
        {
            cout << "\nInvalid vehicle type!";
            return;
        }

        cout << "Enter Vehicle ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle ID already exists!";
                return;
            }
        }

        cout << "Enter Manufacturer: ";
        getline(cin >> ws, manufacturer);

        cout << "Enter Model: ";
        getline(cin, model);

        cout << "Enter Year: ";
        cin >> year;

        switch (type)
        {
        case 1:
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            vehicles[count] =
                new Car(id, manufacturer, model, year, fuel);
            break;

        case 2:
            cout << "Enter Fuel Type (e.g. Electric): ";
            cin >> fuel;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            vehicles[count] =
                new ElectricCar(id, manufacturer, model,
                                year, fuel, battery);
            break;

        case 3:
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cout << "Enter Flight Range (km): ";
            cin >> range;

            vehicles[count] =
                new FlyingCar(id, manufacturer, model,
                              year, fuel, range);
            break;

        case 4:
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            cout << "Enter Top Speed (km/h): ";
            cin >> speed;

            vehicles[count] =
                new SportsCar(id, manufacturer, model,
                              year, fuel, battery, speed);
            break;

        case 5:
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            vehicles[count] =
                new Sedan(id, manufacturer, model, year, fuel);
            break;

        case 6:
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            vehicles[count] =
                new SUV(id, manufacturer, model, year, fuel);
            break;
        }

        count++;
        cout << "\nVehicle added successfully!";
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles registered.";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n\n----------------------";
            cout << "\nVehicle " << i + 1;
            vehicles[i]->display();
        }

        cout << "\n\nTotal Registered Vehicles: " << count;
        cout << "\nTotal Vehicle Objects Created: "
             << Vehicle::getTotalVehicles();
    }

    void searchVehicle()
    {
        int id;

        cout << "\nEnter Vehicle ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found!";
                vehicles[i]->display();
                return;
            }
        }

        cout << "\nVehicle not found!";
    }
};

// Main Function
int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registry.addVehicle();
            break;

        case 2:
            registry.displayAll();
            break;

        case 3:
            registry.searchVehicle();
            break;

        case 4:
            cout << "\nThank you for using Vehicle Registry System!";
            break;

        default:
            cout << "\nInvalid choice! Try again.";
        }

    } while (choice != 4);

    return 0;
}

