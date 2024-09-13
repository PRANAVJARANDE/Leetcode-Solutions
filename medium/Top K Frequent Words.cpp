class Solution {

    static bool cmp(pair<int,string> a,pair<int,string> b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second<b.second;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(string x: words)
        {
            m[x]++;
        }
        vector<pair<int,string>> v1;
        for(auto x: m)
        {
            v1.push_back({x.second,x.first});
        }
        sort(v1.begin(),v1.end(),cmp);
        vector<string> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(v1[i].second);
        }
        return res;
    }
};
