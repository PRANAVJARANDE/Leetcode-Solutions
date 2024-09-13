class RandomizedSet {
public:

    set<int> s1;

    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        auto pos=s1.find(val);
        if(pos==s1.end())
        {
            s1.insert(val);
            return 1;
        }
        s1.insert(val);
        return 0;
    }
    
    bool remove(int val) 
    {
        auto pos=s1.find(val);
        if(pos==s1.end())
        {
            return 0;
        }
        s1.erase(val);
        return 1;
        
    }
    
    int getRandom()
    {
        vector<int> v1;
        for(auto x:s1)
        {
            v1.push_back(x);
        }
        return v1[rand()%v1.size()];
    }
};
