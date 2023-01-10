#include<bits/stdc++.h>
using namespace std;

bool twoSumPair(int a[], int s, int e, int tar)
{
	int i=s,j=e;
	while(i<j)
	{
		if(a[i]+a[j]>tar)
		{
			j--;
		}
		else if(a[i]+a[j]<tar)
		{
			i++;
		}
		else
		{
			//i.e target acheived
			cout<<a[i]<<" "<<a[j]<<" ";
			return true;
		}
	}
	return false;
}

void threeSum(int a[], int n, int tar)
{
	for(int i=0;i<n;i++)
	{
		int oneElem=a[i];
		bool chk=twoSumPair(a,i+1,n-1,tar-oneElem);
		if(chk==true)
		{
			cout<<oneElem<<endl;
			return;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n]; //sorted array
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int target;
	cin>>target;

	threeSum(arr,n,target);
}