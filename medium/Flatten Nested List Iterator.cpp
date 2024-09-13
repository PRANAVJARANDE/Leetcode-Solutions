class NestedIterator {
public:

    vector<int> v1;
    int ptr;


    void getlist(vector<NestedInteger> &nest,vector<int> &vec)
    {
        for(auto x: nest)
        {
            if(x.isInteger())
            {
                vec.push_back(x.getInteger());
            }
            else
            {
                vector<NestedInteger> temp=x.getList();
                getlist(temp,vec);
            }
        }
    }


    NestedIterator(vector<NestedInteger> &nest) 
    {
        ptr=-1;
        getlist(nest,v1);
    }
    
    int next() 
    {
        ptr++;
        return v1[ptr];
    }
    
    bool hasNext() 
    {
        int n=v1.size();
        if(ptr>=n-1)
        {
            return 0;
        }
        return 1;
    }
};
