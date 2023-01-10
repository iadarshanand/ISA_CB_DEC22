#include<bits/stdc++.h>
using namespace std;

int TrappedWater(vector<int>&a)
{
	int n=a.size();

	//left array
	vector<int>left(n);
	left[0]=0;
	for(int i=1;i<n;i++)
	{
		left[i]=max(left[i-1],a[i-1]);
	}

	//right array
	vector<int>right(n);
	right[n-1]=0;
	for(int j=n-2;j>=0;j--)
	{
		right[j]=max(right[j+1],a[j+1]);
	}

	int ans=0;
	for(int i=0;i<n;i++)
	{
		int leftMax=left[i]; //O(1)
		int rightMax=right[i]; //O(1)

		int heff=min(leftMax,rightMax)-a[i];
		if(heff>=0)ans+=heff;
		// ans+=(heff>=0?heff:0);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int ans=TrappedWater(a);
	cout<<ans<<endl;
}