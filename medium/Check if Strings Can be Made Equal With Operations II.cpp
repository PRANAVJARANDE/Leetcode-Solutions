class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
            int n=s1.size();
            vector<int> v1(26,0);
            vector<int> v2(26,0);
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                        v1[s1[i]-'a']++;
                        v1[s2[i]-'a']--;
                }
                else
                {
                        v2[s1[i]-'a']++;
                        v2[s2[i]-'a']--;
                }
            }
            for(int i=0;i<26;i++)
            {
                    if(v1[i]!=0 || v2[i]!=0)
                    {
                            return 0;
                    }
            }
            return 1;
    }
};
