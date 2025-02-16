#include <vector>
#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision

using namespace std;

class Solution {
public:
    double calculateAreaAbove(const vector<vector<int>>& squares, double y) {
        double area = 0.0;
        for (const auto& square : squares) {
            double bottom = square[1];
            double side = square[2];
            double top = bottom + side;

            if (top > y) {
                double overlapHeight = top - max(y, bottom);
                area += overlapHeight * side;
            }
        }
        return area;
    }

    double calculateAreaBelow(const vector<vector<int>>& squares, double y) {
        double area = 0.0;
        for (const auto& square : squares) {
            double bottom = square[1];
            double side = square[2];
            double top = bottom + side;

            if (bottom < y) {
                double overlapHeight = min(y, top) - bottom;
                area += overlapHeight * side;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = 0.0, r = 1e9;
        r *= 2;
        const double EPS = 1e-6;
        double ans = l;
        while (r - l > EPS) {
            double mid = l + ((r - l) / 2.0);
            double ab = calculateAreaAbove(squares, mid);
            double bel = calculateAreaBelow(squares, mid);

            if (ab <= bel) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
