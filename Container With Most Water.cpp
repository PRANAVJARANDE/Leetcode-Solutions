class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int i=0,water=0,h=0;
        int j=arr.size()-1;
        while(i<j)
        {
            h=min(arr[i],arr[j]);
            water=max(water,(j-i)*h);

            if(i<j && h>=arr[i])
            {
                i++;
            }
            if(i<j && h>=arr[j])
            {
                j--;
            }
        }
        return water;
    }
};
