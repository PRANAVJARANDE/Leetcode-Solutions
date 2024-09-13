class Solution {
public:

    int n;
    int helper(int in,vector<string>&w,vector<int>&f,vector<int>&sc)
    {
        if(in>=n)
        {
            return 0;
        }
        //take
        bool b=0;
        vector<int> fin(26,0);
        for(char x: w[in])
        {
            fin[x-'a']++;
            if(fin[x-'a']>f[x-'a'])
            {
                b=1;
                break;
            }
        }
        int op1=0;
        if(b==1)
        {
            op1=0;
        }
        else 
        {
            for(char  x: w[in])
            {
                op1+=sc[x-'a'];
                f[x-'a']--;
            }
            op1+=helper(in+1,w,f,sc);
            for(char  x: w[in])
            {
                f[x-'a']++;
            }
        }
        int op2=helper(in+1,w,f,sc);
        return max(op1,op2);
    }

    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& sc) 
    {
        vector<int> f(26,0);
        for(char x: l)
        {
            f[x-'a']++;
        }
        n=w.size();
        return helper(0,w,f,sc);
    }
};
