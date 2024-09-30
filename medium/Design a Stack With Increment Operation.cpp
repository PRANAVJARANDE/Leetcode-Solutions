class CustomStack {
public:
    int mx;
    vector<int> v1;
    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(v1.size()<mx)v1.push_back(x);
    }
    
    int pop() {
        if(v1.size())
        {
            int in=v1.back();
            v1.pop_back();
            return in;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)v1.size());i++)v1[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
