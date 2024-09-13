class SeatManager {
public:

    int n;
    set<int> unres;
    SeatManager(int nn) 
    {
        n=nn;
        for(int i=1;i<=n;i++)
        {
            unres.insert(i);
        }
    }
    
    int reserve() 
    {
        if(unres.size()!=0)
        {
            int k=*unres.begin();
            unres.erase(k);
            return k;
        }
        return -1;
    }
    
    void unreserve(int sn) 
    {
        unres.insert(sn);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
