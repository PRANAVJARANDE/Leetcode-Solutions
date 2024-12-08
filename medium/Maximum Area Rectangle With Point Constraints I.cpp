class Solution {
public:
    int calculateDistance(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + 
               (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
    
    bool isPointInsideOrOnBorder(vector<int>& point, vector<int>& bottomLeft, vector<int>& topRight) {
        return point[0] >= bottomLeft[0] && point[0] <= topRight[0] &&
               point[1] >= bottomLeft[1] && point[1] <= topRight[1];
    }
    
    int rectangleArea(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4, vector<vector<int>>& allPoints) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        
        vector<int> distances;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                distances.push_back(calculateDistance(points[i], points[j]));
            }
        }
        
        sort(distances.begin(), distances.end());
        
        if (distances[0] == distances[1] && distances[2] == distances[3] && distances[4] == distances[5]) {
            vector<int> bottomLeft = {min({p1[0], p2[0], p3[0], p4[0]}), min({p1[1], p2[1], p3[1], p4[1]})};
            vector<int> topRight = {max({p1[0], p2[0], p3[0], p4[0]}), max({p1[1], p2[1], p3[1], p4[1]})};
            
            for (auto& point : allPoints) {
                if (point != p1 && point != p2 && point != p3 && point != p4 && 
                    isPointInsideOrOnBorder(point, bottomLeft, topRight)) {
                    return -1;
                }
            }
            
            int side1 = sqrt(distances[0]);
            int side2 = sqrt(distances[2]);
            return side1 * side2;
        }
        
        return -1;
    }
    
    int maxRectangleArea(vector<vector<int>>& a) {
        int ans = -1;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int z = j + 1; z < n; z++) {
                    for (int y = z + 1; y < n; y++) {
                        int res = rectangleArea(a[i], a[j], a[z], a[y], a);
                        ans = max(ans, res);
                    }
                }
            }
        }
        return ans;        
    }
};
