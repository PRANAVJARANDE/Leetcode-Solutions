class Solution 
{

public:
    vector<string> gett(int n)
    {
        vector<string> v1;
        switch(n)
        {
            case 2: v1={"a","b","c"};
                    return v1;
            case 3: v1={"d","e","f"};
                    return v1;
            case 4: v1={"g","h","i"};
                    return v1;
            case 5: v1={"j","k","l"};
                    return v1;
            case 6: v1={"m","n","o"};
                    return v1;
            case 7: v1={"p","q","r","s"};
                    return v1;
            case 8: v1={"t","u","v"};
                    return v1;
            case 9: v1={"w","x","y","z"};
                    return v1;
        }
        return v1;
    }


    vector<string> combinationof2(vector<string> a,vector<string> b)
    {
        vector<string> v1;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                string ans=a[i]+b[j];
                v1.push_back(ans);
            }
        }
        return v1;
    }


    vector<string> letterCombinations(string arr) 
    {
        vector<string> ans;
        if(arr.size()==0)
        {
            return ans;
        } 
        if(arr.size()==1)
        {
            int a=arr[0]-'0';
            return gett(a);
        }        

        vector<string> co=combinationof2(gett(arr[0]-'0'),gett(arr[1]-'0'));
        for(int i=2;i<arr.size();i++)
        {
            co=combinationof2(co,gett(arr[i]-'0'));
        }
        return co;

    }
};
