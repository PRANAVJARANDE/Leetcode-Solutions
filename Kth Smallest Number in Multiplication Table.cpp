
Time Complexity- O(mlog(mn))

class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        int l=1;
        int r=m*n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int count=0;
            for(int i=1;i<=m;i++)
            {
                count=count+min(n,mid/i);
            }
            if(count>=k)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};




















Time Complexity- O(n*n*logn)

class Solution {
public:
    int findKthNumber(int m, int n, int k) 
    {
        priority_queue<int> q1;

        for(int i=1;i<=min(m,n);i++)
        {
            q1.push(i*i);
                if(q1.size()>k)
                {
                    q1.pop();
                }
            for(int j=i+1;j<=n;j++)
            {
                q1.push(i*j);
                if(q1.size()>k)
                {
                    q1.pop();
                }
            }
            for(int j=i+1;j<=m;j++)
            {
                q1.push(i*j);
                if(q1.size()>k)
                {
                    q1.pop();
                }
            }
        }
        return q1.top();
    }
};
