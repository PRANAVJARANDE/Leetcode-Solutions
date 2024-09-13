class Solution {
public:

    bool helper(int k,vector<vector<int>> v1,vector<char> &mark)
    {
        char ch;
        if(mark[k]=='r')
        {
            ch='b';
        }
        else if(mark[k]=='b')
        {
            ch='r';
        }

        vector<int> ts=v1[k];
        for(int i=0;i<ts.size();i++)
        {

            if(mark[ts[i]]!=ch)
            {
                if(mark[ts[i]]!='0')
                {
                    return 0;
                }
                mark[ts[i]]=ch;
            
            bool b=helper(ts[i],v1,mark);
            if(b==0)
            {
                return 0;
            }
            }
        }
        return 1;
    }


    bool isBipartite(vector<vector<int>>& v1) 
    {
        int n=v1.size();
        vector<char> mark(n,'0');

        for(int i=0;i<n;i++)
        {
            if(mark[i]=='0')
            {
                mark[i]='r';
                if(helper(i,v1,mark)==0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
