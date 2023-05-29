class Solution {
public:
    int rob1(vector<int>& a) {
        int n=a.size();

        // vector<int>dp(n);
        //dp[i]=max(dp[i-1],a[i]+dp[i-2])
        int pre=0, curr=a[0];
        int temp;
        
        for(int i=1;i<n;i++)
        {
            temp=max(curr,a[i]+pre);
            pre=curr;
            curr=temp;
        }
        return temp;
    }

    int rob(vector<int>& a) {
       int n=a.size();
       //corner case
       if(n==1)return a[0];
       vector<int>v1(a.begin(),a.begin()+n-1);
       vector<int>v2(a.begin()+1,a.end());

       int op1=rob1(v1);
       int op2=rob1(v2);

       return max(op1,op2); 
        
    }
};