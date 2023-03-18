class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            //a[i]==>currAsteroid
            //If currAsteroid is in +ve direction
            if(a[i]>=0)
            {
                st.push(a[i]);
                continue;
            }

            //otherwise currAsteroid is in -ve direction
            while(!st.empty() && st.top()>=0 && abs(a[i])>st.top())st.pop();
            if(!st.empty() && st.top()>=0)
            {
                if(abs(a[i])==st.top())st.pop();
                //curr Asteroid must explode in this case
                continue;
            }
            st.push(a[i]);
        }

        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};