class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans = 1;
        sort(points.begin(), points.end());
        int idx = points[0][0]; // starting point of rectangle
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] - idx > w){
                ans++; // increment the recangle needed by one
                idx = points[i][0]; // update the starting point
            }
        }
        return ans;
    }
};
