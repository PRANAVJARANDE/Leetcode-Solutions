sc=o(1)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) 
    {
        int xs=0;
        for(int i=0;i<arr.size();i++)
        {
            xs=xs^arr[i];
        }
        if(xs==0)
        {
            return 1;
        }
        return 0;
    }
};










//sc-: o(n)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) 
    {
        vector<int> org(arr.size(),0);

        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]==1)
            {
                if(org[i]==1)
                {
                    org[i+1]=0;
                }
                else
                {
                    org[i+1]=1;
                }
            }
            else
            {
                if(org[i]==1)
                {
                    org[i+1]=1;
                }
                else
                {
                    org[i+1]=0;
                }
            }
        }


        if(org[arr.size()-1] ^ org[0]==arr[arr.size()-1])
        {
            return 1;
        }
        return 0;
        
    }
};
