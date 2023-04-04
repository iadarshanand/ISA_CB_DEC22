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
    void pathSumHelper(TreeNode* root, int tar, vector<int>&v, vector<vector<int>>&ans)
    {
        //Base Case
        if(!root)return;
        if(!root->left && !root->right)
        {
            if(root->val==tar)
            {
                v.push_back(root->val);
                ans.push_back(v);
                //Backtrack
                v.pop_back();
            }
            return;
        }

        //Recursive Case
        v.push_back(root->val);
        pathSumHelper(root->left,tar-root->val,v,ans);
        pathSumHelper(root->right,tar-root->val,v,ans);

        //Backtrack
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>>ans;
        vector<int>v; // v store root to curr Node at any state

        pathSumHelper(root,tar,v,ans);

        return ans;    
    }
};