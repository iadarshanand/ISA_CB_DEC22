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
    ListNode* reverse(ListNode* start, ListNode* end)
    {
        ListNode* prev=NULL, *curr=start, *next=NULL;
        while(curr!=end)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* reverseHelper(ListNode* head, int k)
    {
        //Recursive Case
        ListNode* start=head, *end=head;
        for(int i=0;i<k;i++)
        {
            if(!end)return head;
            end=end->next;
        }
        ListNode* reversedHead=reverse(start,end);
        start->next=reverseHelper(end,k);
        return reversedHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseHelper(head,k);

    }
};