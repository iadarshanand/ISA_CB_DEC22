class Solution {
public:
    int robHelper(int idx, int n, vector<int>&a, vector<int>&dp)
    {
        //Base Case
        if(idx>=n)return 0;

        //Memoized case
        //dp[idx] tells us that max amount of money collected from this index to last index (keeping mind constraints)
        if(dp[idx]!=-1)return dp[idx];

        //Recursive Case
        //rob idxth house
        int op1=a[idx]+robHelper(idx+2,n,a,dp);
        //skip current house
        int op2=robHelper(idx+1,n,a,dp);

        return dp[idx]=max(op1,op2);
    }

    int rob(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n,-1);
        int ans=robHelper(0,n,a,dp);
        return ans;
        
    }
};