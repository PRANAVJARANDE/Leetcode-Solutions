class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        unordered_map<int,int> m;
        for(int x: arr)m[x]=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long ans=0;
        long long MOD=1e9+7;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int p=arr[i];
                int a1=arr[j];
                if(p%a1==0)
                {
                    int a2=p/a1;
                    m[p]=(m[p]% MOD )+ ((m[a1]%MOD)*(m[a2]%MOD))%MOD;
                }
            }
        }
        for(int x: arr)
        {
            ans=((ans%MOD)+(m[x]%MOD))%MOD;
        }
        return ans;
        
    }
};
