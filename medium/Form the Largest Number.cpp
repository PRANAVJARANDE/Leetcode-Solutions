class Solution {
  public:
    
    static bool cmp(int&a,int&b)
    {
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
  
    string findLargest(vector<int> &a) {
        sort(a.begin(),a.end(),cmp);
        string res="";
        for(auto x:a)res+=to_string(x);
        int in=0;
        while(in<res.size() && res[in]=='0')
        {
            in++;
        }
        res=res.substr(in);
        if(res.size()==0)res="0";
        return res;
    }
};
