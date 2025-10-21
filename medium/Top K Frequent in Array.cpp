class Solution {
  public:
    vector<int> topKFreq(vector<int> &a, int k) {
        map<int,int>m;
        for(auto x:a)m[x]++;
        vector<vector<int>>v1;
        for(auto x:m)v1.push_back({x.second,x.first});
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        vector<int>ans;
        for(int i=0;i<min((int)v1.size(),k);i++)ans.push_back(v1[i][1]);
        return ans;
    }
};
