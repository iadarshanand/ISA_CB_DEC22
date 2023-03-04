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
		cout<<"called defined default constructor"<<endl;
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

	//inbuilt assignment operator

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

	//inbuilt destructor
	//defined destructor
	~student()
	{
		cout<<"defined destructor called"<<endl;
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

	student s1;
	s1.display();
	//s1 is already created
	// so you can't use copy constructor
	// use assignment operator
	s1=s0; 
	s1.display();

	student *s3=new student(s0);

	delete s3;
	// s3->~student();
	delete s3;
	cout<<"hi"<<endl;


	// s0.~student(); //destruct s0 by self
	// s1.~student();

}