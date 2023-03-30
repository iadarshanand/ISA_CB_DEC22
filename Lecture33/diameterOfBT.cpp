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
    pair<int,int>diamHelper(TreeNode* root)
    {
        //Base Case
        if(!root)return {0,0}; //{D,H}

        //Recursive Case
        pair<int,int>left=diamHelper(root->left);
        pair<int,int>right=diamHelper(root->right);

        //conclusion
        int dl=left.first;
        int dr=right.first;
        int LH=left.second;
        int RH=right.second;

        int dc=LH+RH; //longest path passing from currNode passing

        int D=max({dc,dl,dr});
        int H=1+max(LH,RH);

        return {D,H}; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>ans=diamHelper(root); //pair<diameter,ht>
        return ans.first;
    }
};