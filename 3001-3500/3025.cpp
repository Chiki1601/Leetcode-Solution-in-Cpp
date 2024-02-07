class Solution {
public:

    // custom compare function 
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]) return true;
        else if(a[0] > b[0]) return false;
        return a[1] >= b[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), cnt = 0;

        // custom sort to get all upper-left elements before lower-right
        sort(points.begin(), points.end(), compare);


        // for points[i] & points[j] count all such pairs where
        // no points[k] is present in between them
        // that's our answer
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i != j && points[i][0] <= points[j][0] && points[i][1] >= points[j][1]){
                    bool flag = false;
                    for(int k=i+1; k<n; k++){
                        if(k != i && k != j && (points[k][0] >= points[i][0] && points[k][0] <= points[j][0]) && (points[k][1] <= points[i][1] && points[k][1] >= points[j][1])){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) cnt++;
                }
            }
        }
        return cnt;
    }
};
