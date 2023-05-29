class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        //corner case
        if(a[n-1][m-1]==1 || a[0][0]==1)return 0;

        vector<vector<long long>>dp(n,vector<long long>(m));
        dp[n-1][m-1]=1;//no obstacle at dest
        //last col
        for(int i=n-2;i>=0;i--)
        {
            if(a[i][m-1]==1)dp[i][m-1]=0;
            else dp[i][m-1]=dp[i+1][m-1];
        }
        //last row
        for(int j=m-2;j>=0;j--)
        {
            if(a[n-1][j]==1)dp[n-1][j]=0;
            else dp[n-1][j]=dp[n-1][j+1];
        }

        //Iterative Case
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(a[i][j]==1)dp[i][j]=0;
                else dp[i][j]=dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];

        
    }
};