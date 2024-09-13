class Solution {
public:
    int bestClosingTime(string s) 
    {
        int yr=0,nl=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Y')
            {
                yr++;
            }
        }
        int mpen=INT_MAX,ind=0;
        for(int i=0;i<n;i++)
        {
            int pen=yr+nl;
            if(mpen>pen)
            {
                mpen=pen;
                ind=i;
            }
            if(s[i]=='Y')
                yr--;
            else
                nl++;
        }
        if(mpen>nl)
        {
            ind=n;
        }
        return ind;
    }
};
