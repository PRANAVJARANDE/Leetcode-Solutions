class Solution {
public:

    void helper(int in,int t,int k,vector<int>&v1,vector<vector<int>>&ans)
    {
        if(t==0 && v1.size()==k)
        {
            ans.push_back(v1);
            return;
        }
        if(t<0)
        {
            return ;
        }
        if(v1.size()>k)
        {
            return;
        }
        if(in>9)
        {
            return;
        }
        v1.push_back(in);
        helper(in+1,t-in,k,v1,ans);
        v1.pop_back();
        helper(in+1,t,k,v1,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v1;
        helper(1,n,k,v1,ans);
        return ans;
    }
};
