class Solution {
  public:
    
    int n;
    vector<string>ans;
    map<int,vector<char>>m;
    void helper(int in,string&curr,vector<int>&a)
    {
        if(in>=n)
        {
            ans.push_back(curr);
            return;
        }
        if(a[in]<=1)helper(in+1,curr,a);
        else
        {
            for(auto x:m[a[in]])
            {
                curr.push_back(x);
                helper(in+1,curr,a);
                curr.pop_back();
            }
        }
    }
  
    vector<string> possibleWords(vector<int> &a) 
    {
        n=a.size();
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        string curr="";
        helper(0,curr,a);
        return ans;
    }
};
