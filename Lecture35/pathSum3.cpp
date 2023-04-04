/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<long long,int>mp;
    int ans=0;
    long long csum=0;
    
    
    void f(TreeNode* root, int k)
    {
        // Base Case
        if(!root)return;
        
        //Recursive Case
        csum+=root->val;
        ans+=mp[csum-k];
        mp[csum]++;
        
        f(root->left,k);
        f(root->right,k);
        
        //Backtracking
        mp[csum]--;
        csum-=root->val;
                
    }
    int pathSum(TreeNode* root, int k) {
        mp[0]=1;
        f(root,k);
        return ans;
    }
};