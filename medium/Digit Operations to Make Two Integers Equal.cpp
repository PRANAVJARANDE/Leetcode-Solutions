class Solution {
public:

    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int minOperations(int n, int m) 
    {
        vector<bool>isprime=sieveOfEratosthenes(1e5);
        if(isprime[n] || isprime[m])return -1;
        map<string,bool> vis;
        string ms=to_string(m);
        int sz=ms.size();
        vis[to_string(n)]=1;
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>q1;
        q1.push({n,to_string(n)});

        while(!q1.empty())
        {
            int cans=q1.top().first;
            string cs=q1.top().second;
            q1.pop();
            if(cs==ms)
            {
                return cans;
            }
            
            for(int i=sz-1;i>=0;i--)
            {
                int digi=cs[i]-'0';
                //decreasing
                if(digi>0)
                {
                    cs[i]=digi-1+'0';
                    if(cs[0]!='0')
                    {
                        int ndig=stoi(cs);
                        if(vis[cs]==0 && !isprime[ndig])
                        {
                            vis[cs]=1;
                            q1.push({cans+ndig,cs});
                        }
                    }
                }
                //increasing
                if(digi<9)
                {
                    cs[i]=digi+1+'0';
                    int ndig=stoi(cs);
                    if(vis[cs]==0 && !isprime[ndig])
                    {
                        vis[cs]=1;
                        q1.push({cans+ndig,cs});
                    }
                }
                cs[i]=digi+'0';
            }
            
        }
        return -1;
    }
};
