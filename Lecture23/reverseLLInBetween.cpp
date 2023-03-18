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

    ListNode* reverse(ListNode* sn, ListNode* en)
    {
        ListNode* prev=NULL, *curr=sn, *next=NULL;
        ListNode* end=en->next;
        while(curr!=end)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* startNode, *endNode, *prev;

        int cnt=0;
        ListNode* p=dummy;
        while(cnt<=right)
        {
            if(cnt+1==left)prev=p;
            if(cnt==left)startNode=p;
            if(cnt==right)endNode=p;
            cnt++;
            
            p=p->next;
        }
        ListNode* end=endNode->next;

        ListNode* reversedHead=reverse(startNode,endNode);
        prev->next->next=end;
        prev->next=reversedHead;
        return dummy->next;  
    }
};