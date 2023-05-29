class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        //corner case
        if(n==1)return a[0];

        vector<int>dp(n,-1);
        //base case
        dp[n-1]=a[n-1];
        dp[n-2]=max(a[n-1],a[n-2]);
        //iterative case
        for(int j=n-3;j>=0;j--)
        {
            //rob current house
            int op1=a[j]+dp[j+2];
            //skip current house
            int op2=dp[j+1];

            dp[j]=max(op1,op2);
        }        
        return dp[0];
    }
};