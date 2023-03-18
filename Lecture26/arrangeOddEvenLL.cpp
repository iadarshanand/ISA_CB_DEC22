#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node()
    {
        this->next=NULL;
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

node* arrangeOddEven(node* head)
{
    node* dummyOdd=new node(-1);
    node* dummyEven=new node(-1);

    dummyOdd->next=head;
    dummyEven->next=head->next;
    node* p1=head, *p2=head->next;
    while(p1 && p2)
    {
        p1->next=p2 ? p2->next:NULL;
        p1=p1->next;
        p2->next=p1 ? p1->next:NULL;
        p2=p2->next;
    }
    node* p=dummyOdd;
    while(p->next)p=p->next;
    p->next=dummyEven->next;
    return dummyOdd->next;
    
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

int main() {
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int inp;
        cin>>inp;
        insertToTail(head,inp);
    }
    cout<<"Original List: ";
    printList(head);
    cout<<"Modified List: "; 
    head=arrangeOddEven(head);
    printList(head);
}