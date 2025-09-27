class Solution {
  public:
    vector<int> longestSubarray(vector<int>& a, int x) 
    {
        int n=a.size();
        int l=0;
        multiset<int>s1;
        int ans=0;
        int la=-1;
        int ra=-1;
        for(int i=0;i<n;i++)
        {
            s1.insert(a[i]);
            while(!s1.empty() && (*s1.rbegin())-(*s1.begin())>x)
            {
                s1.erase(s1.find(a[l]));
                l++;
            }
            if(ans<i-l+1)
            {
                ans=i-l+1;
                ra=i;
                la=l;
            }
        }
        vector<int>res;
        for(int i=la;i<=ra;i++)
        {
            res.push_back(a[i]);
        }
        return res;
        
    }
};
