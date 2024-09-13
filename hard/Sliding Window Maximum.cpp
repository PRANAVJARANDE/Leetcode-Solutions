class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int m=INT_MIN;
        int m2=INT_MIN;
        int n=arr.size();
        multiset<int,greater<int>> s1;

        for(int i=0;i<k;i++)
        {
            s1.insert(arr[i]);
        }

        vector<int> ans;
        ans.push_back(*s1.begin());

        for(int i=k;i<n;i++)
        {
            s1.insert(arr[i]);
            s1.erase(s1.find(arr[i-k]));
            ans.push_back(*s1.begin());
        }
        return ans;
    }
};
