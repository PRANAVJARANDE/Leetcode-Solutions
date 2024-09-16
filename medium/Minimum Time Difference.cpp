class Solution {
public:
    int findMinDifference(vector<string>& a) 
    {
        int n=a.size();
        vector<int> v1(n,0);
        for(int i=0;i<n;i++)
        {
            int h=(a[i][0]-'0')*10+a[i][1]-'0';
            int m=(a[i][3]-'0')*10+a[i][4]-'0';
            v1[i]=h*60 + m;
        }
        sort(v1.begin(),v1.end());
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,abs(v1[i]-v1[i+1]));
        }
        int a1=v1[0]+24*60;
        ans=min(ans,abs(v1[n-1]-a1));
        return ans;
        
    }
};
