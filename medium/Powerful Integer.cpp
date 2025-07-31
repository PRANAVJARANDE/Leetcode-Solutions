class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        vector<pair<int,int>>v1;
        
        //0 - start
        //1 - end
        
        for(auto x:intervals)
        {
            v1.push_back({x[0],0});
            v1.push_back({x[1],1});
        }
        sort(v1.begin(),v1.end());
        
        int cnt=0;
        int ans=-1;
        for(auto x:v1)
        {
            if(cnt>=k)ans=max(ans,x.first);
            if(x.second==1)cnt--;
            else cnt++;
            if(cnt>=k)ans=max(ans,x.first);
        }
        return ans;
        
    }
};
