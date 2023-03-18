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
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2)
    {
        if(!l1)return l2;
        if(!l2)return l1;

        if(l1->val<=l2->val)
        {
            l1->next=mergeTwoSortedList(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoSortedList(l1,l2->next);
            return l2;
        }
    }

    ListNode* mergeKListsHelper(int i, int j, vector<ListNode*>& a)
    {
        //Base Case
        if(i==j)return a[i];

        //Recursive Case
        int mid=(i+j)/2;
        ListNode* l1=mergeKListsHelper(i,mid,a);
        ListNode* l2=mergeKListsHelper(mid+1,j,a);

        ListNode* l=mergeTwoSortedList(l1,l2);
        return l; 

    }


    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n=a.size();
        if(n==0)return NULL;

        return mergeKListsHelper(0,n-1,a);
        
    }
};