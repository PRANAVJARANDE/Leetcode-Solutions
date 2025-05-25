class Solution {
public:

    long long helper(string r)
    {
        long long num=0;
        for(auto x:r)
        {
            int z=x-'0';
            num*=10;
            num+=z;
        }

        for(int i=2;i<=sqrtl(num);i++)
        {
            if(num%i==0)return -1;
        }
        return num;
    }

    long long sumOfLargestPrimes(string s) 
    {
        set<long long>v1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string r=s.substr(i,j-i+1);
                long long res=helper(r);
                if(res!=-1 && res!=0 && res!=1)
                {
                    v1.insert(res);
                }
            }
        }
        vector<long long>v2;
        for(auto x:v1)
        {
            v2.push_back(x);
        }
        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());

        
        long long ans=0;
        for(int i=0;i<min(3,(int)v2.size());i++)
        {
            ans+=v2[i];
        }
        return ans;
    }
};
