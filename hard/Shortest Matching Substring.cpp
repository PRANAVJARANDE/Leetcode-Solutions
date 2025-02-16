#include <bits/stdc++.h>
using namespace std;

#define all(ds) (ds).begin(), (ds).end()
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())

class Solution {
public:
    // Function to find all occurrences of a pattern in a string using KMP
    vector<int> findOccurrences(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> lps(m, 0), result;

        if (m == 0) {
            for (int i = 0; i <= n; i++) result.push_back(i);
            return result;
        }

        // Compute LPS array for KMP
        for (int i = 1, j = 0; i < m;) {
            if (p[i] == p[j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Find occurrences of the pattern in the string
        for (int i = 0, j = 0; i < n;) {
            if (s[i] == p[j]) {
                i++, j++;
                if (j == m) {
                    result.push_back(i - m);
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return result;
    }

    // Function to find the shortest substring matching the pattern
    int shortestMatchingSubstring(string s, string p) {
        string p1 = "", p2 = "", p3 = "";
        int in = 1;

        // Split the pattern `p` into three parts based on '*'
        for (auto x : p) {
            if (x == '*') in++;
            else if (in == 1) p1 += x;
            else if (in == 2) p2 += x;
            else p3 += x;
        }

        // Find all occurrences of each pattern part
        vector<int> oc1 = findOccurrences(s, p1);
        vector<int> oc2 = findOccurrences(s, p2);
        vector<int> oc3 = findOccurrences(s, p3);

        int n = s.size(), minLength = INT_MAX;

        // Iterate through all occurrences of the first part
        for (int i1 = 0; i1 < oc1.size(); i1++) {
            int start1 = oc1[i1];
            int i2 = lob(oc2, start1 + p1.size()); // Find the first valid occurrence of p2
            if (i2 == oc2.size()) continue;

            int start2 = oc2[i2];
            int i3 = lob(oc3, start2 + p2.size()); // Find the first valid occurrence of p3
            if (i3 == oc3.size()) continue;

            int start3 = oc3[i3];
            minLength = min(minLength, start3 + (int)p3.size() - start1);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
