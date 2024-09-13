class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> v1;
        for(int i=0;i<pow(2,n);i++)
        {
            int a=i;
            int b=i>>1;
            v1.push_back(a^b);
        }
        return v1;
    }
};
