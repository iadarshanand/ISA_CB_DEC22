#include<bits/stdc++.h>
using namespace std;

class cmp{
public:
	bool operator()(int a, int b)
	{
		// return a>b; //minHeap
		return a<b;
	}
};

int main()
{
	priority_queue<int,vector<int>,cmp>pq;
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