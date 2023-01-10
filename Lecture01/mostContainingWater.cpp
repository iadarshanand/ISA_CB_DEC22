#include<iostream>
using namespace std;

int maxContainerM1(int ht[], int n)
{
	int ans=0;// ans store max containing area 

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int currArea=min(ht[i],ht[j])*(j-i);
			ans=max(ans,currArea);

			//if(ans<currArea)ans=currArea
		}
	}
	//TC==O(n^2)
	//SC==O(1)
	return ans;
}

int maxContainerM2(int ht[], int n)
{
	int ans=0; //store max containing area
	int i=0,j=n-1;
	while(i<j)
	{
		int currArea=min(ht[i],ht[j])*(j-i);
		ans=max(ans,currArea);
		//shift block
		//shift smaller block is beneficial
		if(ht[i]<=ht[j])
		{
			i++;
		}
		else //ht[i]>ht[j]
		{
			j--;
		}
	}
	//TC==>O(n)
	//SC==>O(1)
	return ans;

}

int main()
{
	int n;
	cin>>n;
	int height[n];
	for(int i=0;i<n;i++)
	{
		cin>>height[i];
	}
	

	int maxContainingArea=maxContainerM1(height,n);
	cout<<maxContainingArea<<endl;

	//efficient way
	int maxContainingAreaByEff=maxContainerM2(height,n);
	cout<<maxContainingAreaByEff<<endl;


}