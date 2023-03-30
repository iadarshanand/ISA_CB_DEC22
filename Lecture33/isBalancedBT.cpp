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
    pair<bool,int>isBalancedHelper(TreeNode* root)
    {
        //Base Case
        if(!root)return {true,0};

        //Recursive Case
        pair<bool,int>l=isBalancedHelper(root->left);
        pair<bool,int>r=isBalancedHelper(root->right);

        //conclusion
        bool isBalLeft=l.first, isBalRight=r.first;
        int LH=l.second, RH=r.second;
        int currHt=1+max(LH,RH);
        bool isCurBal=isBalLeft && isBalRight && abs(LH-RH)<=1;

        return {isCurBal,currHt};


    }

    bool isBalanced(TreeNode* root) {
        pair<bool,int>ans=isBalancedHelper(root); //pair<isBalanced,height>
        return ans.first;
    }
};