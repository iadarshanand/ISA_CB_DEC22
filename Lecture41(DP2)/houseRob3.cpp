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
    pair<int,int>robHelper(TreeNode* root)
    {
        //Base Case
        if(!root)return {0,0};

        //Recursive Case
        pair<int,int>left=robHelper(root->left); //pair<picked,notPicked>
        pair<int,int>right=robHelper(root->right);

        //operations
        //picked current node
        int op1=root->val + left.second + right.second;
        //Not Picked current Node
        int op2=max(left.first,left.second) + max(right.first,right.second);

        return {op1,op2};

    }

    int rob(TreeNode* root) {
        pair<int,int>ans=robHelper(root); //pair<Picked,NotPicked>

        return max(ans.first,ans.second);
        
    }
};