class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int t=s1.top();
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    

    int peek() 
    {
        while(s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int t=s1.top();
        s2.push(s1.top());
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        if(s1.size()==0)
        {
            return 1;
        }
        return 0;
    }
};
