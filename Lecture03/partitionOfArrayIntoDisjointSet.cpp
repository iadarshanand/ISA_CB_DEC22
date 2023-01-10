#include<bits/stdc++.h>
using namespace std;

    int partitionDisjoint(vector<int>& a) {
        int n=a.size();

        //leftMax array
        // left[i]==>max elements till ith index
        vector<int>leftMax(n);
        leftMax[0]=a[0];
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],a[i]);
        }

        //rightMin array
        //right[i]==>min of elements from i+1 to end
        vector<int>rightMin(n);
        rightMin[n-1]=INT_MAX;
        for(int j=n-2;j>=0;j--)
        {
            rightMin[j]=min(rightMin[j+1],a[j+1]);
        }

        for(int i=0;i<n;i++)
        {
            if(leftMax[i]<=rightMin[i])return i+1;
        }

        return -1;
        
    }


int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int partitionedIdx=partitionDisjoint(a);
	cout<<partitionedIdx<<endl;
	return 0;
}