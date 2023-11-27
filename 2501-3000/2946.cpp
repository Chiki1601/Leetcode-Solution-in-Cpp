class Solution {
public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){ 
            int newInd = (j + n + k) % n;
            if(mat[i][j] != mat[i][newInd]) return false;
        }
    }
    return true;
}
};
