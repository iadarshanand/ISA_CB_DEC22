class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        stack<int>st;
        vector<int>ans(n);
        //update stack
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=a[i%n])st.pop();
            if(st.empty())ans[i%n]=-1;
            else ans[i%n]=st.top();

            st.push(a[i%n]);
        }

        return ans;
        
    }
};