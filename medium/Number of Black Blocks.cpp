class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& a) {
        map<int,set<int>> mo;
        for(auto x: a)
        {
            mo[x[0]].insert(x[1]);
        }
        vector<long long> ans(5,0);
        //for 1 and 4
        for(auto x: a)
        {
            int i=x[0];
            int j=x[1];
            if(i<n-1 && j<m-1)
            {
                int cnt=mo[i+1].count(j)+mo[i+1].count(j+1)+mo[i].count(j+1);
                if(cnt==0)ans[1]++;
                if(cnt==3)ans[4]++;
                if(cnt==2)ans[3]++;
                if(cnt==1)ans[2]++;
            }
            if(i>0 && j<m-1)
            {
                int cnt=mo[i-1].count(j)+mo[i-1].count(j+1)+mo[i].count(j+1);
                if(cnt==0)ans[1]++;
                if(cnt==1)
                {
                    if(mo[i-1].count(j+1))
                    {
                        ans[2]++;
                    }
                }
            }
            if(i>0 && j>0)
            {
                int cnt=mo[i-1].count(j)+mo[i-1].count(j-1)+mo[i].count(j-1);
                if(cnt==0)ans[1]++;
                if(cnt==2)
                {
                    if(mo[i-1].count(j-1)==0)
                    {
                        ans[3]++;
                    }
                }
                if(cnt==1)
                {
                    if(mo[i-1].count(j-1)==0)
                    {
                        ans[2]++;
                    }
                }
            }
            if(i<n-1 && j>0)
            {
                int cnt=mo[i+1].count(j)+mo[i+1].count(j-1)+mo[i].count(j-1);
                if(cnt==0)ans[1]++;
            }
        }
        long long s=ans[1]+ans[2]+ans[3]+ans[4];
        ans[0]=(long long)(n-1)*(m-1)-s;
        return ans;

    }
};
