class Solution {
public:

    string helper(unordered_set<string>&s1,int n,int i,string s)
    {
        if(i==n)
        {
            if(s1.count(s)==0)
            {
                return s;
            }
            return "";
        }

        string aa=helper(s1,n,i+1,s+"1");
        if(aa!="")
        {
            return aa;
        }
        string s2=helper(s1,n,i+1,s+"0");
        if(s2!="")
        {
            return s2;
        }
        return "";
    }


    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<string> s1(nums.begin(),nums.end());
        return helper(s1,nums[0].size(),0,"");
    }
};
