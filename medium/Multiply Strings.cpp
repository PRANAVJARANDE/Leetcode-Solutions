class Solution {
public:
    string multiply(string n1, string n2) 
    {
        if (n1 == "0" || n2 == "0") return "0";
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        int l1=n1.size(),l2=n2.size();
        vector<int>v1(l1+l2+2,0);
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<l2;j++)
            {
                int a=n1[i]-'0';
                int b=n2[j]-'0';
                v1[i+j]+=a*b;
            }
        }

        int rem=0;
        for(int i=0;i<l1+l2+2;i++)
        {
            v1[i]+=rem;
            rem=v1[i]/10;
            v1[i]=v1[i]%10;
        }
        while(v1.back()==0)
        {
            v1.pop_back();
        }
        string ans="";
        for(int x:v1)
        {
            ans=to_string(x)+ans;
        }
        return ans;
    }
};
