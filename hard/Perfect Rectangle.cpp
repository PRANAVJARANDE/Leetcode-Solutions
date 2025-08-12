class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& a) 
    {
        map<pair<int,int>,int>m;
        for(auto x:a)
        {
            m[{x[0],x[1]}]++;
            m[{x[2],x[3]}]++;
            m[{x[0],x[3]}]--;
            m[{x[2],x[1]}]--;
        }

        int cnt=0;
        for(auto x: m)
        {
            if(x.second==0)continue;
            if(abs(x.second)!=1)return 0;
            cnt++;
        }
        return cnt==4;


    }
};
