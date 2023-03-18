/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        Node* curr=head;
        while(curr)
        {
            if(curr->child)
            {
                Node* temp=curr->next;
                curr->next=curr->child;
                curr->child->prev=curr;
                curr->child=NULL;

                Node* p=curr->next;
                while(p->next)p=p->next;
                p->next=temp;
                if(temp)temp->prev=p;
            }
            curr=curr->next;
        }
        return head;
        
    }
};