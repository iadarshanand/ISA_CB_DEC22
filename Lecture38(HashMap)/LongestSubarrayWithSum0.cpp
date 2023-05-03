#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSum0(vector<int>&a)
{
    int n=a.size();
    //csumArray
    vector<int>csum(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        csum[i]=sum;
    }

    unordered_map<int,int>mp; // map<element, firstvistongIdx>
    mp[0]=-1;// manually as assumption
    //i.e csum[i]=0 ==> csum[i]=csum[-1]=0, i.e element from 0 to ith idx sum is 0
    // csum[j]==csum[i] where j>i, a[i+1]+....+a[j]=0
    //dry run {-1,2,-1}

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(!mp.count(csum[i]))
        {
            //first time element visited
            mp[csum[i]]=i;
        }
        else
        {
            //repeating element
            int tempLen=i-mp[csum[i]];
            ans=max(ans,tempLen);
        }
    }
    return ans;


}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int ans=largestSubarrayWithSum0(a);
    cout<<ans<<endl;

}
