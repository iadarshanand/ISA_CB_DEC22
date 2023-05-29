class Solution {
public:
    int uniquePathHelper(int i, int j, vector<vector<int>>&dp)
    {
        //Base case
        //first row or first col==>one unique ways to reach 0,0
        if(i==0 || j==0)return 1;

        //Memoized Case
        if(dp[i][j]!=-1)return dp[i][j]; //tells us tot unique path from i,j to 0,0

        //Recursive Case
        //left step
        int op1=uniquePathHelper(i,j-1,dp);
        //up step
        int op2=uniquePathHelper(i-1,j,dp);

        return dp[i][j]=op1+op2;
    }

    int uniquePaths(int n, int m) {
        //finish to start tot ways
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=uniquePathHelper(n-1,m-1,dp);
        return ans;
        
    }
};