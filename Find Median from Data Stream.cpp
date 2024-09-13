class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int> > minpq;      
    MedianFinder() {
        
    }
    
    void addNum(int n) {
            if(minpq.empty() && maxpq.empty())
            {
                maxpq.push(n);
            } 
            else if(!maxpq.empty() && n <= maxpq.top())
            {
                maxpq.push(n);
            } 
            else
            {
                minpq.push(n);
            }
        
        
    
   

        if(maxpq.size() - minpq.size() ==2  || maxpq.size() - minpq.size() == -2  )
        {
            if(maxpq.size()>minpq.size())
            {
                minpq.push(maxpq.top());
                maxpq.pop();
            }
            else
            {
                maxpq.push(minpq.top());
                minpq.pop();
            }
        }
    }
    
    double findMedian() 
    {
        
        if(maxpq.size()==minpq.size())
        {
            if(maxpq.empty() && minpq.empty())
            {
                return 0;
            }
            double b=(maxpq.top()+minpq.top())/2.0;
            return b;
        }
        else if(maxpq.size()>minpq.size())
        {
            return maxpq.top();
        }
        
        return minpq.top();
    }
};
