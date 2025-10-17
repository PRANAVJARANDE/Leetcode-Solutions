class AllOne {
public:

    class Node
    {   
        public:
            int mini;
            int maxi;
            string smin;
            string smax;
            int count;
            vector<Node*>next;
            string cur;
        
        Node()
        {
            count=0;
            mini=INT_MAX;
            maxi=INT_MIN;
            smin="";
            smax="";
            cur="";
            next=vector<Node*>(26,NULL);
        }
    };
    
    Node* root;
    AllOne() 
    {
        root=new Node();
    }

    void helper(int in,Node* temp,string&s,int op)
    {
        if(in>=s.size())temp->count+=op;
        else
        {
            int ch=s[in]-'a';
            if(temp->next[ch]==NULL)temp->next[ch]=new Node();
            helper(in+1,temp->next[ch],s,op);
        }
        if(temp->count==0)
        {
            temp->mini=INT_MAX;
            temp->maxi=0;
            temp->cur="";
            temp->smin="";
            temp->smax="";
        }
        else
        {
            temp->cur=s;
            temp->maxi=temp->count;
            temp->mini=temp->count;
            temp->smin=s;
            temp->smax=s;
        }

        for(int i=0;i<26;i++) 
        {
            Node* nxt=temp->next[i];
            if(nxt!=NULL) 
            {
                if(nxt->maxi > temp->maxi) 
                {
                    temp->maxi=nxt->maxi;
                    temp->smax=nxt->smax;
                }
                if(nxt->mini < temp->mini) 
                {
                    temp->mini=nxt->mini;
                    temp->smin=nxt->smin;
                }
            }
        }
    }

    void inc(string s) 
    {
        Node* temp=root;
        helper(0,temp,s,1);
        //cout<<"INC - "<<s<<" "<<getMaxKey()<<" "<<getMinKey()<<endl;
    }
    
    void dec(string s) 
    {
        Node* temp=root;
        helper(0,temp,s,-1);
        //cout<<"DEC - "<<s<<" "<<getMaxKey()<<" "<<getMinKey()<<endl;
    }
    
    string getMaxKey() 
    {
        return root->smax;
    }
    
    string getMinKey() 
    {
        return root->smin;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
