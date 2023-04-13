class Solution {
public:
    vector<int> searchRange(vector<int>&arr, int t) 
    {
        int l=0;
        int r=arr.size()-1;

        int in=-1;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==t)
            {
                in=mid;
                break;
            }
            else if(arr[mid]>t)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        int fi;
        int li;
        vector<int> v1;

        if(in==-1)
        {
            v1.push_back(-1);
            v1.push_back(-1);
            return v1;
        }

        int k=in;
        
        while(k>=0 && arr[k]==t)
        {
            k--;
        }

        fi=k+1;

        int lo=in;
        while(lo<arr.size() && arr[lo]==t )
        {
            lo++;
        }

        li=lo-1;

        
        v1.push_back(fi);
        v1.push_back(li);

        
        return v1;


    }
};
