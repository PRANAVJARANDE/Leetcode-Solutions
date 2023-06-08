class Solution {
public:
    string removeTrailingZeros(string num) 
    {
        while(num[num.size()-1]=='0')
        {
            num=num.substr(0,num.size()-1);
        }
        return num;
    }
};
