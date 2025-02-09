class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) 
    {
        int maxi=1e5 + 2;
        vector<int>m(maxi,INT_MAX);
        for(int i=0;i<e.size();i++)
        {
            m[e[i]]=min(m[e[i]],i);
        }
        int n=g.size();
        vector<int>res(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            int v=g[i];
            for(int j=1;j<=sqrt(v);j++)
            {
                if(v%j==0)
                {
                    int d1=j;
                    int d2=v/j;
                    res[i]=min(res[i],m[d1]);
                    res[i]=min(res[i],m[d2]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(res[i]==INT_MAX)res[i]=-1;
        }
        return res;
        
        
    }
};
