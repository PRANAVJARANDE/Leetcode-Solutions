class Solution {
public:
    string pushDominoes(string s) 
    {
        int n=s.size();
        string ans=s;
        vector<pair<char,int>>v1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.')
            {
                v1.push_back({s[i],i});
            }
        }
        if(v1.empty())return ans;
        if(!v1.empty() && v1[0].first=='L') 
            for(int i=0;i<v1[0].second;i++)ans[i]='L';
        
        if(!v1.empty() && v1.back().first=='R') 
            for(int i=v1.back().second+1;i<n; i++)ans[i]='R';
        
        for(int i=0;i<v1.size()-1;i++)
        {
            if(v1[i].first=='R' && v1[i+1].first=='L')
            {
                int rem=((v1[i+1].second)-(v1[i].second)-1)/2;
                int x=v1[i].second + 1;
                int y=v1[i+1].second - 1;
                while(rem--)
                {
                    ans[x++]='R';
                    ans[y--]='L';
                }
            }
            else if(v1[i].first=='R' && v1[i+1].first=='R')
            {
                for(int j=v1[i].second;j<=v1[i+1].second;j++)
                {
                    ans[j]='R';
                }
            }
            else if(v1[i].first=='L' && v1[i+1].first=='L')
            {
                for(int j=v1[i].second;j<=v1[i+1].second;j++)
                {
                    ans[j]='L';
                }
            }
        }
        return ans;
    }
};
