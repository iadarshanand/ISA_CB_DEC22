class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();

        int i=0,j=1;
        // i==>assured us that till ith index all elements are distinct
        //array "a" is non decreasing array
        //distinct elements till ith index is in increasing way

        while(j<n)
        {
            if(a[j]>a[i])
            {
                //we found a new distinct element
                i++;
                a[i]=a[j];
            }
            j++;
        }

        return i+1;
        
    }
};