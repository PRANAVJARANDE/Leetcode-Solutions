class Solution {
public:


        char pcharr(char ch)
        {
                if(ch=='a')
                        return 'z';
                else
                {
                        return ch-1;
                }
        }

        
        
    bool canMakeSubsequence(string s1, string s2) 
    {
            int k=0;
            int n1=s2.size();
           for(int i=0;i<s1.size();i++)
           {
                   if(s1[i]==s2[k] || s1[i]==pcharr(s2[k]))
                   {
                           k++;
                   }
                   if(k==n1)
                   {
                           return 1;
                   }
           }
            if(k==n1)
                {
                        return 1;
                }
            return 0;
            
        
    }
};
