public:
    int subtractProductAndSum(int n) {
        int p=1;
        int s=0;
        while(n!=0)
        {
            int rem=n%10;
            p*=rem;
            s+=rem;
            n/=10;
        }
        return p-s;
    }
};
