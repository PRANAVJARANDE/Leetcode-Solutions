class Spreadsheet {
public:

    map<string,int>matrix;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        matrix[cell]=value;
    }
    
    void resetCell(string cell) {
        matrix.erase(cell);
    }
    
    int getValue(string s) 
    {
        int n=s.size();
        int in=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')
            {
                in=i;
                break;
            }
        }
        string s1=s.substr(1,in-1);
        string s2=s.substr(in+1);
        //cout<<s1<<" "<<s2<<endl;
        int ans=0;
        if('A'<=s1[0] && s1[0]<='Z')ans+=matrix[s1];
        else ans+=stoi(s1);
        if('A'<=s2[0] && s2[0]<='Z')ans+=matrix[s2];
        else ans+=stoi(s2);
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
