class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int sz=q.size();
        vector<int>res(sz,0);

        map<int,int>col;
        map<int,int>m;

        for(int i=0;i<sz;i++)
        {
            if(col.find(q[i][0])!=col.end())
            {
                m[col[q[i][0]]]--;
                if(m[col[q[i][0]]]==0)
                {
                    m.erase(col[q[i][0]]);
                }
            }
            col[q[i][0]]=q[i][1];
            m[col[q[i][0]]]++;
            res[i]=m.size();
        }
        return res;
    }
};
