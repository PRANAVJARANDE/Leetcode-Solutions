class Solution {
  public:
    int minDifference(vector<string> &a) {
        vector<int>tm;
        for(auto x:a)
        {
            int hr=stoi(x.substr(0,2))*3600;
            int mi=stoi(x.substr(3,2))*60;
            int sc=stoi(x.substr(6,2));
            tm.push_back(hr+mi+sc);
        }
        sort(tm.begin(),tm.end());
        int ans=24*3600 - tm.back() +tm[0];
        for(int i=1;i<tm.size();i++)
        {
            ans=min(ans,tm[i]-tm[i-1]);
        }
        return ans;
    }
};
