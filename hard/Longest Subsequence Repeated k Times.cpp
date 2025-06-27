class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        int n=s.size();
        vector<char>v1;
        map<char,int>freq;
        for(auto x:s)
        {
            freq[x]++;
            if(freq[x]==k)v1.push_back(x);
        }
        sort(v1.begin(),v1.end(),greater<char>());
        queue<string>q1;
        for(auto x:v1)q1.push(string(1,x));
        
        string res="";
        while(!q1.empty())
        {
            string in=q1.front();
            q1.pop();

            if(in.size()>res.size())res=in;

            for(auto x:v1)
            {
                string nw=in+x;
                //check for new

                int in=0;
                int sz=nw.size();
                int cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(s[i]==nw[in])
                    {
                        in++;
                        if(in==sz)
                        {
                            in=0;
                            cnt++;
                        }
                    }
                }
                if(cnt>=k)q1.push(nw);
            }
        }
        return res;
    }
};
