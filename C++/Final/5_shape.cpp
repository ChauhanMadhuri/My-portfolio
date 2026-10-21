
#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
    virtual void calculateArea() = 0;
    virtual void draw() = 0;
};

// Derived class
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void calculateArea() override
    {
        cout << "Circle Area: "
             << 3.14 * radius * radius << endl;
    }

    void draw() override
    {
        cout << "Drawing Circle" << endl;
    }
};

// Derived class
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    void calculateArea() override
    {
        cout << "Rectangle Area: "
             << length * width << endl;
    }

    void draw() override
    {
        cout << "Drawing Rectangle" << endl;
    }
};

// Main function
int main()
{
    Circle c(5);
    Rectangle r(4, 6);

    Shape *s[2];

    s[0] = &c;
    s[1] = &r;

    for (int i = 0; i < 2; i++)
    {
        s[i]->calculateArea();
        s[i]->draw();
        cout << endl;
    }

    return 0;
}

