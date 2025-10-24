class Solution {
public:
    vector<int> threeEqualParts(vector<int>& a)
    {
        int n=a.size();
        int pv=0;
        int j=n-1;
        while(j>=0 && a[j]==0)
        {
            j--;
            pv++;
        }
        if(pv==n)return {0,2};

        //atleast 1 one exists

        int oc=0;
        for(int i=0;i<n;i++)if(a[i]==1)oc++;
        if(oc%3!=0)return {-1,-1};

        //oc is multiple of 3
        int div=oc/3;

        map<int,vector<int>>m;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                m[cnt%div].push_back(i);
                cnt++;
            }
        }

        for(int i=1;i<div;i++)
        {
            for(int j=1;j<3;j++)
            {
                if((m[i][j]-m[i][j-1])!=(m[0][j]-m[0][j-1]))
                {
                    return {-1,-1};
                }
            }
        }

        //diff are good
        //check for consecutive ones
        vector<int>ans;
        for(int z=0;z<2;z++)
        {
            //div-1
            int in=m[div-1][z]+1;
            int cnt=pv;
            while(cnt--)
            {
                if(a[in]==1)return {-1,-1};
                in++;
            }
            if(z==0)ans.push_back(in-1);
            else ans.push_back(in);
        }
        return ans;
    }
};
