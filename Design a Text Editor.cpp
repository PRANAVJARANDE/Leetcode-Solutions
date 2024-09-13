class TextEditor {
public:

    string a="";
    int ind=0;

    TextEditor() {
        
    }
    
    void addText(string text) {
        a.insert(ind,text);
        ind+=text.size();
    }
    
    int deleteText(int k) {
        
        if(ind<k)
        {
            a.erase(0,ind);
            int res=ind;
            ind=0;
            return res;
        }
        a.erase(ind-k,k);
        ind-=k;
        return k;
    }
    
    string cursorLeft(int k) {
        
        if(ind<=k)
        {
            ind=0;
            return "";
        }
        ind-=k;
        if(ind<10)
        {
            return a.substr(0,ind);
        }
        else
        {
            return a.substr(ind-10,10);
        }
    }
    
    string cursorRight(int k) {
        if(ind+k<=a.size())
        {
            ind+=k;
        }
        else
        {
            ind=a.size();
        }
        if(ind<10)
        {
            return a.substr(0,ind);
        }
        else
        {
            return a.substr(ind-10,10);
        }

    }
};
