class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char, int> minLens;
        int secondMin = INT_MAX, count = 0;

        for(size_t i = 0; i < points.size(); ++i) {
            int len = max(abs(points[i][0]), abs(points[i][1]));
            char c = s[i];

            if(minLens.find(c) == minLens.end()) {
                minLens[c] = len;
            } else if(len < minLens[c]) {
                secondMin = min(secondMin, minLens[c]); 
                minLens[c] = len;
            } else {
                secondMin = min(secondMin, len);
            }
        }

        for(auto& pair : minLens) {
            if(pair.second < secondMin) {
                count++;
            }
        }

        return count;
    }
};
