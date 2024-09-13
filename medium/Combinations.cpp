class Solution {
public:

    void helper(vector<vector<int>>&ans,vector<int>& v1,int n,int in,int k)
    {
        if(k==0)
        {
            ans.push_back(v1);
            return;
        }
        if(in>n)
        {
            return;
        }
        v1.push_back(in);
        helper(ans,v1,n,in+1,k-1);
        v1.pop_back();
        helper(ans,v1,n,in+1,k);
    }




    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v1;
        helper(ans,v1,n,1,k);
        return ans;
    }
};
