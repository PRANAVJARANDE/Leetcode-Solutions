class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) 
    {
        int l=0;
        int r=arr.size()-1;
        vector<int> v1;
        while(l<r)
        {
            int s=arr[l]+arr[r];
            if(s==t)
            {
                
                v1.push_back(l+1);
                v1.push_back(r+1);
                return v1;
            }
            if(s<t)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return v1;
    }
};
