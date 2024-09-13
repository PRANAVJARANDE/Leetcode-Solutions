class WordDictionary {
public:

    class node
    {
        public:
        bool endd;
        node* next[26];
        node()
        {
            endd=0;
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
        }
    };
    
    node* trie;
    WordDictionary() {
        trie=new node();
    }
    
    void addWord(string s) {
        int i=0;
        node* temp=trie;
        while(i<s.size())
        {
            if(temp->next[s[i]-'a']==NULL)
            {
                temp->next[s[i]-'a']=new node();
            }
            temp=temp->next[s[i]-'a'];
            i++;
        }
        temp->endd=1;
    }

    bool helper(int i,string s,node* temp)
    {
        if(temp==NULL)
        {
            return 0;
        }
        if(i==s.size())
        {
            if(temp->endd==1)return 1;
            return 0;
        }
        
        bool nx=0;
        if(s[i]=='.')
        {
            for(int j=0;j<26;j++)
            {
                bool b=helper(i+1,s,temp->next[j]);
                if(b==1)return 1;
            }
            return 0;
        }
        else
        {
            return helper(i+1,s,temp->next[s[i]-'a']);
        }
       
    }
    
    bool search(string s) {
        return helper(0,s,trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
