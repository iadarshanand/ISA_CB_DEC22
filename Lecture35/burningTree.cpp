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

    int height(TreeNode* root)
    {
        //Base Case 
        if(!root)
        {
           return 0; 
        } 

        //Recursive Case
        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left,right);

    }
    
    int searchTime(TreeNode* root, int start, int &ans)
    {
        //Base Case
        if(!root)return -1;
        if(root->val==start)
        {
            ans=max(ans,height(root)-1);
            return 1;
        }

        //Recursive Case
        int left=searchTime(root->left,start,ans);
        if(left!=-1)
        {
            //fire came from left side
            if(!root->right)ans=max(ans,left);
            else
            {
                int restTime=left+height(root->right);
                ans=max(ans,restTime);
            }
            return left+1;
        }

        int right=searchTime(root->right,start,ans);
        if(right!=-1)
        {
            //fire came from right side
            if(!root->left)ans=max(ans,right);
            else
            {
                int restTime=right+height(root->left);
                ans=max(ans,restTime);
            }
            return right+1;
        }
        
        //fire didn't came from descendent
        return -1;
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        searchTime(root,start,ans);
        return ans;
        
    }
};