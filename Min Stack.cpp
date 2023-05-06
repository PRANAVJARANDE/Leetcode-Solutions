class MinStack {
public:

   
    vector<int> v1;
    

    void push(int val) 
    {
        v1.push_back(val);
    
    }
    
    void pop() 
    {
        v1.pop_back();   
    }
    
    int top() 
    {
       return v1[v1.size()-1];
    }
    
    int getMin() 
    {
        int m=INT_MAX;
        for(int i=0;i<v1.size();i++)
        {
            m=min(m,v1[i]);
        }
        return m;
    }
};
