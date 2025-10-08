class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        long long n=spells.size();
        long long m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            //for this spell[i]
            // spell[i]*postion[j]=success
            //postion[i] == ceil(success/spell[i])
            long long req=success/spells[i];
            if(success%spells[i])req++;
            long long in=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            long long rem=m-in;
            ans[i]=rem;
        }
        return ans;
    }
};
