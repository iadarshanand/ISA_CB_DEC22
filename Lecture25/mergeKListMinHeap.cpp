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
 #define pil pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n=a.size();
        if(n==0)return NULL;

        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        priority_queue<pil,vector<pil>,greater<pil>>minHeap; //minHeap<int,ListNode*>
        for(int i=0;i<n;i++)
        {
            if(a[i])minHeap.push({a[i]->val,a[i]});
        }

        while(!minHeap.empty())
        {
            pil minNode=minHeap.top();
            minHeap.pop();
            int val=minNode.first;
            ListNode* temp=minNode.second;

            tail->next=temp;
            if(temp->next)minHeap.push({temp->next->val,temp->next});
            tail=tail->next;
        }
        return dummy->next;
        
    }
};