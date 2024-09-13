class Solution {
public:

    long long helper(long long a,bool ev)
    {
        long long ans=a;
        if(ev==0)
        {
            a/=10;
        }
        while(a)
        {
            ans=ans*10 + a%10;
            a/=10;
        }
        return ans;
    }

    string nearestPalindromic(string s) {
        vector<long long>op;
        int n=s.size();
        int mid=n/2;
        if(n%2==0)mid--;
        long long hf=stoll(s.substr(0,mid+1));
        op.push_back(helper(hf,n%2==0));
        op.push_back(helper(hf+1,n%2==0));
        op.push_back(helper(hf-1,n%2==0));
        op.push_back(powl(10,n-1)-1);
        op.push_back(powl(10,n-1)+1);
        op.push_back(powl(10,n)+1);
        op.push_back(powl(10,n)-1);
        long long diff=LLONG_MAX,ans=0,num=stoll(s);
        for(auto x: op)
        {
            if(x==num)continue;
            if(abs(x-num)<diff)
            {
                diff=abs(x-num);
                ans=x;
            }
            else if(abs(x-num)==diff)
            {
                ans=min(ans,x);
            }
        }


        return to_string(ans);
    }
};
