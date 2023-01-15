class Solution {
	public:
		vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
		   vector<vector<int>> mat(n, vector<int>(n)), diff(n + 1, vector<int>(n + 1));

		for (auto q : queries) {
			int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
			diff[row1][col1]++;
			diff[row1][col2 + 1]--;
			diff[row2 + 1][col1]--;
			diff[row2 + 1][col2 + 1]++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] += diff[i][j];
				if (i > 0) mat[i][j] += mat[i - 1][j];
				if (j > 0) mat[i][j] += mat[i][j - 1];
				if (i > 0 && j > 0) mat[i][j] -= mat[i - 1][j - 1];
			}
		}

		return mat;
		}
	};
