class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& a) 
    {
        set<int>s1;
        for(auto x:a)
        {
            s1.insert(x[0]);
            s1.insert(x[0]+x[1]);
        }
        map<int,int>m;
        int in=0;
        for(auto x:s1)m[x]=in++;

        vector<int>ans;
        vector<int>psum(in+3,0);
        for(auto x:a)
        {
            int res=0;
            int maxi=0;
            for(int i=m[x[0]];i<=m[x[0]+x[1]]-1;i++)maxi=max(maxi,psum[i]);
            for(int i=m[x[0]];i<=m[x[0]+x[1]]-1;i++)psum[i]=maxi+x[1]; 
            for(auto x:psum)res=max(res,x);
            ans.push_back(res);
        }
        return ans;
    }
};
