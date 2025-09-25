class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        
        k=k%dq.size();
        while(k--)
        {
            int val;
            if(type==1)
            {
                val=dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
            else 
            {
                val=dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
        
    }
};
