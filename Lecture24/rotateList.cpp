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
    ListNode* rotateRight(ListNode* head, int k) {
        // if(k==0)return head;
        ListNode* start=head, *end=head;
        int n=0;
        ListNode*p=head;
        while(p)
        {
            n++;
            p=p->next;
        }
        // n will be size of LL
        //if LL is empty
        if(n==0)return head;
        // LL is not empty
        k=k%n;
        if(k==0)return head;
        //window of size k+1
        for(int i=0;i<k;i++)end=end->next;
        // cout<<start->val<<" "<<end->val<<endl;

        while(end && end->next)
        {
            start=start->next;
            end=end->next;
        }
        // cout<<start->val<<" "<<end->val<<endl;        
        ListNode* ansHead=start->next;
        end->next=head;
        start->next=NULL;
        return ansHead;
        
    }
};