#include <bits/stdc++.h>
using namespace std;

bool fun(vector<int>&a)
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

    // csum[j]==csum[i]; where j>i, a[i+1]+a[i+2]+...+a[j]=0
    unordered_map<int,bool>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.count(csum[i]))return true;
        //otherwise
        mp[csum[i]]=true;
    }
    return false;

}

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    bool chk=fun(a);
    if(chk)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
