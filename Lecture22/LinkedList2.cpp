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

void insertNodeATMiddle(Node* &head, int data)
{
	Node* newNode=new Node(data);
	//LL is empty
	if(!head)
	{
		head=newNode;
		return;
	}
	Node* midNode=findMidNode(head);
	newNode->next=midNode->next;
	midNode->next=newNode;
}

void deleteNodeAtMid(Node* &head)
{
	//LL is empty
	if(!head)
	{
		cout<<"Linked List is already empty"<<endl;
		return;
	}

	//find MidNode and prev Node
	Node *prev=NULL, *slow=head, *fast=head;

	while(fast->next && fast->next->next)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	//slow pointed to mid node of LL
	//prev pointed to NULL or prev of midNode

	//special case
	if(prev==NULL)
	{
		//size of LL is <=2
		head=head->next;
		return;
	}

	//otherwise
	prev->next=slow->next;
	slow->next=NULL;
}

Node* reverseLinkedListIterative(Node* head)
{
	Node *prev=NULL, *curr=head, *next=NULL;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

Node* reverseLinkedListRecursive1(Node* p)
{
	//Base Case
	if(p==NULL || p->next==NULL)return p;

	//Recursive Case
	Node* newHead=reverseLinkedListRecursive1(p->next);
	p->next->next=p;
	p->next=NULL;

	return newHead;

}

Node* reverseHelper(Node* prev, Node* curr)
{
	//Base Case
	if(!curr)return prev;

	//Recursive Case
	Node* next=curr->next;
	curr->next=prev;
	return reverseHelper(curr, next);
}

Node* reverseLinkedListRecursive2(Node* head)
{
	return reverseHelper(NULL,head);
}

Node* reverseHelper3(Node* prev, Node* curr)
{
	//Base Case
	if(!curr)return prev;

	//Recursive Case
	Node* newHead=reverseHelper3(curr,curr->next);
	//do operation
	curr->next=prev;
	return  newHead;
}

Node* reverseLinkedListRecursive3(Node* head)
{
	return reverseHelper3(NULL,head);
}

int main()
{
	Node* head=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int input;
		cin>>input;

		insertNodeAtTail(head,input);
	}

	insertNodeATMiddle(head,11);
	printLinkedList(head);
	insertNodeATMiddle(head,12);
	printLinkedList(head);	

	deleteNodeAtMid(head);
	printLinkedList(head);
	deleteNodeAtMid(head);
	printLinkedList(head);	

	head=reverseLinkedListIterative(head);
	printLinkedList(head);

	head=reverseLinkedListRecursive1(head);
	printLinkedList(head);

	head=reverseLinkedListRecursive2(head);
	printLinkedList(head);
	head=reverseLinkedListRecursive3(head);
	printLinkedList(head);


}