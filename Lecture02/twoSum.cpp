#include<bits/stdc++.h>
using namespace std;

void TwoSumPair(int a[], int n, int target)
{
	//stl of sorting an array
	sort(a,a+n); //O(nlogn)

	//two pointer O(n)
	int i=0,j=n-1;
	while(i<j)
	{
		if(a[i]+a[j]>target)
		{
			j--;
		}
		else if(a[i]+a[j]<target)
		{
			i++;
		}
		else
		{
			cout<<a[i]<<" "<<a[j]<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int target;
	cin>>target;

	TwoSumPair(arr,n,target);

}