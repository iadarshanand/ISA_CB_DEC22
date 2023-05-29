class Solution {
public:
    int uniqueHelper(int i, int j, int n, int m, vector<vector<int>>&a, vector<vector<int>>&dp)
    {
        //Base Case
        if(i==n-1 && j==m-1)return 1;
        if(i==n || j==m)return 0;
        if(a[i][j]==1)return 0; //obstacle block

        //Memoized Case
        if(dp[i][j]!=-1)return dp[i][j];

        //Recursive Case
        //down step
        int op1=uniqueHelper(i+1,j,n,m,a,dp);
        //right step
        int op2=uniqueHelper(i,j+1,n,m,a,dp);

        return dp[i][j]=op1+op2;


    }

    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        //corner case
        if(a[0][0]==1 || a[n-1][m-1]==1)return 0;

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return uniqueHelper(0,0,n,m,a,dp);
        
    }
};