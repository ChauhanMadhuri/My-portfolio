//// 4. Extend the `Vehicle` hierarchy from Question 3 to include a virtual function 
//`displayDetails()`. Implement the `displayDetails()` function in each derived 
//class to print information specific to the vehicle. Create an array of `Vehicle`
// pointers, pointing to objects of different vehicles. Demonstrate polymorphism by 
// calling the `displayDetails()` function for each object.



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

    virtual void displayDetails()
    {
        cout << "Vehicle Model: " << model << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

// Derived Class Car
class Car : public Vehicle
{
public:
    void displayDetails() override
    {
        cout << "\n--- Car Details ---" << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/h" << endl;
        cout << "Type: Four Wheeler" << endl;
    }
};

// Derived Class Bike
class Bike : public Vehicle
{
public:
    void displayDetails() override
    {
        cout << "\n--- Bike Details ---" << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/h" << endl;
        cout << "Type: Two Wheeler" << endl;
    }
};

int main()
{
    Car c;
    Bike b;

    c.setData("Swift", 120);
    b.setData("Pulsar", 90);

    Vehicle *v[2];

    v[0] = &c;
    v[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        v[i]->displayDetails();
    }

    return 0;
}

