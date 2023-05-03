class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();

        unordered_map<int,int>mp; //map<csum[i],freq>
        mp[0]=1;// subarray from start to jth index wich sum equals to k
        int sum=0;
        int ans=0;
        for(int j=0;j<n;j++)
        {
            sum+=a[j];
            //here at each jth idx, sum is value of their corresponding csum[j]
            ans+=mp[sum-k];// csum[i]=csum[j]-k

            mp[sum]+=1;
        }
        return ans;
        
    }
};