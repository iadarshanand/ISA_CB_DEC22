#include<bits/stdc++.h>
using namespace std;

int minJoiningCost(vector<int>&ropes)
{
	int n=ropes.size();
	priority_queue<int,vector<int>,greater<int>>pq; //minHeap

	for(int i=0;i<n;i++)pq.push(ropes[i]);

	//operations
	int cost=0;
	while(pq.size()>1)
	{
		int firstRope=pq.top();
		pq.pop();

		int secondRope=pq.top();
		pq.pop();

		cost+=(firstRope+secondRope);

		//Reff=Rfirst+Rsecond
		pq.push(firstRope+secondRope);
	}
	return cost;

}

int main()
{
	int n;
	cin>>n;

	vector<int>ropes(n);
	for(int i=0;i<n;i++)cin>>ropes[i];

	int ans=minJoiningCost(ropes);
	cout<<ans<<endl;
	return 0;
}