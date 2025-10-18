class Solution {
public:
    int minSwapsCouples(vector<int>& a) 
    {
        int n=a.size();
        map<int,int>m;
        for(int i=0;i<n;i++)m[a[i]]=i;

        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            if(min(a[i],a[i+1])+1==max(a[i],a[i+1]) && min(a[i],a[i+1])%2==0)continue;
            int p1=a[i];
            int p2=a[i+1];
            int ch;
            if(p1%2)ch=p1-1;
            else ch=p1+1;
            swap(a[i+1],a[m[ch]]);
            swap(m[p2],m[ch]);
            ans++;
        }
        return ans;   
    }
};
