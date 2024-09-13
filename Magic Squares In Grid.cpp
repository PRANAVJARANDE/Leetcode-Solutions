class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;

        
        auto isMagic = [&](int i, int j) {
            vector<int> count(10, 0);
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (a[r][c] < 1 || a[r][c] > 9) return false;
                    count[a[r][c]]++;
                }
            }
            for (int k = 1; k <= 9; k++) {
                if (count[k] != 1) return false;
            }

            int rs1 = a[i][j] + a[i][j+1] + a[i][j+2];
            int rs2 = a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
            int rs3 = a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            int cs1 = a[i][j] + a[i+1][j] + a[i+2][j];
            int cs2 = a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
            int cs3 = a[i][j+2] + a[i+1][j+2] + a[i+2][j+2];
            int d1 = a[i][j] + a[i+1][j+1] + a[i+2][j+2];
            int d2 = a[i][j+2] + a[i+1][j+1] + a[i+2][j];
            return (rs1 == rs2 && rs2 == rs3 && rs3 == cs1 && cs1 == cs2 && cs2 == cs3 && cs3 == d1 && d1 == d2);
        };

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isMagic(i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
