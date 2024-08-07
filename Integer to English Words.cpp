class Solution {
public:

    string decode(int n)
    {
        switch(n) {
        case 1: return "One ";
        case 2: return "Two ";
        case 3: return "Three ";
        case 4: return "Four ";
        case 5: return "Five ";
        case 6: return "Six ";
        case 7: return "Seven ";
        case 8: return "Eight ";
        case 9: return "Nine ";
        case 10: return "Ten ";
        case 11: return "Eleven ";
        case 12: return "Twelve ";
        case 13: return "Thirteen ";
        case 14: return "Fourteen ";
        case 15: return "Fifteen ";
        case 16: return "Sixteen ";
        case 17: return "Seventeen ";
        case 18: return "Eighteen ";
        case 19: return "Nineteen ";
        case 20: return "Twenty ";
        case 30: return "Thirty ";
        case 40: return "Forty ";
        case 50: return "Fifty ";
        case 60: return "Sixty ";
        case 70: return "Seventy ";
        case 80: return "Eighty ";
        case 90: return "Ninety ";
        default: return "";
        }
    }

    string d3(int a,int b,int c)
    {
        string ans="";
        if(a!=0)
        {
            ans+=decode(a)+"Hundred ";
        }
        if(b==1)
        {
            ans+=decode(b*10+c);
        }
        else
        {
            if(b!=0)
            {
                ans+=decode(b*10);
            }
            if(c!=0)
            {
                ans+=decode(c);
            }
        }
        return ans;
    }

    string trimEnd(string str) {
        string result = str;
        result.erase(find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), result.end());
        return result;
    }


    string numberToWords(int n) {
        if(n==0)
        {
            return "Zero";
        }
        vector<int> a;
        while(n!=0)
        {
            int rem=n%10;
            a.push_back(rem);
            n/=10;
        }
        while(a.size()!=10)
        {
            a.push_back(0);
        }
        reverse(a.begin(),a.end());
        string ans="";
        if(a[0]!=0)
        {
            ans+=decode(a[0])+"Billion ";
        }

        string ta=d3(a[1],a[2],a[3]);
        if(ta.size()!=0)
        {
            ans+=ta+"Million ";
        }
        ta=d3(a[4],a[5],a[6]);
        if(ta.size()!=0)
        {
            ans+=ta+"Thousand ";
        }
        ta=d3(a[7],a[8],a[9]);
        if(ta.size()!=0)
        {
            ans+=ta;
        }
        
        return trimEnd(ans);
    }
};
