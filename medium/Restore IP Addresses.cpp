class Solution {
public:

    bool isvalid(string s)
    {
        int n=s.size();
        if(n==0 || n>3)return 0;
        if(n==1)return 1;
        if(s[0]=='0')return 0;
        int val=stoi(s);
        if(val<=255)return 1;
        return 0;
    }

    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        if(n<4 || n>12)return ans;

        for(int i=0;i<min(n,3);i++)
        {
            for(int j=i+1;j<min(n,i+4);j++)
            {
                for(int k=j+1;k<min(n,j+4);k++)
                {
                    string r1=s.substr(0,i+1);
                    string r2=s.substr(i+1,j-i);
                    string r3=s.substr(j+1,k-j);
                    string r4=s.substr(k+1);

                    if(isvalid(r1) && isvalid(r2) && isvalid(r3) && isvalid(r4))
                        ans.push_back(r1+"."+r2+"."+r3+"."+r4);
                    
                }
            }
        }
        return ans;
    }
};
