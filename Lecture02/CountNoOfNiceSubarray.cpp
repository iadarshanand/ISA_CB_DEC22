#include<bits/stdc++.h>
using namespace std;

    int AtmostValid(vector<int>&a, int k)
    {
        int n=a.size();
        int i=0,j=0;
        int cntOdd=0;
        int ans=0;

        while(j<n)
        {
            if(a[j]%2==1)cntOdd++;

            ///
            while(cntOdd>k)
            {
                cntOdd-=(a[i]%2);
                i++;
            }
            ans+=(j-i+1);
            j++;

        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& a, int k) {
        int n=a.size();
        int atmostK=AtmostValid(a,k);
        int atmostKminus1=AtmostValid(a,k-1);
        return atmostK-atmostKminus1;
        
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
	int k;
	cin>>k;

	cout<<numberOfSubarrays(a,k)<<endl;
	return 0;
}