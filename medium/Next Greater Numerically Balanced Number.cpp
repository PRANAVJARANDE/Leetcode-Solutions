class Solution {
public:

    bool check(int n)
    {
        vector<int>v1(10,0);
        while(n)
        {
            v1[n%10]++;
            n/=10;
        }
        for(int i=0;i<10;i++)
        {
            if(v1[i]==0)continue;
            if(v1[i]!=i)return 0;
        }
        return 1;
    }

    int nextBeautifulNumber(int n) 
    {
        int j=n+1;
        while(1)
        {
            if(check(j))return j;
            j++;
        }
        return 1e6;
    }
};
