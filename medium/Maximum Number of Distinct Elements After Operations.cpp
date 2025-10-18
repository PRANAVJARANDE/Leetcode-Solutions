#define ll long long
class Solution {
public:
    int maxDistinctElements(vector<int>& a, int k) 
    {
        sort(a.begin(),a.end());
        ll n=a.size();
        int ans=0;
        int in=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=max(a[i]-k,in+1);
            if(l<=a[i]+k)
            {
                in=l;
                ans++;
            }
        }
        return ans;
    }
};
