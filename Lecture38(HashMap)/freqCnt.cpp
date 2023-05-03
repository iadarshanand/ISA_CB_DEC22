#include<bits/stdc++.h>
using namespace std;
void freqCount(vector<int>&a)
{
	int n=a.size();
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[a[i]]++;
	}
	//Print
	for(auto x:mp)
	{
		cout<<x.first<<"-->"<<x.second<<endl;
	}
}

int main()
{
	int n;
	cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	freqCount(a);
}