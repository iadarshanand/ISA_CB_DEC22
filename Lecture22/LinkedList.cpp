#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	//constructor
	Node()
	{
		next=NULL;
	}

	Node(int data)
	{
		this->data=data;
		this->next=NULL;

	}
};

void insertNodeAtTail(Node* &head, int data)
{
	Node* newNode=new Node(data);

	//!head-->head==NULL
	//head-->head!=NULL
	if(!head)
	{
		head=newNode;
		return;
	}
	//Linked List is not empty
	// reach at last node
	Node* ptr=head;
	while(ptr->next)
	{
		ptr=ptr->next;
	}
	ptr->next=newNode;
	//O(N)
}

void printLinkedList(Node* const &head)
{
	if(!head)
	{
		cout<<"Linked List is empty"<<endl;
		return;
	}
	Node* ptr=head;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;

}

void deleteNodeATail(Node* &head)
{
	if(!head)
	{
		cout<<"Linked List is already empty"<<endl;
		return;
	}
	if(!head->next)
	{
		//LL is of size 1
		head=NULL;
		return;
	}

	Node* ptr=head;
	while(ptr->next->next)
	{
		ptr=ptr->next;
	}
	Node* p1=ptr->next;
	ptr->next=NULL;
	delete p1;

}

void insertNodeAtFront(Node* &head, int data)
{
	Node *newNode=new Node(data);

	if(!head)
	{
		head=newNode;
		return;
	}
	//otherwise
	newNode->next=head;
	head=newNode;
}

void deleteNodeAtFront(Node* &head)
{
	//LL is empty
	if(!head)
	{
		cout<<"Linked List is already empty"<<endl;
		return;
	}
	if(!head->next)
	{
		//size is 1
		head=NULL;
		return;
	}
	//otherwise
	Node*p=head;
	head=head->next;
	p->next=NULL;
	delete p;

}

int sizeOfLL(Node* &head)
{
	Node* p=head;
	int cnt=0;
	while(p)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

Node* findMidNode(Node* head)
{
	Node* slow=head, *fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
	//O(N/2)
}

int main()
{
	Node* head=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		printLinkedList(head);
		int input;
		cin>>input;

		insertNodeAtTail(head,input);
	}
	printLinkedList(head);
	printLinkedList(head->next);

	Node* midNode=findMidNode(head);
	cout<<"mid node element is "<<midNode->data<<endl;

	deleteNodeATail(head);
	printLinkedList(head);
	deleteNodeATail(head);
	printLinkedList(head);
	deleteNodeATail(head);
	printLinkedList(head);
	deleteNodeATail(head);
	printLinkedList(head);	
	deleteNodeATail(head);
	printLinkedList(head);	
	deleteNodeATail(head);

	insertNodeAtFront(head,11);
	printLinkedList(head);
	insertNodeAtFront(head,12);
	printLinkedList(head);

	deleteNodeAtFront(head);
	printLinkedList(head);
	deleteNodeAtFront(head);
	printLinkedList(head);
	deleteNodeAtFront(head);

}