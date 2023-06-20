class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
    vector<bool> rowFlag(n, 1), colFlag(n, 1);
    long long ans = 0, rowRemain = n, colRemain = n;
    for(int i = q.size()-1; i >= 0; --i){
        if(q[i][0] == 0 && rowFlag[q[i][1]]) { ans += colRemain * q[i][2];    rowFlag[q[i][1]] = 0; rowRemain--; }
        if(q[i][0] == 1 && colFlag[q[i][1]]) { ans += rowRemain * q[i][2];    colFlag[q[i][1]] = 0; colRemain--; }
    }
    return ans;
}
};
