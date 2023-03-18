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


node* reverse(node* start, node* end)
{
    node* prev=NULL, *curr=start, *next=NULL;
    while(curr!=end)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* reverseInBetween(node* head, int i, int j)
{
    node* dummy=new node(-1);
    dummy->next=head;
    node* start=dummy, *end=dummy, *prev=NULL;
    for(int i1=0;i1<i;i1++)
    {
        if(i1==i-1)prev=start;
        start=start->next;
    }
    for(int j1=0;j1<j;j1++)end=end->next;
    end=end->next;

    prev->next=reverse(start,end);
    start->next=end;
    return dummy->next;


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
    int i,j;
    cin>>i>>j;
    head=reverseInBetween(head,i,j);
    printList(head);
    return 0;
}