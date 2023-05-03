class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int>mp; //map<freq,charcter>
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;//maxHeap<freq,character>

        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }

        string ans="";
        while(pq.size()>=2)
        {
            //First
            char firstChar=pq.top().second;
            int firstCharFreq=pq.top().first;
            pq.pop();
            ans+=firstChar;
            firstCharFreq--;

            //Second
            char secondChar=pq.top().second;
            int secondCharFreq=pq.top().first;
            pq.pop();
            ans+=secondChar;
            secondCharFreq--;

            if(firstCharFreq>0)pq.push({firstCharFreq,firstChar});
            if(secondCharFreq>0)pq.push({secondCharFreq,secondChar});

        }

        //pq.size=0 or 1
        if(pq.size()==0)return ans;
        //pq.size()==1
        char lastChar=pq.top().second;
        int lastCharFreq=pq.top().first;

        if(lastCharFreq>1)
        {
            //Imposible bcz we have to append all remaining cnt of las char at last of ans string
            return "";
        }

        //i.e lastCharFreq==1
        ans+=lastChar;
        return ans; 
    }
};