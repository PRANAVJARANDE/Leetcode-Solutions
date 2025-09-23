class Solution {
  public:
    
    void reverseQueue(queue<int> &q1) 
    {
        if(q1.empty())return;
        int in=q1.front();
        q1.pop();
        reverseQueue(q1);
        q1.push(in);
    }
};
