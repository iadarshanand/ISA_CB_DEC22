#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    //constructor
    node()
    {
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insertToTail(node* &head, int val)
{
    node* newNode=new node(val);
    if(!head)
    {
        head=newNode;
        return;
    }
    node* p=head;
    while(p->next)p=p->next;
    //p point to tail node
    p->next=newNode;
}

void printLL(node* head)
{
	node* p=head;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

node* findMid(node* head)
{
	node* slow=head, *fast=head;
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

node* reverse(node* head)
{
	node* prev=NULL, *curr=head, *next=NULL;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;

}

bool isPalindrome(node* head)
{
	//find mid node
	node* midNode=findMid(head);
	//reverse 2nd half part
	midNode->next=reverse(midNode->next);
	//check first half and 2nd reverse half
	node* p1=head, *p2=midNode->next;
	while(p2!=NULL)
	{
		if(p1->data!=p2->data)return false;
		p1=p1->next;
		p2=p2->next;
	}
	return true;

}

int main()
{
	node* head=NULL;
	//Taking unknown number of inputs from user
	int input;
	while(cin>>input)
	{
		insertToTail(head,input);
	}
	// printLL(head);

	bool chk=isPalindrome(head);
	if(chk)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	

}

