class Solution {
public:

    int getmini(string s)
    {
        int n=s.size();
        char ch=s[0];
        if(ch=='1')
        {
            int i=0;
            while(i<n && (s[i]=='1' || s[i]=='0'))i++;
            if(i<n)
            {
                char ch=s[i];
                for(int j=i;j<n;j++)
                {
                    if(s[j]==ch)s[j]='0';
                }
            }
            return stoi(s);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==ch)s[i]='1';
        }
        return stoi(s);
    }

    int getmaxi(string s)
    {
        int n=s.size();
        int i=0;
        while(i<n && s[i]=='9')i++;
        if(i<n)
        {
            char ch=s[i];
            for(int j=i;j<n;j++)
            {
                if(s[j]==ch)s[j]='9';
            }
        }
        return stoi(s);
    }


    int maxDiff(int num) {
        string s=to_string(num);
        int maxi=getmaxi(s);
        int mini=getmini(s);
        return maxi-mini;
    }
};
