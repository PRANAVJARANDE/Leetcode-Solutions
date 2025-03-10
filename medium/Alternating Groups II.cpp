class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a, int k) 
    {
        int cnt=1;
        int ans=0;
        int n=a.size();
        for(int i=1;i<n+k-1;i++)
        {
            if(a[i%n]!=a[(i-1)%n])cnt++;
            else cnt=1;
            if(cnt>=k)ans++;
        }
        return ans;
    }
};
