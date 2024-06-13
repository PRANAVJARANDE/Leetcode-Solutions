class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& st) {
        sort(s.begin(),s.end());
        sort(st.begin(),st.end());
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans+=abs(s[i]-st[i]);
        }
        return ans;
    }
};
