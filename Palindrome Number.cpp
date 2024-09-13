class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
        {
            return 0;
        }

        long long rev=0;
        int n=x;
        while(n!=0)
        {
            int rem=n%10;
            rev=rev*10+rem;
            n=n/10;
        }
        if(x==rev)
        {
            return 1;
        }
        return 0;
    }
};
