class Solution {
public:

    int cnt;
    bool helper(int in,char pc,string&res,int n,int k)
    {
        if(in>=n)
        {
            cnt++;
            if(cnt==k)
            {
                return 1;
            }
            return 0;
        }

        for(char c='a';c<='c';c++)
        {
            if(c==pc)continue;
            string pv=res;
            res+=c;
            if(helper(in+1,c,res,n,k))return 1;
            res=pv;
        }
        return 0;
    }


    string getHappyString(int n, int k) 
    {
        string res="";
        cnt=0;
        helper(0,'d',res,n,k);
        return res;
    }
};
