class Solution {
public:
        
long long sumOfAP(long long a, long long d, long long n) 
{
    long long sum = (n * (2 * a + (n - 1) * d)) / 2;
    return sum;
}

        
    int differenceOfSums(int n, int m)
    {
        long long s1=sumOfAP(1,1,n)-2*sumOfAP(m,m,n/m);
        return s1;
    }
};
