class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> res;
        for(int i=1;i<=9;i++)
        {
            int c=i;
            int nx=i+1;
            while(c<=high && nx<=9)
            {
                c=c*10+nx;
                if(c<=high && c>=low)
                {
                    res.push_back(c);
                }
                nx++;
            }   
        }
        sort(res.begin(),res.end());
        return res;
    }
};
