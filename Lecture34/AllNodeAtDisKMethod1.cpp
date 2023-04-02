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
    void distAtKinDescendent(TreeNode* root, int k, vector<int>&ans)
    {
        //Base Case
        if(!root)return;
        if(k<0)return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }

        //Recursive Case
        distAtKinDescendent(root->left,k-1,ans);
        distAtKinDescendent(root->right,k-1,ans);

    }


    int searchNode(TreeNode* root, TreeNode* tar, int k, vector<int>&ans)
    {
        //Base Case
        if(!root)return -1;
        if(root==tar)
        {
            distAtKinDescendent(root,k,ans);
            return 1;
        }

        //Recursive Case
        int left=searchNode(root->left,tar,k,ans);
        if(left!=-1)
        {
            if(left==k)
            {
                ans.push_back(root->val);
            }
            else
            {
                distAtKinDescendent(root->right,k-left-1,ans);
            }

            return left+1;
        }

        int right=searchNode(root->right,tar,k,ans);

        if(right!=-1)
        {
            if(right==k)ans.push_back(root->val);
            else distAtKinDescendent(root->left,k-right-1,ans);
            return right+1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
        vector<int>ans;
        searchNode(root,tar,k,ans);
        return ans;
        
    }
};