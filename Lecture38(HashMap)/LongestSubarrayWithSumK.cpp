#include <bits/stdc++.h>
using namespace std;
int longestSubArrwithSumK(vector<int>&a, int k)
{
    int n=a.size();
    //csum Array
    vector<int>csum(n);
    int sum=0;


    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        csum[i]=sum;
    }

    // for(int i=0;i<n;i++)cout<<csum[i]<<" ";
    // cout<<endl;    

    unordered_map<int,int>mp;//map<element,firstTimevisitingIdx>
    mp[0]=-1;//dryRun {1,2,3}, k=6
    int ans=0;
    for(int j=0;j<n;j++)
    {
        if(mp.count(csum[j]-k))//i.e csum[i] is founded, where csum[i]=cum[j]-k
        {
            int len=j-mp[csum[j]-k];
            ans=max(ans,len);
        }

        if(!mp.count(csum[j]))
        {
            mp[csum[j]]=j;
        }
    }
    return ans;


}
int main() 
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    cout<<longestSubArrwithSumK(a,k)<<endl;
}
