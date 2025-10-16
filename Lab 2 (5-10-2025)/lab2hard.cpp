// Given a m*n grid with each cell consisting of positive, negative, or no points i.e., zero points. 
// From a cell (i, j) we can move to (i+1, j) or (i, j+1) and we can move to a cell only if we have positive points ( > 0 ) when we move to that cell. 
// Whenever we pass through a cell, points in that cell are added to our overall points. 
// The task is to find the minimum initial points to reach cell (m-1, n-1) from (0, 0).

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minInitialPoints(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    // Base case: at the destination cell (m-1, n-1)
    dp[m-1][n-1] = max(1, 1 - grid[m-1][n-1]);

    // Fill the last row
    for (int j = n - 2; j >= 0; j--) {
        dp[m-1][j] = max(1, dp[m-1][j+1] - grid[m-1][j]);
    }

    // Fill the last column
    for (int i = m - 2; i >= 0; i--) {
        dp[i][n-1] = max(1, dp[i+1][n-1] - grid[i][n-1]);
    }

    // Fill the rest of the dp table
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int down = max(1, dp[i+1][j] - grid[i][j]);
            int right = max(1, dp[i][j+1] - grid[i][j]);
            dp[i][j] = min(down, right);
        }
    }

    return dp[0][0];
}

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the elements of the grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = minInitialPoints(grid);
    cout << "Minimum initial points required: " << result << endl;

    return 0;
}