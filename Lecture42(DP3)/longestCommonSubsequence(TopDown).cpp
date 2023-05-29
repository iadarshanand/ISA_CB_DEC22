class Solution {
public:

    int lcsHelper(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>>&dp)
    {
        //Base Case
        if(i==n || j==m)return 0;

        //Memoized Case
        if(dp[i][j]!=-1)return dp[i][j];

        //Recursive Case
        if(s1[i]==s2[j])return dp[i][j]=1+lcsHelper(i+1,j+1,n,m,s1,s2,dp);
        else return dp[i][j]=max(lcsHelper(i+1,j,n,m,s1,s2,dp), lcsHelper(i,j+1,n,m,s1,s2,dp));

    }

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return lcsHelper(0,0,n,m,s1,s2,dp);
        
    }
};