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

bool isLoop1(node* head)
{
    //hashmap
    //track visited node
    map<node*,bool>mp;
    node* p=head;
    while(p)
    {
        //check is already curr node is visited or not
        if(mp.count(p))return true;
        //store this node as visited
        mp[p]=true;
        p=p->next;
    }
    return false;
}

bool loop1(node* head)
{
    //fast and slow approach
    node* slow=head, *fast=head;
    slow=slow->next;
    if(fast && fast->next)fast->next->next;
    else return false; // there is no loop

    while(fast && fast->next)
    {
        if(slow==fast)
        {
            //trajectory is circular
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    //translatory trajectory
    // ther is no loop 
    return false;
}