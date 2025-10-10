class Solution {
public:

    int cross(vector<int>&o,vector<int>&b,vector<int>&a)
    {
        int res=((a[0]-o[0])*(b[1]-o[1]))-((a[1]-o[1])*(b[0]-o[0]));
        return res;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& a) 
    {
        int n=a.size();
        if(n<=3)return a;
        sort(a.begin(),a.end());

        vector<vector<int>>v1;
        for(int i=0;i<n;i++)
        {
            while(v1.size()>=2 && cross(v1[v1.size()-2],v1[v1.size()-1],a[i])<0)v1.pop_back();
            v1.push_back({a[i][0],a[i][1]});
        }
        vector<vector<int>>v2;
        for(int i=n-1;i>=0;i--)
        {
            while(v2.size()>=2 && cross(v2[v2.size()-2],v2[v2.size()-1],a[i])<0)v2.pop_back();
            v2.push_back({a[i][0],a[i][1]});
        }
        map<vector<int>,int>m;
        for(auto x:v1)m[x]++;
        for(auto x:v2)m[x]++;
        vector<vector<int>>ans;
        for(auto x:m)ans.push_back(x.first);
        return ans;
    }
};
