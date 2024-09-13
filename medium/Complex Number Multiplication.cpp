class Solution {
public:

    pair<int,int> getnum(string s)
    {
        int x=s.find("+");
        s.pop_back();
        int a=stoi(s.substr(0,x));
        int b=stoi(s.substr(x+1));
        return {a,b};
    }

    string complexNumberMultiply(string s, string s1) 
    {
        pair<int,int> p1=getnum(s);
        pair<int,int> p2=getnum(s1);
        int a=p1.first;
        int b=p1.second;
        int c=p2.first;
        int d=p2.second;
        return to_string(a*c-b*d)+"+"+to_string(a*d+b*c)+"i";
    }

    
};
