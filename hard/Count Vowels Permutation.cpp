class Solution {
public:
    int countVowelPermutation(int n) 
    {
        long long a=1,e=1,i=1,o=1,u=1;
        long long MOD=1e9+7;

        for(int j=2;j<=n;j++)
        {
            long long na=(i + e + u)%MOD;
            long long ne=(i%MOD + a%MOD)%MOD;
            long long ni=(e%MOD + o%MOD)%MOD;
            long long no=(i%MOD );
            long long nu=(i%MOD + o%MOD)%MOD;

            a=na;
            e=ne;
            i=ni;
            o=no;
            u=nu;
        }
        return (a%MOD + o%MOD + e%MOD + i%MOD + u%MOD)%MOD;
    }
};
