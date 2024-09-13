class Solution {
public:

    set<pair<int,int>>s1;
    int m;
    int n;

    Solution(int k, int z) 
    {
        m=k;
        n=z;
    }
    
    vector<int> flip() 
    {
        int r=rand()%m;
        int c=rand()%n;
        while(s1.count({r,c})==1)
        {
            r=rand()%m;
            c=rand()%n;
        }
        s1.insert({r,c});
        return {r,c};
    }
    
    void reset() 
    {
        s1.clear();
    }
};
