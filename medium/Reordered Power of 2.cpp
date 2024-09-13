class Solution {
public:

    bool helper(string s,int in)
    {
        int n=s.size();
        if(in==n-1)
        {
            if(s[0]!='0')
            {
                int t=stoi(s);
                if((t & (t-1) )==0)
                {
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        for(int i=in;i<n;i++)
        {
            swap(s[i],s[in]);
            bool b=helper(s,in+1);
            if(b==1)
            {
                return 1;
            }
            swap(s[i],s[in]);
        }
        return 0;
    }

    bool reorderedPowerOf2(int n) {
        return helper(to_string(n),0);
    }
};
