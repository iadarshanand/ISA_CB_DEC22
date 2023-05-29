#include<bits/stdc++.h>
using namespace std;

int minCostBottomUp(vector<int>&a, int k)
{
	int n=a.size();
	vector<int>dp(n);
	//base case
	dp[0]=0;

	//dp[i] tells us min cost to reach at ith idx from 0th
	for(int i=1;i<n;i++)
	{
		int ans=INT_MAX;
		for(int j=1;j<=k;j++)
		{
			if(i-j<0)break;
			//otherwise
			ans=min(ans,dp[i-j]+abs(a[i]-a[i-j]));
		}
		dp[i]=ans;
	}
	return dp[n-1];
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>stones(n);
	for(int i=0;i<n;i++)cin>>stones[i];

	cout<<minCostBottomUp(stones,k)<<endl;
}