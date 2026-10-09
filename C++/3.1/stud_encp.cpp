#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int stu_id;
    string stu_name;
    int stu_age;
    string stu_course;
    string stu_city;
    string stu_email;
    string stu_college;

public:
    void setData(int id, string name, int age, string course,
                 string city, string email, string college)
    {
        stu_id = id;
        stu_name = name;
        stu_age = age;
        stu_course = course;
        stu_city = city;
        stu_email = email;
        stu_college = college;
    }

    void displayData()
    {
        cout << "Student ID       : " << stu_id << endl;
        cout << "Student Name     : " << stu_name << endl;
        cout << "Student Age      : " << stu_age << endl;
        cout << "Student Course   : " << stu_course << endl;
        cout << "Student City     : " << stu_city << endl;
        cout << "Student Email    : " << stu_email << endl;
        cout << "Student College  : " << stu_college << endl;
        cout << "-----------------------------" << endl;
    }
};

int main()
{
    Student s[5];

    int id, age;
    string name, course, city, email, college;

    // Input for 5 students
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Course: ";
        cin >> course;

        cout << "Enter City: ";
        cin >> city;

        cout << "Enter Email: ";
        cin >> email;

        cout << "Enter College: ";
        cin >> college;

        s[i].setData(id, name, age, course, city, email, college);
    }

    cout << "\n===== STUDENT RECORD SYSTEM =====" << endl;

    // Display 5 students
    for (int i = 0; i < 5; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        s[i].displayData();
    }

    return 0;
}