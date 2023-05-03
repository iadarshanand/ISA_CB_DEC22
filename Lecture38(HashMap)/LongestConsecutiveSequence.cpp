class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();

        unordered_map<int,int>mp;//map<chainHead/Tail,length>
        for(int i=0;i<n;i++)
        {
            int node=a[i];
            //duplicate element founded then ignore
            if(mp.count(node))continue; 

            //Two chain merge
            if(mp.count(node+1) && mp.count(node-1))
            {
                int sz=mp[node+1]+1+mp[node-1];
                mp[node+mp[node+1]]=sz;
                mp[node-mp[node-1]]=sz;
                mp[node]=1;//tell that node is present in array. prevent from duplicacy in future
            }

            //Head Attachment
            else if(mp.count(node-1))
            {
                int sz=1+mp[node-1];
                mp[node]=sz;
                mp[node-sz+1]=sz;
            }

            //Tail Attachment
            else if(mp.count(node+1))
            {
                int sz=1+mp[node+1];
                mp[node]=sz;
                mp[node+sz-1]=sz; 
            }

            //No attachment
            else
            {
                mp[node]=1;
            }
        }

        int ans=0;
        for(auto x:mp)ans=max(ans,x.second);

        return ans;
   
    }
};