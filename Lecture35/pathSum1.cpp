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
    bool hasPathSum(TreeNode* root, int tar) {
        //Base Case
        if(!root)return false;
        if(!root->left && !root->right)return tar==root->val;

        //Recursive Case
        return hasPathSum(root->left,tar-root->val) ||hasPathSum(root->right,tar-root->val);

        
    }
};