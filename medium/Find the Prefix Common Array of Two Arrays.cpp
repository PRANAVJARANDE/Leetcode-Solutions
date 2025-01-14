class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int>ans(n,0);
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
            if(m[a[i]]==2)ans[i]++;
            m[b[i]]++;
            if(m[b[i]]==2)ans[i]++;
            if(i-1>=0)ans[i]+=ans[i-1];
        }
        return ans;
    }
};
