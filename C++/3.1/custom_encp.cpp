#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
    int cust_id;
    string cust_name;
    int cust_age;
    string cust_city;
    string cust_mobile_number;
    int cust_simcard_validity;
    string cust_telecom_brand_name;

public:
    void setData(int id, string name, int age, string city,
                 string mobile, int validity, string brand)
    {
        cust_id = id;
        cust_name = name;
        cust_age = age;
        cust_city = city;
        cust_mobile_number = mobile;
        cust_simcard_validity = validity;
        cust_telecom_brand_name = brand;
    }

    void displayData()
    {
        cout << "Customer ID          : " << cust_id << endl;
        cout << "Customer Name        : " << cust_name << endl;
        cout << "Customer Age         : " << cust_age << endl;
        cout << "Customer City        : " << cust_city << endl;
        cout << "Mobile Number        : " << cust_mobile_number << endl;
        cout << "SIM Validity         : "
             << cust_simcard_validity << " years" << endl;
        cout << "Telecom Brand        : "
             << cust_telecom_brand_name << endl;
        cout << "-----------------------------" << endl;
    }
};

int main()
{
    Customer c[5];

    int id, age, validity;
    string name, city, mobile, brand;

    // Input for 5 customers
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details of Customer " << i + 1 << endl;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter City: ";
        cin >> city;

        cout << "Enter Mobile Number: ";
        cin >> mobile;

        cout << "Enter SIM Card Validity: ";
        cin >> validity;

        cout << "Enter Telecom Brand: ";
        cin >> brand;

        c[i].setData(id, name, age, city, mobile, validity, brand);
    }

    cout << "\n===== CUSTOMER RECORD SYSTEM =====" << endl;

    // Display 5 customers
    for (int i = 0; i < 5; i++)
    {
        cout << "\nCustomer " << i + 1 << endl;
        c[i].displayData();
    }

    return 0;
}