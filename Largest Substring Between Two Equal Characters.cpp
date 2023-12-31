class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        vector<int> v1(26,-1);
        int ans=-1;
        for(int i=0;i<s.size();i++)
        {
            int eq=s[i]-'a';
            if(v1[eq]!=-1)
            {
                ans=max(ans,i-v1[eq]-1);
            }
            else
            {
                v1[eq]=i;
            }
        }
        return ans;
    }
};
