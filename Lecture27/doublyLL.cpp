#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next, *prev;

	node(int data)
	{
		this->data=data;
		next=NULL;
		prev=NULL;
	}
};

void insertNodeAtTail(node* &head, node* &tail, int data)
{
	node* newNode= new node(data);
	if(!head)
	{
		head=newNode;
		tail=newNode;
		return;
	}
	tail->next=newNode;
	newNode->prev=tail;
	tail=tail->next;
}

void printList(node* head)
{
	node* p=head;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void printList1(node* tail)
{
	node* p=tail;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->prev;
	}
	cout<<endl;
}

int main()
{
	node *head=NULL, *tail=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int ip;
		cin>>ip;

		insertNodeAtTail(head,tail,ip);
	}

	printList(head); //print from head to tail
	printList1(tail); //print from tail to head
}