#include<iostream>
using namespace std;

class student
{
private:
	int age;
	string address;
public:
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
	// student(int age, string name)
	// {
	// 	student::age=age;
	// 	student::name=name;
	// 	cout<<"paremeterized constructor"<<endl;
	// }

	//this keyword
	student(int age, string name)
	{
		this->age=age;
		this->name=name;
	}



	//fn
	void setAge(int data)
	{
		age=data;
	}
	void setAddress(string data, string password)
	{
		if(password!="abc")
		{
			cout<<"you are not authorised"<<endl;
			return;
		}
		address=data;
	}
	int getAge()
	{
		return age;
	}
	string getAddress(string password)
	{
		if(password!="abc")
		{
			return "Not Authorised";
		}		
		return address;
	}
};

int main()
{
	student s1(21,"Adarsh");
	cout<<s1.name<<endl;

}