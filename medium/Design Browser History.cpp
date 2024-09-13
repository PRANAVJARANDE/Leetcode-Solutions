class node
{
public:
    string data;
    node* next;
    node* prev;

    node(string x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};



class BrowserHistory {
public:

    node* head;
    node* curr;

    BrowserHistory(string homepage) {
        head=new node(homepage);
        curr=head;
    }
    
    void visit(string url) {
        node* n=new node(url);
        node* td=curr->next;
        curr->next=n;
        n->prev=curr;
        curr=n;

        node* temp=td;
        while(temp!=NULL)
        {
            node *h=temp;
            temp=temp->next;
            delete h;
        }
    }
    
    string back(int steps) {
        int u=0;
        node* temp=curr;
        while(temp->prev!=NULL && u<steps)
        {
            temp=temp->prev;
            u++;
        }
        curr=temp;
        return temp->data;
    }
    
    string forward(int steps) {
        int u=0;
        node* temp=curr;
        while(temp->next!=NULL && u<steps)
        {
            temp=temp->next;
            u++;
        }
        curr=temp;
        return temp->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
