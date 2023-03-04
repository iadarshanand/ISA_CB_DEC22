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
	student(int age1, string name1)
	{
		age=age1;
		name=name1;
		cout<<"paremeterized constructor"<<endl;
	}

	student(int age1, string name1, char gender1, int roll1)
	{
		age=age1;
		name=name1;
		gender=gender1;
		roll=roll1;
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
	student s0;
	student s1(22, "Adarsh"); //call parameterized constructor
	cout<<s1.name<<endl;
	cout<<s1.getAge()<<endl;

	student s2(21,"Adarsh",'M',123);
	cout<<s2.roll<<endl;
	// student s3(21,123,"Anand",'M'); //error

	student s4=student(10,"Ram");
	cout<<s4.name<<endl;
	student s5=student();
	student s6();

	//dynamic creation
	student *s7=new student(21,"Anand",'M',1234);
	cout<<s7->roll<<endl;
	student *s8=new student();
	student *s9=new student;
}