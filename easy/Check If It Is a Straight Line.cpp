class Solution {

public:

    bool checkStraightLine(vector<vector<int>>& arr) 

    {

        int dy=arr[0][1]-arr[1][1],dx=arr[0][0]-arr[1][0];

        for(int i=0;i<arr.size();i++)

        {

            int x=arr[i][0];

            int y=arr[i][1];

            if(dy*(x-arr[1][0])!=dx*(y-arr[1][1]))

            {

                return 0;

            }

        }

        return 1;

    }

};
