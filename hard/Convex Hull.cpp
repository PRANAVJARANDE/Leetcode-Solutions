#define ll long long
class Solution {
  public:
  
    ll cross(vector<int>& o, vector<int>& b, vector<int>& a) 
    {
        return ((ll)b[0] - (ll)o[0]) * ((ll)a[1] - (ll)o[1]) - ((ll)b[1] - (ll)o[1]) * ((ll)a[0] - (ll)o[0]);
    }
  
    vector<vector<int>> findConvexHull(vector<vector<int>>&a)
    {
        ll n=a.size();
        sort(a.begin(),a.end());
        
        bool collinear = true;
        for(int i=2;i<n;i++)
        {
            if(cross(a[0], a[1], a[i]) != 0){
                collinear = false;
                break;
            }
        }
        if(collinear) return {{-1}};

        
        vector<int>v1;
        for(int i=0;i<n;i++)
        {
            while(v1.size()>=2 && cross(a[v1[v1.size()-2]],a[v1[v1.size()-1]],a[i])<=0)v1.pop_back();
            v1.push_back(i);
        }
        vector<int>v2;
        for(int i=n-1;i>=0;i--)
        {
            while(v2.size()>=2 && cross(a[v2[v2.size()-2]],a[v2[v2.size()-1]],a[i])<=0)v2.pop_back();
            v2.push_back(i);
        }
        map<int,int>m;
        for(auto x:v1)m[x]=1;
        for(auto x:v2)m[x]=1;
        vector<vector<int>>ans;
        for(auto x:m)ans.push_back(a[x.first]);
        return ans;
    }
};
