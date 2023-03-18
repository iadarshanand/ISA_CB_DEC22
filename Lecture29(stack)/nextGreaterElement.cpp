#include <bits/stdc++.h>
using namespace std;

vector<int>nextGreater(vector<int>&a)
{
    int n=a.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int currElem=a[i];
        while(!st.empty() && st.top()<=currElem)st.pop();
        //confirmed either stack empty or st.top>currElem
        if(st.empty())ans[i]=-1;
        else ans[i]=st.top();

        //push currElem in stack as hope in NGE for rest elements
        st.push(currElem);
    }
    return ans;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        vector<int>ans=nextGreater(a);

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<","<<ans[i]<<endl;
        }
    }
    return 0;
}
