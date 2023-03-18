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
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
    cout<<"hi"<<endl;
}

int main()
{
    cout<<"hello"<<endl;
    // int n,m;
    // cin>>n>>m;
    // node* head1=NULL, *head2=NULL;
    // for(int i=0;i<n;i++)
    // {
    //     int inp;
    //     cin>>inp;
    //     cout<<"1"<<endl;
    //     insertToTail(head1,inp);
    //     cout<<"hello"<<endl;
    // }

    // //creating 2nd LL
    // for(int i=0;i<m;i++)
    // {
    //     int inp;
    //     cin>>inp;
    //     insertToTail(head2,inp);
    // }

    // printLL(head1);
    // printLL(head2);
}