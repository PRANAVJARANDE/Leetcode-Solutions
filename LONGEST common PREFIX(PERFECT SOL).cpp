class Solution 
{
public:
    string longestCommonPrefix(vector<string>& arr) 
    {
        string ans="";
        int lmin=arr[0].size();
        

       if(arr.size()==1)
       {
           ans=arr[0];
           return ans;
       }

        for(int j=0;j<lmin;j++)
        {
            int k=1;
            char ch;
            for(int i=0;i<arr.size()-1;i++)
            {
                ch=arr[i][j];
                if(arr[i][j]==arr[i+1][j])
                {
                    k++;
                }
                else
                {
                    return ans;
                }

                if(k==arr.size())
                {
                    ans=ans+ch;
                }

            }

        }

        return ans;

    }
};
