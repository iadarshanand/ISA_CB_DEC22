#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>>pq; //minHeap
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int inp;
		cin>>inp;
		pq.push(inp);
	}

	//print 
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;

}