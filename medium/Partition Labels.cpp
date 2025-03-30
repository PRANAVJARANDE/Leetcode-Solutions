class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n=s.size();
        vector<int>mini(26,n),maxi(26,-1),psum(n,0);
        for(int i=0;i<n;i++)
        {
            mini[s[i]-'a']=min(mini[s[i]-'a'],i);
            maxi[s[i]-'a']=max(maxi[s[i]-'a'],i);
        }
        
        for(int i=0;i<26;i++)
        {
            if(maxi[i]!=-1)
            {
                psum[mini[i]]++;
                psum[maxi[i]]--;
            }
        }

        for(int i=1;i<n;i++)psum[i]+=psum[i-1];

        vector<int>res;
        int pv=-1;
        for(int i=0;i<n;i++)
        {
            if(psum[i]==0)
            {
                res.push_back(i-pv);
                pv=i;
            }
        }
        return res;
    }
};
