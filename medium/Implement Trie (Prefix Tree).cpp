class Trie {
public:


    class node
    {
        public:
        bool end;
        string word;
        node* next[26];
        node()
        {
            end=0;
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
            word="";
        }
    };
    node* root;

    Trie() {
        root=new node();
    }
    
    void insert(string s) 
    {
        int i=0;
        node* temp=root;
        while(i<s.size())
        {
            if(temp->next[s[i]-'a']==NULL)
            {
                temp->next[s[i]-'a']=new node();
            }
            temp=temp->next[s[i]-'a'];
            i++;
        }
        temp->end=1;
        temp->word=s;
    }
    
    bool search(string s) 
    {
        int i=0;
        node* temp=root;
        while(i<s.size() && temp!=NULL)
        {
            temp=temp->next[s[i]-'a'];
            i++;
        }
        return temp!=NULL && temp->end==1;
    }
    
    bool startsWith(string s) {
        node* temp=root;
        int i=0;
        while(temp!=NULL  && i<s.size())
        {
            temp=temp->next[s[i]-'a'];
            i++;
        }
        return temp!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
