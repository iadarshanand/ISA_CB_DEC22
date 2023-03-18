#include<bits/stdc++.h>
using namespace std;

vector<int>stockSpan(vector<int>&a)
{
    int n=a.size();
    stack<int>st; //stack<index>
    vector<int>span(n); //span[i]-->stock span of ith day

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]<=a[i])st.pop();
        //confirmed either stack is empty or st.top() is previousGreaterElement Day
        if(st.empty())span[i]=i+1;
        else span[i]=i-st.top();

        //push ith day/index in stack as hope of PGEday for next
        st.push(i);
    }
    return span;

}

int main()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<int>ans=stockSpan(a);
    for(auto x:ans)cout<<x<<" ";
    cout<<"END"<<endl;

    return 0;
}