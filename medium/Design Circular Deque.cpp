class MyCircularDeque {
public:

    class node
    {
        public:
        int data;
        node* next;
        node* prev;

        node(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
    };

    int sz;
    node* head;
    node* tail;
    int k;

    MyCircularDeque(int kk) {
        sz=0;
        k=kk;
        head=NULL;
        tail=NULL;
    }
    
    bool insertFront(int val) {

        if(sz==k)
        {
            return 0;
        }
        node* n=new node(val);
        if(head==NULL)
        {
            head=n;
            tail=n;
            sz++;
            return 1;
        }
        n->next=head;
        head->prev=n;
        head=n;
        sz++;
        return 1;
    }
    
    bool insertLast(int val) {

        if(sz==k)
        {
            return 0;
        }
        node* n=new node(val);
        if(head==NULL)
        {
            head=n;
            tail=n;
            sz++;
            return 1;
        }
        tail->next=n;
        n->prev=tail;
        tail=n;
        sz++;
        return 1;
    }
    
    bool deleteFront() 
    {
        if(head==NULL)     
        {
            return 0;
        }   
        if(head==tail)
        {
            sz--;
            node* td=head;
            head=NULL;
            tail=NULL;
            delete td;
            return 1;
        }
        node* td=head;
        head=head->next;
        head->prev=NULL;
        delete td;
        sz--;
        return 1;
    }
    
    bool deleteLast() {
        if(tail==NULL)     
        {
            return 0;
        }   
        if(head==tail)
        {
            sz--;
            node* td=head;
            head=NULL;
            tail=NULL;
            delete td;
            return 1;
        }
        node* td=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete td;
        sz--;
        return 1;
    }
    
    int getFront() {
        if(head==NULL)
            return -1;

        return head->data;
    }
    
    int getRear() {
        if(tail==NULL)
            return -1;

        return tail->data;
    }
    
    bool isEmpty() {
        if(head==NULL)
            return 1;

        return 0;
    }
    
    bool isFull() {
        if(sz==k)
            return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
