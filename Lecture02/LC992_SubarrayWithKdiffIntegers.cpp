///////Assignment

class Solution {
public:
    
    int f(vector<int>&a, int k)
    {
        int n=a.size();
        map<int,int>mp;
        int i=0,j=0;
        int cnt=0;
        while(j<n)
        {
            mp[a[j]]++;
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[a[i]]--;
                    if(mp[a[i]]==0)mp.erase(a[i]);
                    i++;
                }
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;

    }
    
    int subarraysWithKDistinct(vector<int>& a, int k) {
        //Hint number(exactly k)=number(atmost k)-number     (atmost (k-1)).
        
        int atmostK=f(a,k);
        int atmostKminus1=f(a,k-1);
        // cout<<atmostK<<" "<<atmostKminus1<<endl;
        return atmostK-atmostKminus1;
    }
};