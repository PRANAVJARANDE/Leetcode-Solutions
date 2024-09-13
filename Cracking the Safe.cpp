class Solution {
public:

    int maxi;
    string s="";
    set<string>s1;
    int n,k;
    bool helper()
    {
        if(s1.size()>=maxi)return 1;

        for(int i=0;i<k;i++)
        {
            s+=to_string(i);
            if(s.size()<n)
            {
                bool b=helper();
                if(b==1)return 1;
            }
            else
            {
                string ta=s.substr(s.size()-n);
                if(s1.find(ta)==s1.end())
                {
                    s1.insert(ta);
                    bool b=helper();
                    if(b==1)return 1;
                    s1.erase(ta);
                }
            }
            s.pop_back();
        }
        return 0;
    }

    string crackSafe(int a, int b) {
        n=a,k=b;
        maxi=pow(k,n);
        helper();
        return s;
    }
};
