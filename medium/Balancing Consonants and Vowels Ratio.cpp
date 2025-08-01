class Solution {
  public:
    int countBalanced(vector<string>& a)
    {
        map<pair<int,int>,int>m;
        m[{0,0}]=1;
        int ans=0;
        int v=0,c=0;
        for(auto x:a)
        {
            for(auto ch:x)
            {
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')v++;
                else c++;
            }
            int mini=min(c,v);
            c-=mini;
            v-=mini;
            ans+=m[{c,v}];
            m[{c,v}]++;
        }
        return ans;
    }
};
