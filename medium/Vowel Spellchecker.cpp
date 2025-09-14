class Solution {
public:

    string tolower(string s)
    {
        for(auto &x:s)
        {
            if('A'<=x && x<='Z')
            {
                x=x-'A'+'a';
            }
        }
        return s;
    }

    bool isvov(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return 1;
        return 0;
    }


    string mask_string(string s)
    {
        for(auto &x:s)
        {
            if(isvov(x)) x = '#';
            else if('A'<=x && x<='Z')x=x-'A'+'a';
        }
        return s;
    }


    vector<string> spellchecker(vector<string>& wl, vector<string>& queries) 
    {
        int n=wl.size();
        map<string,int>org;
        map<string,int>all_small;
        map<string,int>mask;
        for(int i=0;i<n;i++)
        {
            if(org.find(wl[i])==org.end())org[wl[i]]=i;
            string s1=tolower(wl[i]);
            if(all_small.find(s1)==all_small.end())all_small[s1]=i;
            string s2=mask_string(wl[i]);
            if(mask.find(s2)==mask.end())mask[s2]=i;
        }
        vector<string>ans;
        for(auto x:queries)
        {
            if(org.find(x)!=org.end())ans.push_back(wl[org[x]]);
            else if(all_small.find(tolower(x))!=all_small.end())ans.push_back(wl[all_small[tolower(x)]]);
            else if(mask.find(mask_string(x))!=mask.end())ans.push_back(wl[mask[mask_string(x)]]);
            else ans.push_back("");
        }
        return ans;
    }
};
