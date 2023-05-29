class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();

        vector<int>dp(n);
        // dp[idx] tells max money collected from 0th index to idx index
        //base case
        dp[0]=a[0];
        //iterative case
        for(int i=1;i<n;i++)
        {
            //skip 
            int op1=dp[i-1];
            //rob
            int op2=a[i];
            if(i-2>=0)op2+=dp[i-2];

            dp[i]=max(op1,op2);
        }
        return dp[n-1];

        
    }
};