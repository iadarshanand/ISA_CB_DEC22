class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m));
        //base Case
        //last col and last row==> only one unique path
        //last col
        for(int i=0;i<n;i++)dp[i][m-1]=1;
        //last row
        for(int j=0;j<m;j++)dp[n-1][j]=1;

        //iterartive case
        // dp[i][j]=dp[i+1][j] + dp[i][j+1];
        //dp[i][j] tells us tot unique path drom i,j to destination

        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j] + dp[i][j+1];
            }
        }

        return dp[0][0];

        
    }
};