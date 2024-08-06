class Solution {
public:
    int minimumPushes(string word) {
        vector<int>m(26,0);
        for(char x: word)
        {
            m[x-'a']++;
        }
        sort(m.begin(),m.end());
        int key=1;
        int ans=0;
        int in=0;
        for(int i=25;i>=0;i--)
        {
            if(m[i]==0)break;
            ans+=m[i]*key;
            in++;
            if(in==8)
            {
                key++;
                in=0;
            }
        }
        return ans;
    }
};
