class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();

        vector<int>dp(n,-1);
        //base case
        dp[n-1]=a[n-1];
        //iterative case
        for(int j=n-2;j>=0;j--)
        {
            //skip current house
            int op1=dp[j+1];
            //rob current house
            int op2=a[j];
            if(j+2<n)op2+=dp[j+2];

            dp[j]=max(op1,op2);
            
        }        
        return dp[0];
    }
};