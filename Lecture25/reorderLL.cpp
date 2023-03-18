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
    ListNode* findMid(ListNode* head)
    {
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL, *curr=head, *next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid=findMid(head);
        // cout<<mid->val<<endl;
        ListNode* p2=reverse(mid->next);
        mid->next=NULL;
        ListNode* p1=head;
        while(p2)
        {
            ListNode* nh1=p1->next;
            ListNode* nh2=p2->next;

            p1->next=p2;
            p2->next=nh1;
            p1=nh1;
            p2=nh2;
        }  
    }
};