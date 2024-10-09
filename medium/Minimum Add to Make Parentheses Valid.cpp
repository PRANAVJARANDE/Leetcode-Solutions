class Solution {
public:
    
int minAddToMakeValid(string s) {
        int ans=0,op=0;
        for(char x:s){
            if(x=='(')op++;
            else{
                if(op)op--;
                else ans++;
            }
        }
        ans+=op;
        return ans;
    }
};
