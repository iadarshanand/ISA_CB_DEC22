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
        ListNode *prev=NULL, *curr=start, *next=NULL;
        while(curr!=end)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy, *start=head, *end=head;
        while(end)
        {
            for(int i=0;i<k;i++)
            {
                if(!end)return dummy->next;
                end=end->next;
            }
            ListNode* reversedHead=reverse(start,end);
            prev->next=reversedHead;
            start->next=end;

            //reset prev, start,end for next iteration
            prev=start;
            start=end;
            end=end;

        }
        return dummy->next;

        
    }
};