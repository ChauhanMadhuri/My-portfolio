#include<iostream>
#include<string>

using namespace std;

class Student 
{
	int m1,m2,m3;
	string name;
	int total;
	float percentage;
	
	public:
	 void getdata()
	 {
		cout << "Enter your name " ;
		cin >> name;
	
		cout << "Enter your three subject mark" ;
		cin >> m1 >> m2 >> m3 ;
	}
	
	void cal()
	{
	  total = m1 + m2 + m3 ;
	  percentage = total/ 3;
	}
	
	
	void display()
	{
		cout << "\n Name :" <<name << endl;
		cout << "\n Total :" << total << endl ;
		cout << "\n percentage :" << percentage << endl;
		
		if(m1 >= 33 && m2 >= 33 && m3 >= 33 )
		 {
		 	cout << "Your are pass" ;
		 }
		else 
		 {
		 	cout << "your are fail";
		 }
	}		
};

int main()
 {
 	Student s1;
 	
 	s1.getdata();
 	s1.cal();
 	s1.display();
 	
 	return 0;
 }

