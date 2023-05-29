class Solution {
public:
    int uniquePathHelper(int i, int j, int n, int m, vector<vector<int>>&dp)
    {
        //Base Case
        if(i==n-1 || j==m-1)return 1;

        //memoized case
        //dp[i][j]==>stores tot unique path from i,j to destination block if not -1
        if(dp[i][j]!=-1)return dp[i][j];

        //Recursive Case
        // f(i,j)=f(i+1,j)+f(i,j+1);
        //right steps
        int op1=uniquePathHelper(i,j+1,n,m,dp);
        //down steps
        int op2=uniquePathHelper(i+1,j,n,m,dp);

        return dp[i][j]=op1+op2;
    }

    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int ans=uniquePathHelper(0,0,n,m,dp);
        return ans;
        
    }
};