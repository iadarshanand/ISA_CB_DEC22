#include<bits/stdc++.h>
using namespace std;

double findMedian(priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap)
{
	int maxSz=maxHeap.size();
	int minSz=minHeap.size();

	//size equals
	if((maxSz+minSz)%2==0)
	{
		return (maxHeap.top()+minHeap.top())/2.0;
	}

	//otherwise heap with greater size contain median
	if(maxSz>minSz)
	{
		return maxHeap.top();
	}

	//minHeap size greater
	return minHeap.top();
}

void balance(priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap)
{
	int maxSz=maxHeap.size();
	int minSz=minHeap.size();

	if(abs(maxSz-minSz)<=1)
	{
		//i.e already balanced
		return;
	}	

	//we need to balance it
	if(maxSz-minSz>1)
	{
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
	else
	{
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}

}

void add(int num,priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap)
{

	int maxSz=maxHeap.size();
	int minSz=minHeap.size();
	//corner Case
	if(maxSz==0 && minSz==0)
	{
		maxHeap.push(num);
		//already balanced so no need to balance
		return;
	}

	//General Case
	double currMedian=findMedian(maxHeap,minHeap);
	if(num<=(int)currMedian)
	{
		//num will placed in left side
		maxHeap.push(num);
	}
	else
	{
		//num will placed to rightside
		minHeap.push(num);
	}

	balance(maxHeap,minHeap);


}

int main()
{

	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>>minHeap;
	int inp;
	while(cin>>inp)
	{
		add(inp,maxHeap,minHeap);
		cout<<findMedian(maxHeap,minHeap)<<" ";
	}
	return 0;
}