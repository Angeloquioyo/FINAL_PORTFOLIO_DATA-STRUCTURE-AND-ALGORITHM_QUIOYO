#include <iostream>
#include <vector>
using namespace std;

int countPathsMemo(vector<vector<int>>& mat, int row, int col, int cost, vector<vector<vector<int>>>& memo) {
  
    if (row < 0 || col < 0) return 0;
    
    if (row == 0 && col == 0) return (mat[0][0] == cost) ? 1 : 0;

    if (memo[row][col][cost] != -1)
        return memo[row][col][cost];

    int pathsFromAbove = countPathsMemo(mat, row - 1, col, cost - mat[row][col], memo);
    int pathsFromLeft = countPathsMemo(mat, row, col - 1, cost - mat[row][col], memo);

    memo[row][col][cost] = pathsFromAbove + pathsFromLeft;
    return memo[row][col][cost];
}

int main() {
    vector<vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };
    
    int targetCost = 25;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(targetCost + 1, -1)));

    int result = countPathsMemo(matrix, rows - 1, cols - 1, targetCost, memo);

    cout << "Number of paths with cost " << targetCost << " = " << result << endl;
    return 0;
}
