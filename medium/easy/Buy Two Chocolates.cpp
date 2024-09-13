class Solution {
public:
    int buyChoco(vector<int>& arr, int m) 
    {
        int m1=INT_MAX,m2=INT_MAX;
        for(int x:arr)
        {
            if(m2>x)
            {
                m1=m2;
                m2=x;
            }
            else if(m1>x)
            {
                m1=x;
            }
        }
        if(m1+m2>m)
        {
            return m;
        }
        return m-m1-m2;
    }
};
