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
    vector<int>ans;
    
    void KthDis(TreeNode* root, TreeNode* block, int k)
    {
        //Base Case
        if(!root)return;
        if(k<0)return;
        if(root==block)return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        
        //Recursive Case
        KthDis(root->left,block,k-1);
        KthDis(root->right,block,k-1);
    }
    
    int findSourceDist(TreeNode* root, TreeNode* target, int k)
    {
        //Base Case
        if(!root)return -1; //-1 means no target node in this subtree
        
        if(root==target)
        {
            KthDis(root,NULL,k);
            return 1; // i.e target node from its parent is at dist 1
        }
        
        //Recursive Case
        int left=findSourceDist(root->left,target,k);
        int right=findSourceDist(root->right,target,k);
        
        if(left!=-1)
        {
            KthDis(root,root->left,k-left);
            return left+1;
        }
        if(right!=-1)
        {
            KthDis(root,root->right,k-right);
            return right+1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        int chk=findSourceDist(root,target,k);
        return ans;
        
    }
};