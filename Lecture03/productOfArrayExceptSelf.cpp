#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>&a)
{
	int n=a.size();

	//left array
	//left[i]==>product of leftside elements
	vector<int>left(n);
	left[0]=1;
	for(int i=1;i<n;i++)
	{
		left[i]=left[i-1]*a[i-1];
	}
	//debug
	// print left array
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<left[i]<<" ";
	// }
	// cout<<endl;

	//right array
	//right[i]==>product of rightside elements

	vector<int>right(n);
	right[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		right[i]=right[i+1]*a[i+1];
	}

	//print right array
	// for(int i=0;i<n;i++)cout<<right[i]<<" ";
	// cout<<endl;

	//ans array
	//ans[i]=left[i]*right[i]==>product of array except self
	vector<int>ans(n);
	for(int i=0;i<n;i++)
	{
		ans[i]=left[i]*right[i];
	}
	return ans;

}

vector<int>productExceptSelf1(vector<int>&a)
{
	int n=a.size();
	int cnt0=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)cnt0++;
	}
	if(cnt0>1)
	{
		vector<int>ans(n,0);
		return ans;
	}
	if(cnt0==1)
	{
		vector<int>ans(n,0);
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				//right product
				int right=1;
				for(int j=i+1;j<n;j++)right*=a[j];

				//left product
				int left=1;
				for(int j=i-1;j>=0;j--)left*=a[j];

				ans[i]=left*right;
			}
		}
		return ans;
	}
	//cnt0==0
	int prodOfAll=1;
	for(int i=0;i<n;i++)prodOfAll*=a[i];

	vector<int>ans(n);
	for(int i=0;i<n;i++)
	{
		ans[i]=prodOfAll/a[i]; //we confirmed that a[i] will never be 0 in this case
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

	vector<int>res=productExceptSelf(a);
	vector<int>res1=productExceptSelf1(a);
	//print res array
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;

	//print res1
	for(int i=0;i<n;i++)
	{
		cout<<res1[i]<<" ";
	}
	cout<<endl;
	return 0;
}