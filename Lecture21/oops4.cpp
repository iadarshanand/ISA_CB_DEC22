#include<iostream>
using namespace std;

class student
{
private:
	string contactNo;
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

	//inbuilt copy constructor
	//defined copy constructor
	student(student const &obj)
	{
		cout<<"execute copy constructor"<<endl;
		this->age=obj.age;
		this->name=obj.name;
		this->roll=obj.roll;
		this->gender=obj.gender;
		this->branch=obj.branch;
		this->contactNo=obj.contactNo; //private member copied too
	}

	void setContact(string data)
	{
		contactNo=data;
	}
	string getContact()
	{
		return contactNo;
	}

	void display()
	{
		cout<<age<<" "<<name<<" "<<roll<<" "<<gender<<" "<<branch<<" "<<contactNo<<endl;
	}

};

int main()
{
	student s0(11,"mohan");
	s0.roll=123;
	s0.branch="CS";
	s0.gender='M';
	s0.setContact("9999");

	s0.display();
	//Naive approach
	student s1;
	s1.age=s0.age;
	s1.name=s0.name;
	s1.roll=s0.roll;
	s1.gender=s0.gender;
	s1.setContact(s0.getContact());
	s1.branch=s0.branch; //hectic work
	s1.display();
	s1.name="Adarsh";

	// copy constructor
	student s2(s1);
	s2.display();
	// student s3=s1;
	// s3.display();

	// student *s4=new student(s0);
	// s4->display();
	// s4->name="Ram";

	// student *s5=new student(*s4);
	// s5->display();

}