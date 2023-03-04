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
	student s0; //static creation
	s0.name="Adarsh";
	cout<<s0.name<<endl;

	// s0.age=21; //error bcz private property
	s0.setAge(21);
	// cout<<s0.age<<endl; error bcz private
	cout<<s0.getAge()<<endl;

	s0.setAddress("Bihar","abc");
	cout<<s0.getAddress("abc")<<endl;

	//dynamic creation
	student *s1=new student;
	// cout<<s1.name<<endl; //error s1 is not object, it is pointer
	cout<<(*s1).name<<endl; //garbage value
	(*s1).name="Anand";
	cout<<(*s1).name<<endl;
	cout<<s1->name<<endl;
}