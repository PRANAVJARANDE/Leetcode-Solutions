class Solution {
public:
    bool canBeEqual(string s1, string s2) 
    {
            char ch1=s1[0],ch2=s1[1],ch3=s1[2],ch4=s1[3];
            if((ch1==s2[0] && ch3==s2[2]) || (ch1==s2[2] && ch3==s2[0]))
            {
                 if((ch2==s2[1] && ch4==s2[3]) || (ch2==s2[3] && ch4==s2[1]))
                 {
                         return 1;
                 }
                 return 0;
            }
            return 0;
        
    }
};
