class Solution {
public:
    int maxScore(string s) 
    {
        int zcl=0,ocr=0;
        for(char x: s)
        {
            if(x=='1')ocr++;
        }
        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='0')
            {
                zcl++;
            }
            else
            {
                ocr--;
            }
            ans=max(ans,ocr+zcl);
        }
        return ans;
    }
};
