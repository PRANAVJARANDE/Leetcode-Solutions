class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        map<char,int> m;
        for(char x: word)
        {
            m[x]++;
        }
        vector<int> v1;
        for(auto x: m)
        {
            v1.push_back(x.second);
        }
        sort(v1.begin(),v1.end());
        int n=v1.size();
        int ans=INT_MAX;
        int psum=0;
        for(int i=0;i<n;i++)
        {
            int cn=0;
            for(int j=i+1;j<n;j++)
            {
                int td=v1[j]-v1[i]-k;
                if(td>=0)
                {
                    cn+=td;
                }
            }
            ans=min(ans,cn+psum);
            psum+=v1[i];
        }
        return ans;
        
    }
};
