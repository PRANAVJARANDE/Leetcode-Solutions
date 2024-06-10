class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int> v1(n);
        for(int i=0;i<n;i++)
        {
            v1[i]=heights[i];
        }
        sort(v1.begin(),v1.end());
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]!=heights[i])
            {
                cnt++;
            }
        }
        return cnt;

    }
};
