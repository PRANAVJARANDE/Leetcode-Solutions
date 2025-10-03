class Solution {
  public:
        
    vector<vector<int>>comb;
    void helper(int in,vector<int>&v1,string&s)
    {
        int n=s.size();
        if(in>=n)
        {
            comb.push_back(v1);
            return;
        }
        if(s[in]=='0')
        {
            v1.push_back(0);
            helper(in+1,v1,s);
            v1.pop_back();
            return;
        }
        int num=0;
        for(int i=in;i<n;i++)
        {
            //num = num*10 + (s[i]-'0');  
            num=num*10;
            num+=s[i]-'0';
            v1.push_back(num);
            helper(i+1,v1,s);
            v1.pop_back();
        }
    }
    
    void gene(int in,int n,vector<int>&v1,vector<vector<int>>&ops)
    {
        if(in>=n)
        {
            ops.push_back(v1);
            return;
        }
        for(int z=0;z<3;z++)
        {
            v1.push_back(z);
            gene(in+1,n,v1,ops);
            v1.pop_back();
        }
    }
    
    long long compute(vector<int>&x,vector<int>&y)
    {
        int n=x.size();
        vector<long long>v1;
        vector<long long>v2;
        v1.push_back(x[0]);
        
        for(int i=1;i<n;i++)
        {
            v1.push_back(x[i]);
            if(y[i-1]==2)
            {
                int p1=v1.back();
                v1.pop_back();
                int p2=v1.back();
                v1.pop_back();
                v1.push_back(p1*p2);
            }
            else
            {
                v2.push_back(y[i-1]);
            }
        }
        
        int res=v1[0];
        for(int i=1;i<v1.size();i++)
        {
            if(v2[i-1]==0)res+=v1[i];
            else res-=v1[i];
        }
        return res;
    }
    
    string prep(vector<int>&x,vector<int>&y)
    {
        string res=to_string(x[0]);
        for(int i=1;i<x.size();i++)
        {
            if(y[i-1]==0)res+="+";
            else if(y[i-1]==1)res+="-";
            else res+="*";
            res+=to_string(x[i]);
        }
        return res;
    }   
    
    vector<string> findExpr(string &s, int target) 
    {
        vector<string>ans;
        if(stoi(s)==target)
        {
            if(s[0]=='0')
            {
                if(s.size()==1)ans.push_back(s);
            }
            else ans.push_back(s);
            
            //if(ans.size()>=1)cout<<ans[0]<<endl;
        }
        vector<int>v1;
        helper(0,v1,s);
        int n=s.size();
        vector<vector<vector<int>>>ops(n);
        for(int i=1;i<n;i++)
        {
            vector<int>v2;
            gene(0,i,v2,ops[i]);
        }
        
        
        for(auto x:comb)
        {
            int sz=x.size();
            for(auto y:ops[sz-1])
            {
                if(compute(x,y)==target)
                {
                    ans.push_back(prep(x,y));
                }   
            }
        }
        return ans;
        
    }
};
