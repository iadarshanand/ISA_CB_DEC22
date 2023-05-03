#include<bits/stdc++.h>
using namespace std;

void topKM1(vector<int>&a, int k)
{
	int n=a.size();
	priority_queue<int>maxHeap;
	for(int i=0;i<n;i++)
	{
		maxHeap.push(a[i]);
	}

	for(int i=0;i<k;i++)
	{
		cout<<maxHeap.top()<<" ";
		maxHeap.pop();
	}
	cout<<endl;
	// T.C. O(NlogN)
	// S.C. O(N)

}

void topkM2(vector<int>&a, int k)
{
	int n=a.size();
	priority_queue<int,vector<int>,greater<int>>minHeap;

	for(int i=0;i<n;i++)
	{
		int currVal=a[i];

		if(minHeap.size()==k)
		{
			if(currVal>minHeap.top())
			{
				minHeap.pop();
				minHeap.push(currVal);
			}
		}
		else
		{
			// case when size<k
			minHeap.push(currVal);
		}
	}

	vector<int>ans;
	while(!minHeap.empty())
	{
		ans.push_back(minHeap.top());
		minHeap.pop();
	}

	reverse(ans.begin(),ans.end());
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;

//T.C. O(NlogK)
//S.C. O(k)
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	//Method1 (sort and get)

	//Method 2(Using MaxHeap)
	topKM1(a,k);

	//Method 3(Using MinHeap)
	topkM2(a,k);
	return 0;

}