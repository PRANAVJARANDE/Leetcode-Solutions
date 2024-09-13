class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n=score.size();
        vector<vector<int>> v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=score[i];
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        vector<string> ans(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)ans[v1[i][1]]="Gold Medal";
            else if(i==1)ans[v1[i][1]]="Silver Medal";
            else if(i==2)ans[v1[i][1]]="Bronze Medal";
            else ans[v1[i][1]]=to_string(i+1);
        }
        return ans;
        
    }
};
