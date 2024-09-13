class Solution {
public:
    string mergeAlternately(string a, string b) 
    {
        string ans="";
        int p1=0,p2=0;
        int l1=a.size();
        int l2=b.size();

        while(p1<l1 && p2<l2)
        {
            ans=ans+a[p1];
            ans=ans+b[p2];
            p1++;
            p2++;
        }

        while(p1<l1)
        {
            ans=ans+a[p1];
            p1++;
        }
        while(p2<l2)
        {
            ans=ans+b[p2];
            p2++;
        }
        return ans;
        
    }
};
