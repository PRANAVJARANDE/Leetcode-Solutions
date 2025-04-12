class Solution {
public:

    int limit;
    vector<long long >v1;
    long long helper(int in,long long num,int k,int n)
    {
        if(in>=limit)
        {
            if(num%k==0)
            {
                v1.push_back(num);
                return 1;
            }
            return 0;
        }
        int i1=in;
        int i2=n-in-1;
        long long ans=0;
        for(int j=0;j<=9;j++)
        {
            if(in==0 && j==0)continue;
            long long nexnum=num;
            nexnum+=(powl(10,i1)*j);
            if(i1!=i2)
            {
                nexnum+=(powl(10,i2)*j);
            }
            ans+=helper(in+1,nexnum,k,n);
        }
        return ans;
    }

    long long factorial(int n) 
    {
        long long result=1;
        for(int i=2;i<=n;i++)result*=i;
        return result;
    }

    long long calc(string r)
    {
        map<char,int>m;
        for(auto x:r)m[x]++;
        int sz=r.size();
        long long res=factorial(sz);
        for(auto x:m)
        {
            res/=factorial(x.second);
        }
        if(m['0']!=0)
        {
            m['0']--;
            sz--;
            long long tm=factorial(sz);
            for(auto x:m)
            {
                tm/=factorial(x.second);
            }
            res-=tm;
        }
        return res;
    }


    long long countGoodIntegers(int n, int k) 
    {
        limit=(n+1)/2;
        helper(0,0,k,n);
        long long ans=0;
        map<string,int>m;
        for(auto x:v1)
        {
            string r=to_string(x);
            sort(r.begin(),r.end());
            cout<<r<<" ";
            if(m[r]==0)
            {
                m[r]=1;
                ans+=calc(r);
            }
        }
        return ans;
    }
};
