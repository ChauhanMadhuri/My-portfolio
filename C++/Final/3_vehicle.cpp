////3. Define a base class `Vehicle` with private attributes `model` and `speed`. 
//Implement public member functions for setting and getting these attributes. 
//Derive two classes, `Car` and `Bike`, from the `Vehicle` class. Implement 
//methods to calculate the time taken for a certain distance based on the 
//speed of each vehicle. Demonstrate abstraction by calling the time calculation 
//methods for both `Car` and `Bike`.



#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle
{
private:
    string model;
    double speed;

public:
    void setData(string m, double s)
    {
        model = m;
        speed = s;
    }

    string getModel()
    {
        return model;
    }

    double getSpeed()
    {
        return speed;
    }
};

// Derived Class Car
class Car : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        cout << "Car Model: " << getModel() << endl;
        cout << "Time Taken: "
             << distance / getSpeed() << " hours" << endl;
    }
};

// Derived Class Bike
class Bike : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        cout << "Bike Model: " << getModel() << endl;
        cout << "Time Taken: "
             << distance / getSpeed() << " hours" << endl;
    }
};

int main()
{
    Car c;
    Bike b;

    c.setData("Swift", 60);
    b.setData("Honda", 40);

    double distance = 120;

    cout << "--- Car Details ---" << endl;
    c.calculateTime(distance);

    cout << "\n--- Bike Details ---" << endl;
    b.calculateTime(distance);

    return 0;
}

