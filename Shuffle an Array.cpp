class Solution {
public:
    vector<int> v1;
    vector<int> cpy;
    Solution(vector<int>& nums) 
    {
        cpy=nums;
        v1=nums;
    }
    
    vector<int> reset() 
    {
        return cpy;
    }
    
    vector<int> shuffle() 
    {
        int n=v1.size();
        swap(v1[rand()%n],v1[rand()%n]);
        return v1;
    }
};
