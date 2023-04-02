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
    bool chkIteratively(TreeNode* leftChild, TreeNode* rightChild)
    {
        queue<TreeNode*>q1,q2;
        q1.push(leftChild);
        q2.push(rightChild);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* p1=q1.front();
            q1.pop();
            TreeNode* p2=q2.front();
            q2.pop();

            if(!p1 && !p2)continue;
            if(!p1 || !p2)return false;
            if(p1->val!=p2->val)return false;

            //child compare==>is mirror of each other or not
            q1.push(p1->left);
            q1.push(p1->right);

            q2.push(p2->right);
            q2.push(p2->left);

        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        bool chk=chkIteratively(root->left,root->right);
        return chk;
    }
};