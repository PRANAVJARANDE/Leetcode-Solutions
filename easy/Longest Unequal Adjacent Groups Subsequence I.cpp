class Solution {
public:

    vector<string> helper(int pv,vector<string>& w, vector<int>& g)
    {
        int n=w.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            if(g[i]!=pv)
            {
                if(pv==0)pv=1;
                else pv=0;
                ans.push_back(w[i]);
            }
        }
        return ans;
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        auto ans1=helper(0,words,groups);
        auto ans2=helper(1,words,groups);
        if(ans1.size()>ans2.size())return ans1;
        return ans2;
    }
};
