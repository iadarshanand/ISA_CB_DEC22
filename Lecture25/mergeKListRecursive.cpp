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


    ListNode* mergeKListHelper(int j, vector<ListNode*>& a)
    {
        //Base Case
        if(j==0)return a[0];

        //some operation
        ListNode* l=mergeTwoSortedList(a[0],a[j]);
        a[0]=l;

        //Recursive Case
        return mergeKListHelper(j-1,a);
    }

    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n=a.size();
        if(n==0)return NULL;
        // for(int i=1;i<n;i++)
        // {
        //     a[0]=mergeTwoSortedList(a[0],a[i]);
        //     // a[i]=NULL; 
        // }
        return mergeKListHelper(n-1,a);
        
    }
};