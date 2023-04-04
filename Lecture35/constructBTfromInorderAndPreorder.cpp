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
    int idx=0;

    TreeNode* buildHelper(int s, int e, vector<int>&pre, vector<int>&in)
    {
        //Base Case
        if(s>e)return NULL;

        //Recursive Case
        //find root node==>by help of preorder
        int val=pre[idx];
        idx++;

        //find index of root node in inorder
        int k=-1;
        for(int i=s;i<=e;i++)
        {
            if(in[i]==val)
            {
                k=i;
                break;
            }
        }

        TreeNode* root=new TreeNode(in[k]);
        //1st construct LST, bcz preorder manner is in root,left,right
        root->left=buildHelper(s,k-1,pre,in);
        root->right=buildHelper(k+1,e,pre,in);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        TreeNode* root=buildHelper(0,n-1,pre,in);
        return root;
    }
};