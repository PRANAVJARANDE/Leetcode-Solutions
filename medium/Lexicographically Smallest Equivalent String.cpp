class Solution {
public:

    string smallestEquivalentString(string s1, string s2, string b) 
    {
        int n=s1.size();
        vector<int>par(26,0);
        for(int i=0;i<26;i++)par[i]=i;
        for(char c='a';c<='z';c++)
        {
            for(int i=0;i<n;i++)
            {
                par[s1[i]-'a']=min(par[s1[i]-'a'],par[s2[i]-'a']);
                par[s2[i]-'a']=min(par[s1[i]-'a'],par[s2[i]-'a']);
            }
        }

        // for(int i=0;i<26;i++)
        // {
        //     char ch=i+'a';
        //     char p=par[i]+'a';
        //     cout<<ch<<" "<<p<<" "<<endl;
        // }

        for(int i=0;i<b.size();i++)
        {
            char ch=par[b[i]-'a']+'a';
            b[i]=ch;
        }
        return b;
    }
};
