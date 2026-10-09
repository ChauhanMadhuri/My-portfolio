#include <iostream.h>
#include <string.h>
#include <conio.h>

class Employee
{
public:
    int emp_id;
    char emp_name[50];
    int emp_age;
    char emp_role[50];
    float emp_salary;
    char emp_city[50];
    int emp_experience;
    char emp_company_name[50];

    void setData(int id, char name[], int age, char role[],
                 float salary, char city[], int experience,
                 char company[])
    {
        emp_id = id;
        strcpy(emp_name, name);
        emp_age = age;
        strcpy(emp_role, role);
        emp_salary = salary;
        strcpy(emp_city, city);
        emp_experience = experience;
        strcpy(emp_company_name, company);
    }

    void display()
    {
	cout << "Employee ID          : " << emp_id <<endl;
	cout << "Employee Name        : " << emp_name <<endl ;
	cout << "Employee Age         : " << emp_age <<endl;
	cout << "Employee Role        : " << emp_role<< endl ;
	cout << "Employee Salary      : " << emp_salary<<endl ;
	cout << "Employee City        : " << emp_city<<endl ;
	cout << "Employee Experience  : " << emp_experience << " years" ;
	cout << "Company Name : "   << emp_company_name ;
        cout << "-------------------------------" << endl;
    }
};

int main()
{
    clrscr();

    Employee emp1, emp2, emp3, emp4, emp5;

    emp1.setData(101, "Rahul", 25, "Developer",
               30000, "Rajkot", 2, "TCS");

    emp2.setData(102, "Priya", 24, "Designer",
               28000, "Ahmedabad", 1, "Infosys");

   emp3.setData(103, "Amit", 27, "Manager",
               45000, "Surat", 4, "Wipro");

    emp4.setData(104, "Neha", 26, "Tester",
               32000, "Vadodara", 3, "Accenture");

    emp5.setData(105, "Karan", 23, "Developer",
               25000, "Junagadh", 1, "Tech Mahindra");

    cout << "\n===== EMPLOYEE RECORD SYSTEM =====\n";

    cout << "\nEmployee 1" << endl;
    emp1.display();

    cout << "\nEmployee 2" << endl;
    emp2.display();

    cout << "\nEmployee 3" << endl;
    emp3.display();

    cout << "\nEmployee 4" << endl;
    emp4.display();

    cout << "\nEmployee 5" << endl;
    emp5.display();

    getch();
    return 0;
}