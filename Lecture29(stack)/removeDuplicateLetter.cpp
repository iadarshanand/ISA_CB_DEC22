class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();

        string ans="";
        vector<int>fre(26,0);
        for(int i=0;i<n;i++)
        {
            fre[s[i]-'a']++;
        }

        vector<bool>included(26,false);

        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(included[c-'a'])
            {
                fre[c-'a']--;
                continue;
            }
            //otherwise
            while(!ans.empty() && fre[ans.back()-'a']>0 && ans.back()>c)
            {
                included[ans.back()-'a']=false;
                ans.pop_back();
            }

            //push curr char in ans
            ans+=c;
            included[c-'a']=true;
            fre[c-'a']--;
        }
        return ans;

        
    }
};