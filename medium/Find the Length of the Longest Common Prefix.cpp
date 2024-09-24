class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        map<string,int> m;
        for(int x: arr1)
        {
            string s=to_string(x);
            for(int i=0;i<s.size();i++)
            {
                m[s.substr(0,i+1)]++;
            }
        }
        for(auto x:arr2)
        {
            string s=to_string(x);
            for(int i=0;i<s.size();i++)
            {
                if(m[s.substr(0,i+1)])
                {
                    ans=max(ans,i+1);
                }
            }
        }
        return ans;
    }
};
