#include<bits/stdc++.h>
using namespace std;

int minCostHelper(int idx, int n, vector<int>&a, vector<int>&dp)
{
	//base Case
	if(idx==n-1)return 0;

	//Memoized Case
	if(dp[idx]!=-1)return dp[idx];

	//recursive Case
	//1 step jump
	int op1=abs(a[idx]-a[idx+1])+minCostHelper(idx+1,n,a,dp);
	int op2=INT_MAX;
	//2 step jump if possible
	if(idx+2<n)op2=abs(a[idx]-a[idx+2])+ minCostHelper(idx+2,n,a,dp);

	return dp[idx]=min(op1,op2);

}

int minCost(vector<int>a)
{
	int n=a.size();
	vector<int>dp(n,-1);
	return minCostHelper(0,n,a,dp);
}

int fun(int idx, vector<int>&a, vector<int>&dp)
{
	//base Case
	if(idx==0)return 0;

	//Memoized case
	if(dp[idx]!=-1)return dp[idx];

	//Recursive Case
	int op1=abs(a[idx]-a[idx-1])+fun(idx-1,a,dp);
	int op2=INT_MAX;
	if(idx-2>=0)op2=abs(a[idx]-a[idx-2])+fun(idx-2,a,dp);

	return dp[idx]=min(op1,op2);
}

int minCost2(vector<int>&stones)
{
	int n=stones.size();

	vector<int>dp(n,-1);
	return fun(n-1,stones,dp);
}

int minCostBottomUp(vector<int>&a)
{
	int n=a.size();
	vector<int>dp(n);
	//base case 
	dp[0]=0;
	//iterative case
	//dp[i]==> tells min cost to reach at ith idx stone from start
	for(int i=1;i<n;i++)
	{
		int op1=abs(a[i]-a[i-1])+dp[i-1];
		int op2=INT_MAX;
		if(i-2>=0)op2=abs(a[i]-a[i-2])+dp[i-2];

		dp[i]=min(op1,op2);
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin>>n;

	vector<int>stones(n);
	for(int i=0;i<n;i++)
	{
		cin>>stones[i];
	}

	cout<<minCost(stones)<<endl;
	cout<<minCost2(stones)<<endl;
	cout<<minCostBottomUp(stones)<<endl;
}