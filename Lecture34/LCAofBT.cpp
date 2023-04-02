/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base Case
        if(!root)return NULL;
        if(root->val==p->val || root->val==q->val)return root;

        //Recursive case
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left && right)
        {
            //current node is LCA
            // partition point
            return root;
        }

        if(left)return left;
        if(right)return right;

        return NULL;    
    }
};