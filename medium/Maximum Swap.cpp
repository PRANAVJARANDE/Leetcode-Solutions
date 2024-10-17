class Solution {
public:
    int maximumSwap(int n) {
        string s="";
        while(n)
        {
            int rem=n%10;
            s=to_string(rem)+s;
            n/=10;
        }
        for(int i=0;i<s.size();i++)
        {
            int i1=s[i]-'0';
            int maxi=i1;
            int ind=i;
            for(int j=i+1;j<s.size();j++)
            {
                int r=s[j]-'0';
                if(r>=maxi)
                {
                    maxi=r;
                    ind=j;
                }
            }
            if(maxi!=i1)
            {
                swap(s[i],s[ind]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};
