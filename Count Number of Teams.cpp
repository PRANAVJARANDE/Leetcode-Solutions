#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& a) {
        int n=a.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = 0;
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i]) {
                    ++l;
                }
            }
            for (int k = i + 1; k < n; ++k) {
                if (a[k] > a[i]) {
                    ++r;
                }
            }
            count += l * r;
        }

        for (int i = 0; i < n; ++i) {
            int l = 0, r = 0;
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[i]) {
                    ++l;
                }
            }
            for (int k = i + 1; k < n; ++k) {
                if (a[k] < a[i]) {
                    ++r;
                }
            }
            count += l * r;
        }

        return count;
    }
};
