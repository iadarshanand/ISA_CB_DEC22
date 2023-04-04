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
    int idx;

    TreeNode* buildHelper(int s, int e, vector<int>&in, vector<int>&post)
    {
        //Base Case
        if(s>e)return NULL;

        //Recursive Case
        //find root node
        int val=post[idx];
        idx--;

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
        //1st construct RST, bcz we traverse postorder in reverse way
        // so root,right,left in reverse way

        root->right=buildHelper(k+1,e,in,post);

        //2nd construct LST

        root->left=buildHelper(s,k-1,in,post);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        idx=n-1;

        TreeNode* root=buildHelper(0,n-1,in,post);
        return root;
        
    }
};