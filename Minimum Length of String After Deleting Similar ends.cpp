class Solution {
public:
    int minimumLength(string a) 
    {
        int n=a.size();
        int l=0,r=n-1;
        while(l<r && a[l]==a[r])
        {
            char ch=a[l];
            while(l<r && a[l]==ch)
            {
                l++;
            }
            if(l==r)return 0;
            while(l<r && a[r]==ch)
            {
                r--;
            }
            if(l==r)return 1;
        }
        return r-l+1;
    }
};
