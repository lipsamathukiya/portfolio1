/*Student Result Management System */
#include<iostream>
using namespace std;

class Student
{
	string name;
	int m1,m2,m3,total;
	float percentage;
	
public:
	void getData()
	{
		cout<<"Enter name:";
		cin>> name;
		
		cout<<"Enter marks of 3 subjects:";
		cin>> m1>>m2>>m3;
	}
	void display()
	{
		total = m1+m2+m3;
		percentage = total / 3.0;
		
		cout<<"\n Name:"<< name;
		cout<<"\n Total:"<<total;
		cout<<"\n percentage:" << percentage <<"%";
		
		if( m1 >=35 && m2 >=35 && m3 >=35)
		cout<<"\n Result: pass";
		else
		cout <<"\n Result: Fail";
	}
};

int main()
{
	Student s;
	s.getData();
	s.display();

return 0;
}
