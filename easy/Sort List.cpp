class Solution {
public:

void mergee(vector<int> &v1,int l,int r,int mid)
{
    int n1=mid-l+1;
    int n2=r-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++)
    {
        arr1[i]=v1[l+i];
    }

    for(int i=0;i<n2;i++)
    {
        arr2[i]=v1[mid+1+i];
    }

    int k=l;
    int p1=0;
    int p2=0;
    while(p1<n1 && p2<n2)
    {
        if(arr1[p1]<arr2[p2])
        {
            v1[k]=arr1[p1];
            p1++;
            k++;
        }
        else
        {
            v1[k]=arr2[p2];
            p2++;
            k++;
        }
    }

    while(p1<n1)
    {
        v1[k]=arr1[p1];
        p1++;
        k++;
    }

    while(p2<n2)
    {
        v1[k]=arr2[p2];
        p2++;
        k++;
    }
}

void breakk(vector<int> &v1,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        breakk(v1,l,mid);
        breakk(v1,mid+1,r);
        mergee(v1,l,r,mid);
    }
}



    vector<int> sortArray(vector<int>& nums) 
    {
        breakk(nums,0,nums.size()-1);
        return nums;
    }
};
