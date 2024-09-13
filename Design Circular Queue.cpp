class MyCircularQueue {
public:

    int f;
    int b;
    int n;
    vector<int> arr;
    MyCircularQueue(int k) {
        vector<int>temp(k,0);
        arr=temp;
        f=-1;
        b=-1;
        n=k;
    }
    
    bool enQueue(int value) {
        if(this->isFull())
        {
            return 0;
        }

        if(f==-1 && b==-1)
        {
            f=0;
            b=0;
            arr[0]=value;
            return 1;
        }
        if(b==n-1)
        {
            b=0;
            arr[b]=value;
            return 1;
        }
        b++;
        arr[b]=value;
        return 1;
    }
    
    bool deQueue() {
        if(this->isEmpty())
        {
            return 0;
        }
        if(f==b)
        {
            f=-1;
            b=-1;
            return 1;
        }
        if(f==n-1)
        {
            f=0;
            return 1;
        }
        f++;
        return 1;
    }
    
    int Front() {
        if(f==-1)
        {
            return -1;
        }
        return arr[f];
    }
    
    int Rear() {
        if(b==-1)
        {
            return -1;
        }
        return arr[b];
    }
    
    bool isEmpty() {
        if(b==-1 && f==-1)
        {
            return 1;
        }
        return 0;
    }
    
    bool isFull() {
        if(f==0 && b==n-1)
        {
            return 1;
        }
        if(f==b+1)
        {
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
