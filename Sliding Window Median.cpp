class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int, greater<int>> maxi;
        multiset<int> mini;
        int i = 0;
        vector<double> ans;
        for(int j=0; j<nums.size(); j++) 
        {
            maxi.insert(nums[j]);

            if(!mini.empty() && *maxi.begin() > *mini.begin()) 
            {
                mini.insert(*maxi.begin());
                maxi.erase(maxi.begin());
            }
            if(maxi.size() > mini.size()+1) 
            {
                mini.insert(*maxi.begin());
                maxi.erase(maxi.begin());
            }
            if(mini.size() > maxi.size()+1) {
                maxi.insert(*mini.begin());
                mini.erase(mini.begin());
            }
            
            
            if(j-i+1 == k) {
                double val;
                if(k & 1) 
                {
                    val = maxi.size() > mini.size() ? *maxi.begin() : *mini.begin();
                } 
                else 
                { 
                    val = ( (double)*maxi.begin() + (double)*mini.begin() ) / (double)2;
                }
                ans.push_back(val);
                
                if(maxi.find(nums[i]) != maxi.end()) 
                {
                    maxi.erase(maxi.find(nums[i]));
                }
                else if(mini.find(nums[i]) != mini.end()) 
                {
                    mini.erase(mini.find(nums[i]));
                }
                
                i++;
            }
        }
        return ans;
    }
};
