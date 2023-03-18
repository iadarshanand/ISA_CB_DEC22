#include<bits/stdc++.h>
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

node* findMid(node* head)
{
    node* slow=head, *fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergeTwoSortedList(node* l1, node* l2)
{
    if(!l1)return l2;
    if(!l2)return l1;

    if(l1->data<=l2->data)
    {
        l1->next=mergeTwoSortedList(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next=mergeTwoSortedList(l1,l2->next);
        return l2;
    }
}

node* mergeSortLL(node* s, node* e)
{
    //Base Case
    if(s==e)return s;

    //Recursive Case
    node* midNode=findMid(s);
    node* midNext=midNode->next;
    midNode->next=NULL;

    node* l1=mergeSortLL(s,midNode);
    node* l2=mergeSortLL(midNext,e);

    //we have two sorted list==>l1,l2
    node* l=mergeTwoSortedList(l1,l2);
    return l;
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

int main()
{
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int ip;
        cin>>ip;
        insertToTail(head,ip);
    }

    node* tail=head;
    while(tail->next)tail=tail->next;

    head=mergeSortLL(head,tail);

    printList(head);
    return 0;

}