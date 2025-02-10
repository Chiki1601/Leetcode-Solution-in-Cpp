#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& matrix) {
        // Map to store diagonals, where key is the difference of row and column index
        map<int, vector<int>> diagonalMap;
        int rows = matrix.size(), cols = matrix[0].size();

        // Traverse the matrix and group elements by their diagonal (row - col)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                diagonalMap[i - j].push_back(matrix[i][j]);
            }
        }

        // Sort each diagonal; diagonals with negative keys are sorted in ascending order,
        // while diagonals with positive keys are sorted in descending order
        for (auto& entry : diagonalMap) {
            if (entry.first < 0) 
                sort(entry.second.begin(), entry.second.end());
            else 
                sort(entry.second.rbegin(), entry.second.rend());
        }

        // Populate the sorted values back into the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = diagonalMap[i - j].front();
                diagonalMap[i - j].erase(diagonalMap[i - j].begin());
            }
        }

        return matrix;
    }
};
