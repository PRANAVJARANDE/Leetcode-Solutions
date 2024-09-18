class Solution {
public:

    static bool compare(const string &a, const string &b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> v1;
        for(int x:nums)
        {
            string r=to_string(x);
            v1.push_back(r);
        }
        sort(v1.begin(),v1.end(),compare);
        if(v1[0]=="0")return "0";
        string ans="";
        for(auto x:v1)
        {
            ans+=x;
        }
        return ans;
    }
};
