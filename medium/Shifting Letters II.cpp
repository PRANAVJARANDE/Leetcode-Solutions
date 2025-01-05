class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>psum(n+1,0);

        for(auto x:shifts)
        {
            int ta=1;
            if(x[2]==0)ta=-1;
            psum[x[0]]+=ta;
            psum[x[1]+1]-=ta;
        }
        for(int i=1;i<n;i++)psum[i]+=psum[i-1];

        for(int i=0;i<n;i++)
        {
            int y=(26+s[i]-'a'+psum[i])%26;
            if(y<0)y+=26;
            s[i]=y+'a';
        }
        return s;
    }
};
