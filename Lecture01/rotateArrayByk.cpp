#include<bits/stdc++.h>
using namespace std;

void rotateArrayBy1(int *a, int n)
{
	int temp=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	a[0]=temp;
}

void RotateArrayByK(int *a, int n, int k)
{
	k=k%n;

	for(int i=0;i<k;i++)
	{
		rotateArrayBy1(a,n);
	}
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

	int k;
	cin>>k;

	//rotate array by k
	RotateArrayByK(arr,n,k);

	//print array
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}