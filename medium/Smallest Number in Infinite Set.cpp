class SmallestInfiniteSet {
public:

    set<int> s1;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            s1.insert(i);
        }
    }
    
    int popSmallest() {
        int a=*s1.begin();
        s1.erase(s1.begin());
        return a;
    }
    
    void addBack(int num) {
        s1.insert(num);
    }
};
