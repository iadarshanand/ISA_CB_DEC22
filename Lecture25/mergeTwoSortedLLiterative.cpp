/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;

        ListNode* dummy=new ListNode(-1); // by the help of this we start merging our lists

        ListNode* prev=dummy; //prev always points to tail of our resultant merged list
        ListNode *p1=l1, *p2=l2;

        while(p1 && p2)
        {
            if(p1->val<=p2->val)
            {
                prev->next=p1;
                p1=p1->next;
                prev=prev->next;
            }
            else
            {
                prev->next=p2;
                p2=p2->next;
                prev=prev->next;
            }
        }
        if(p1)prev->next=p1;
        if(p2)prev->next=p2;

        return dummy->next;

        
    }
};