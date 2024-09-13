class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n=pref.size();
        int prev=pref[0];
        for(int i=1;i<n;i++)
        {
            pref[i]^=prev;
            prev^=pref[i];
        }
        return pref;
    }
};
