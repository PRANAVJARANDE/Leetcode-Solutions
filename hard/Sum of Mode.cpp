class Solution {
  public:
    int sumOfModes(vector<int>& a, int k) 
    {
        int n=a.size();
        int ans=0;
        map<int,set<int>>m;
        map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            m[freq[a[i]]].erase(a[i]);
            if(m[freq[a[i]]].empty())m.erase(freq[a[i]]);
            
            freq[a[i]]++;
            m[freq[a[i]]].insert(a[i]);
            
            if(i-k>=0)
            {
                m[freq[a[i-k]]].erase(a[i-k]);
                if(m[freq[a[i-k]]].empty())m.erase(freq[a[i-k]]);
                freq[a[i-k]]--;
                m[freq[a[i-k]]].insert(a[i-k]);
            }
            
            // for(auto x:m)
            // {
            //     cout<<x.first<<" - ";
            //     for(auto z:x.second)cout<<z<<" ";
            //     cout<<endl;
            // }
            
            
            if(i>=k-1)
            {
                // auto temp=(*m.rbegin()).first;
                // cout<<temp<<endl;
                int res=*(((*m.rbegin()).second).begin());
                //cout<<i<<" "<<res<<endl;
                ans+=res;
            }
            //cout<<endl;
        }
        return ans;
    }
};
