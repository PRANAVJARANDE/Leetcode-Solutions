class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) 
    {
        int ans=1;
        unordered_map<int,int> m;
        for(int x: arr)
        {
            m[x]=m[x-d]+1;
            ans=max(m[x],ans);
        }
        return ans;
    }
};
