#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int q;
	cin>>q;

	//create difference array initialized with 0
	int temp[n+1]={0};

	while(q--)
	{
		int i,j,d;
		cin>>i>>j>>d;

		temp[i]+=d;
		temp[j+1]-=d;
	}

	//update temp array to its prefix sum array
	int csum=0;
	for(int i=0;i<=n;i++)
	{
		csum+=temp[i];
		temp[i]=csum;
	}

	//update original array to resulting array
	for(int i=0;i<n;i++)
	{
		a[i]+=temp[i];
	}

	//print updated array
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}