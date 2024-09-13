class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ans;
        vector<int> v1(n,0);
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1]+1)
            {
                v1[i]=1;
            }
        }
        vector<int> psum(n,0);
        for(int i=1;i<n;i++)
        {
            psum[i]=psum[i-1]+v1[i];
        }
        int j=0;
        for(int i=k-1;i<n;i++)
        {
            if(psum[i]==psum[i-k+1])
            {
                ans.push_back(a[i]);
            }
            else 
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
