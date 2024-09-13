class Solution {
public:
    int findDuplicate(vector<int>& arr) 
    {
        int l=arr.size();
        vector<int> co(l,0);

        for(int i=0;i<l;i++)
        {
            co[arr[i]]++;
            if(co[arr[i]]==2)
            {
                return arr[i];
            }
        }

        return 0;
        
    }
}
