class Solution {
public:
    int totalMoney(int n) 
    {
        int d=n/7;
        int ans=28*d;
        int rem=n%7;
        ans+=((rem*(rem+1))/2);
        ans+=(7*d*(d-1))/2;
        ans+=(rem*d);
        return ans;
    }
};
