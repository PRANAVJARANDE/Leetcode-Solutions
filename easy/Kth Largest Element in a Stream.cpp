class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> q1;
    KthLargest(int j, vector<int>& nums) {
        k=j;
        for(int x: nums)
        {
            q1.push(x);
            if(q1.size()>k)
            {
                q1.pop();
            }
        }
    }
    
    int add(int val) {
        q1.push(val);
        if(q1.size()>k)q1.pop();
        return q1.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
