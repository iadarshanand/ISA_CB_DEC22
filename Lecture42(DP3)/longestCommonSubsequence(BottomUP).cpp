class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));

        //Base Case
        //j==m || i==n dp[i][j]=0
        //last col
        for(int i=0;i<=n;i++)dp[i][m]=0;
        //last row
        for(int j=0;j<=m;j++)dp[n][j]=0;

        //iterative case
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                //dp[i][j]==>lcs of s1(i to last) and s2(j to last)
                if(s1[i]==s2[j])dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];


        
    }
};