class Solution {
public:
    int sum;
    vector<int> psum;
    Solution(vector<int>& w) 
    {
        sum=w[0];
        psum.push_back(w[0]);
        for(int i=1;i<w.size();i++)
        {
            psum.push_back(psum[i-1]+w[i]);
            sum+=w[i];
        }
    }
    
    int pickIndex() {
        int in=rand()%sum;
        int index=upper_bound(psum.begin(),psum.end(),in)-psum.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
