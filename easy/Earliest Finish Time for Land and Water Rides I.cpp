class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) 
    {
        int n=ls.size(),m=ws.size();
        int minimum_end_land=INT_MAX;
        int minimum_end_water=INT_MAX;
        vector<vector<int>>v1(n,vector<int>(2,0));
        vector<vector<int>>v2(m,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=ls[i];
            v1[i][1]=ld[i];
            minimum_end_land=min(minimum_end_land,v1[i][0]+v1[i][1]);
        }
        for(int i=0;i<m;i++)
        {
            v2[i][0]=ws[i];
            v2[i][1]=wd[i];
            minimum_end_water=min(minimum_end_water,v2[i][0]+v2[i][1]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        int ans=INT_MAX;
        
        //land then water
        for(auto x:v2)
        {
            if(x[0]<=minimum_end_land)ans=min(ans,minimum_end_land+x[1]);
            else ans=min(ans,x[0]+x[1]);
        }
        cout<<ans<<endl;

        //water then land
        for(auto x:v1)
        {
            if(x[0]<=minimum_end_water)ans=min(ans,minimum_end_water+x[1]);
            else ans=min(ans,x[0]+x[1]);
        }

        return ans;
    }
};
