class Solution {
public:

    int diyears(int year)
    {
        if(year%4==0)
        {
            return 366;
        }
        return 365;
    }

    int dimonth(int n,int y)
    {
        if(n>=8)
        {
            if(n%2==0)
            {
                return 31;
            }
            return 30;
        }
        else
        {
            if(n%2==1)
            {
                return 31;
            }
            if(n==2)
            {
                if(y%4==0)
                {
                    return 29;
                }
                return 28;
            }
            return 30;
        }
    }

    string dayyy(int n)
    {
        switch(n)
        {
            case 1: return "Friday";
            case 2: return "Saturday";
            case 3: return "Sunday";
            case 4: return "Monday";
            case 5: return "Tuesday";
            case 6: return "Wednesday";
            case 0: return "Thursday";
        }
        return "";
    }

    string dayOfTheWeek(int day, int month, int year) 
    {
        int d=0;
        for(int i=1971;i<year;i++)
        {
            d=d+diyears(i);
        }
        for(int i=1;i<month;i++)
        {
            d=d+dimonth(i,year);
        }
        d=d+day;
        if(year==2100 && month>2)
        {
            d--;
        }
        d=d%7;
        return dayyy(d);
    }
};
