//BY MATHEMATICS
//Suppose k rows fill completely
//sum: k=1+2+3+4+5+....k
//sum=k(k+1)/2 <=n
//solve for equaltiy



//BY BRUTE FORCE
class Solution {
public:
    int arrangeCoins(int n) 
    {
        int i=1;
        while(i<=n)
        {
            n=n-i;
            i++;
        }
        return i-1;
    }
};
