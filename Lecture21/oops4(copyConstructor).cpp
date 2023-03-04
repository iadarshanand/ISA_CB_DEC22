#include<iostream>
using namespace std;

class student
{
private:
	string address;
public:
	int age;
	int roll;
	string name;
	char gender;
	string branch;

	//Inbuilt default constructor
	// defined default constructor
	student()
	{
		cout<<"called defined constructor"<<endl;
	}

	//parameterized constructor
	student(int age, string name)
	{
		this->age=age;
		this->name=name;
	}

	student(int age, string name, char gender, int roll)
	{
		this->age=age;
		this->name=name;
		this->gender=gender;
		this->roll=roll;
	}

	void display()
	{
		cout<<age<<" "<<name<<" "<<roll<<" "<<gender<<" "<<branch<<endl;
	}



};

int main()
{
	student s0(11,"mohan");
	s0.roll=123;
	s0.branch="CS";
	s0.gender='M';

	s0.display();
	//Naive approach
	student s1;
	s1.age=s0.age;
	s1.name=s0.name;
	s1.roll=s0.roll;
	s1.gender=s0.gender;
	s1.branch=s0.branch; //hectic work
	s1.display();


}