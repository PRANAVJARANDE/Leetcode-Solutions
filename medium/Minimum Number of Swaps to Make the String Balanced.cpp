class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ans=0;
        int ac=0;
        for(char x:s)
        {
            if(x==']')
            {
                if(ac)ac--;
                else 
                {
                    ac++;
                    ans++;  
                }  
            }  
            else
            {
                ac++;
            } 
        }
        return ans;
    }
};
