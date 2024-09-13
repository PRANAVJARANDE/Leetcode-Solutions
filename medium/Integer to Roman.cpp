class Solution {
public:

    string units(int n)
    {
        switch(n)
        {
            case 0: return "";
            case 1: return "I";
            case 2: return "II";
            case 3: return "III";
            case 4: return "IV";
            case 5: return "V";
            case 6: return "VI";
            case 7: return "VII";
            case 8: return "VIII";
            case 9: return "IX";
        }
        return "";
    }

    string tens(int n)
    {
        switch(n)
        {
            case 0: return "";
            case 1: return "X";
            case 2: return "XX";
            case 3: return "XXX";
            case 4: return "XL";
            case 5: return "L";
            case 6: return "LX";
            case 7: return "LXX";
            case 8: return "LXXX";
            case 9: return "XC";
        }
        return "";
    }

    string hund(int n)
    {
        switch(n)
        {
            case 0: return "";
            case 1: return "C";
            case 2: return "CC";
            case 3: return "CCC";
            case 4: return "CD";
            case 5: return "D";
            case 6: return "DC";
            case 7: return "DCC";
            case 8: return "DCCC";
            case 9: return "CM";
        }
        return "";
    }

    string thou(int n)
    {
        switch(n)
        {
            case 0: return "";
            case 1: return "M";
            case 2: return "MM";
            case 3: return "MMM";
        }
        return "";
    }

    string intToRoman(int n) 
    {
        string ans="";
        ans=ans+units(n%10);
        n/=10;
        ans=tens(n%10)+ans;
        n/=10;
        ans=hund(n%10)+ans;
        n/=10;
        ans=thou(n%10)+ans;
        return ans;
    }
};
