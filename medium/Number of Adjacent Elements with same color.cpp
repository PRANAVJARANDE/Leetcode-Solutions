class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& que) 
    {
        int qs = que.size();
        vector<int> ans(qs, 0);
        vector<int> arr(n, 0);
        int cur = 0;

        for (int i = 0; i < qs; i++)
        {
            int in = que[i][0];
            int col = que[i][1];
            
            if (arr[in] == 0)
            {
                arr[in] = col;
                if (in != 0) cur += (arr[in - 1] == col) ? 1 : 0;
                if (in != n - 1) cur += (arr[in + 1] == col) ? 1 : 0;
            }
            else
            {
                int pcol = arr[in];
                if (in != 0) cur -= (arr[in - 1] == pcol) ? 1 : 0;
                if (in != n - 1) cur -= (arr[in + 1] == pcol) ? 1 : 0;
                arr[in] = col;
                if (in != 0) cur += (arr[in - 1] == col) ? 1 : 0;
                if (in != n - 1) cur += (arr[in + 1] == col) ? 1 : 0;
            }
            ans[i] = cur;
        }
        return ans;
    }
};
