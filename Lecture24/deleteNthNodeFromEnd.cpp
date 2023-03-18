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

node* deleteNthNodeFromEnd(node* head, int k)
{
    if(k==0)return head;
    node* start=head, *end=head;
    for(int i=0;i<=k;i++)
    {
        if(!end)
        {
            if(i==k)return head->next;
            return head;
        }
        end=end->next;
    }
    while(end)
    {
        start=start->next;
        end=end->next;
    }
    start->next=start->next->next;
    return head;
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
    int k;
    cin>>k;
    head=deleteNthNodeFromEnd(head,k);
    printList(head);
}