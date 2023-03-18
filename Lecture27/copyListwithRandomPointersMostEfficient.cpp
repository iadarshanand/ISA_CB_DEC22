/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
     //step 1--> add in between clone node
    Node* curr=head;
    while(curr)
    {
        Node* temp=curr->next;
        curr->next=new Node(curr->val); // linked to corresponig clone node
        curr->next->next=temp;

        curr=curr->next->next;
    }

    //step 2--> copy random pointer to cloned node
    //Each orgNode->next is pointing to their clone node
    curr=head;
    while(curr)
    {
        if(curr->random!=NULL)curr->next->random=curr->random->next;
        curr=curr->next->next;
    }

    //step 3-->disjoint original and clone
    Node* cloneHead=head->next;

    curr=head;
    while(curr->next!=NULL)
    {
        Node* temp=curr->next;
        curr->next=curr->next->next;
        curr=temp;
    }
    return cloneHead;        
    }
};