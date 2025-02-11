class Solution {
public:
    string removeOccurrences(string s, string p) {
        vector<char> v1;
        
        for(char c:s) 
        {
            v1.push_back(c);
            int vs=v1.size();
            int ps=p.size();
            if (vs >= ps) 
            {  
                bool bb=1;
                for(int j=0;j<ps;j++) 
                {
                    if(v1[vs-ps+j]!=p[j]) 
                    {
                        bb=0;
                        break;
                    }
                }
                if(bb) 
                {
                    while(ps--)
                    {
                        v1.pop_back();
                    }
                }
            }
        }
        string res(v1.size(),'a');
        for(int i=0;i<v1.size();i++)
        {
            res[i]=v1[i];
        }
        return res;
    }
};
