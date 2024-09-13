class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q1.push(x);
    }
    
    int pop() 
    {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int t=q1.front();
        q1.pop();
        q1.swap(q2);
        return t;
    }
    
    int top() 
    {
        return q1.back();
    }
    
    bool empty() 
    {
        if(q1.empty())
        {
            return 1;
        }
        return 0;
    }
};
