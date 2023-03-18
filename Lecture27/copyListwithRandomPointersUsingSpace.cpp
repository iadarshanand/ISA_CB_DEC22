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
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL)
            return head;
        unordered_map<Node*,Node*>mp;
        Node*p2=head;
        Node* p1=new Node(p2->val);
        Node* head1=p1;
        mp[p2]=p1;
        p2=p2->next;
        while(p2!=NULL)
        {
            p1->next=new Node(p2->val);
            p1=p1->next;
            mp[p2]=p1;
            p2=p2->next;
        }
        mp[NULL]=NULL;
        
        p2=head;
        p1=head1;
        while(p2!=NULL)
        {
            p1->random=mp[p2->random];
            p2=p2->next;
            p1=p1->next;
        }
        return head1;
        
    }
};