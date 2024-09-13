class Solution {
public:
    int longestValidSubstring(string w, vector<string>& f) 
    {
            int n=w.size();
            int r=n;
            unordered_set<string> s1;
            int lmax=0,ans=0;
            for(string x: f)
            {
                s1.insert(x);
                lmax=max(lmax,(int)x.size());
            }
            for(int i=n-1;i>=0;i--)
            {
                string t;
                for(int j=i;j<r && j-i<lmax;j++)
                {
                    t.push_back(w[j]);
                    if(s1.count(t)==1)
                    {
                        r=j;
                        break;
                    }
                }
                ans=max(ans,r-i);
            }
            return ans;
        
    }
};
