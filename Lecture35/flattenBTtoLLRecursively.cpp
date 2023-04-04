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
    TreeNode* flattenHelper(TreeNode* root)
    {
        //Base Case
        if(!root)return NULL;

        //Recursive Case
        TreeNode* left=flattenHelper(root->left);
        TreeNode* right=flattenHelper(root->right);

        //operation
        if(!left)return root;
        //LST exist
        //find last element of flattened LST
        TreeNode* p=left;
        while(p->right)p=p->right;
        //p pointed to last node of flattened LST
        p->right=right;
        root->right=left;
        root->left=NULL;

        return root;

    }

    void flatten(TreeNode* root) {
        flattenHelper(root);
        return;
        
    }
};