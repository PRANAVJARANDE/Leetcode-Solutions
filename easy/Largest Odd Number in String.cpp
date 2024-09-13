class Solution {
public:
    string largestOddNumber(string num) 
    {
        int j=num.size()-1;
        while(j>=0)
        {
            int n=num[j]-'0';
            if(n%2==1)
            {
                return num.substr(0,j+1);
            }
            j--;
        }
        return "";
    }
};
