#include<bits/stdc++.h>
using namespace std;

void rev(int a[], int s, int e)
{
	int i=s, j=e;
	while(i<j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}

void rotateArrayByK(int a[], int n, int k)
{
	k%=n;// k=k%n
	rev(a,n-k,n-1);
	rev(a,0,n-k-1);
	rev(a,0,n-1);
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

	//efficient way
	rotateArrayByK(arr,n,k);
	//print
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}