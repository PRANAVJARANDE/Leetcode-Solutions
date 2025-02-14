class ProductOfNumbers {
public:
    vector<int>v1;
    
    void add(int num) 
    {
        if(num==0)
        {
            v1.clear();
        }
        else
        {
            if(!v1.empty())v1.push_back(v1.back()*num);
            else v1.push_back(num);
        }
    }
    
    int getProduct(int k)
    {
        int p=v1.back(),sz=v1.size();
        if(sz-k-1>=0)p/=v1[sz-k-1];
        if(sz-k<0)p=0;
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
