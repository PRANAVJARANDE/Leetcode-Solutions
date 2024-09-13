class Solution {
public:


    void mergee(vector<pair<int,int>> &arr,int l,int r,int mid,vector<int> &count)
    {
        int i=l;
        int j=mid+1;
        int k=0;
        vector<pair<int,int>> v1(r-l+1);
        while(i<=mid && j<=r)
        {
            if(arr[i].first <= arr[j].first)
            {
                v1[k]=arr[j];
                k++;
                j++;
            }
            else
            {
                count[arr[i].second]=count[arr[i].second]+r-j+1;
                v1[k]=arr[i];
                k++;
                i++;
            }
            
        }

        while(i<=mid)
        {
            v1[k]=arr[i];
            k++;
            i++;
        }
        while(j<=r)
        {
            v1[k]=arr[j];
            k++;
            j++;
        }

        for(int z=l;z<=r;z++)
        {
            arr[z]=v1[z-l];
        }
    }


    void breakk(vector<pair<int,int>> &arr,int l,int r,vector<int> &count)
    {
        if(l>=r)
        {
            return;
        }
            int mid=l+(r-l)/2;
            breakk(arr,l,mid,count);
            breakk(arr,mid+1,r,count);
            mergee(arr,l,r,mid,count);
        
    }

    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> count(nums.size(),0);
        vector<pair<int,int>> f;
        for(int i=0;i<nums.size();i++)
        {
            f.push_back({nums[i],i});
        }
        breakk(f,0,nums.size()-1,count);
        return count;
    }
};
