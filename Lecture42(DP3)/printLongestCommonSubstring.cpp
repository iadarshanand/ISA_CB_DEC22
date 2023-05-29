#include <bits/stdc++.h>
using namespace std;

string printLcs(string &s1, string &s2)
{
    int n=s1.size(), m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //Base case already fullfilled by dp matrix as 0
    //iterative Case
    int maxi=0;
    string ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //dp[i][j]=x i.e x cponsecutive char are same from s1[i-1 to ...] and s2[j-1 to ...]

            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>maxi)
                {
                    maxi=dp[i][j];
                    ans=s1.substr(i-maxi,maxi);
                }
            }
            else dp[i][j]=0;
        }
    }
    return ans;

}

int main() 
{
    string s1,s2;
    cin>>s1>>s2;

    cout<<printLcs(s1,s2)<<endl;
}
