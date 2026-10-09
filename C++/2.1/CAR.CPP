#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

class Car
{
public:
    int car_id;
    char car_company_name[50];
    char car_color[20];
    char car_model[30];
    int car_release_year;

    void setData(int id, const char company[], const char color[],
                 const char model[], int year)
    {
        car_id = id;
        strcpy(car_company_name, company);
        strcpy(car_color, color);
        strcpy(car_model, model);
        car_release_year = year;
    }

    void displayData()
    {
        cout << "Car ID             : " << car_id << endl;
        cout << "Company Name       : " << car_company_name << endl;
        cout << "Car Color          : " << car_color << endl;
        cout << "Car Model          : " << car_model << endl;
        cout << "Release Year       : " << car_release_year << endl;
        cout << "-----------------------------" << endl;
    }
};

int main()
{
    Car car1, car2, car3, car4;

    car1.setData(1, "Toyota", "White", "Fortuner", 2022);
    car2.setData(2, "BMW", "Black", "X5", 2023);
    car3.setData(3, "Honda", "Red", "City", 2021);
    car4.setData(4, "Hyundai", "Blue", "Creta", 2024);

    cout << "\n===== CAR RECORD SYSTEM =====\n" << endl;

    cout << "Car 1" << endl;
    car1.displayData();

    cout << "Car 2" << endl;
    car2.displayData();

    cout << "Car 3" << endl;
    car3.displayData();

    cout << "Car 4" << endl;
    car4.displayData();

    getch();
    return 0;
}
