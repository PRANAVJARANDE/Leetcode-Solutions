class Solution {
  public:
  
    string help(int i)
    {
        string res="";
        while(i)
        {
            char ch='0';
            if(i%2)ch='1';
            res=ch+res;
            i/=2;
        }
        return res;
    }
    
  
    vector<string> generateBinary(int n) 
    {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(help(i));
        }
        return ans;
    }
};
