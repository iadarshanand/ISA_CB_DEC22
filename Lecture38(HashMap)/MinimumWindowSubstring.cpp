class Solution {
public:
    bool fit(map<char,int>&mps, map<char,int>&mpt)
    {
        for(auto x:mpt)
        {
            if(x.second>mps[x.first])return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        //freq of t
        map<char,int>mpt;
        for(auto x:t)mpt[x]++;

        //sliding window
        int n=s.size();
        int i=0,j=0;
        int ans=INT_MAX;
        map<char,int>mps;
        int startingIdx=0;
        while(j<n)
        {
            //expansion
            while(j<n && !fit(mps,mpt))
            {
                mps[s[j]]++;
                j++;
            }
            //contraction
            while(fit(mps,mpt))
            {
                if(ans>j-i)
                {
                    ans=j-i;
                    startingIdx=i;
                }
                
                mps[s[i]]--;
                i++;
            }
        }
        if(ans==INT_MAX)return "";
        //otherwise res exist
        string res=s.substr(startingIdx,ans);
        return res;


        
    }
};