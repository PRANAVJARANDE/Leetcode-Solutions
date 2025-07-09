class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) 
    {
        int n=s.size();
        int k=indices.size();
        vector<bool>can_change(n,0);
        map<int,string>index_to_tar,index_to_source;

        for(int i=0;i<k;i++)
        {
            int in=indices[i];
            string src=sources[i];
            string tar=targets[i];
            
            
            bool change=1;
            int sz=src.size();
            if(in+sz-1>=n)continue;
            for(int j=in;j<in+sz;j++)
            {
                if(s[j]!=src[j-in])
                {
                    change=0;
                    break;
                }
            }
            
            if(change)
            {
                can_change[in]=change;
                index_to_tar[in]=tar;
                index_to_source[in]=src;
            }
        }


        string res="";
        for(int i=0;i<n;i++)
        {
            if(can_change[i])
            {
                res+=index_to_tar[i];
                i+=index_to_source[i].size();
                i--;
            }
            else
            {
                res+=s[i];
            }
        }
        return res;
    }
};
