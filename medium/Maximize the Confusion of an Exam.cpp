class Solution {
public:

    int sliding(string a,char ch,int k)
    {
        int zc=0,l=0,ans=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==ch)
            {
                zc++;
            }

            while(zc>k)
            {
                if(a[l]==ch)
                {
                    zc--;
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string a, int k) {
        return max(sliding(a,'T',k),sliding(a,'F',k));
    }
};
