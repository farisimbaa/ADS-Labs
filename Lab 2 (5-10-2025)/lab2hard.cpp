// Given a m*n grid with each cell consisting of positive, negative, or no points i.e., zero points. 
// From a cell (i, j) we can move to (i+1, j) or (i, j+1) and we can move to a cell only if we have positive points ( > 0 ) when we move to that cell. 
// Whenever we pass through a cell, points in that cell are added to our overall points. 
// The task is to find the minimum initial points to reach cell (m-1, n-1) from (0, 0).

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Recursive function to find minimum initial points needed at cell i,j
int minPoint(int i, int j, vector<vector<int>> &points) {

    // Base case 1: Out of bounds
    if (i < 0 || i == points.size() || j < 0 || j == points[0].size())
        return INT_MAX; // Return a large value for invalid paths

    // Base case 2: At destination cell (bottom-right)
    if (i == points.size() - 1 && j == points[0].size() - 1) {

        // If positive or zero, need at least 1 point to stay positive
        if (points[i][j] > 0)
            return 1;

        // If negative, we need |value| + 1 points to stay positive
        return abs(points[i][j]) + 1;
    }

    // Recursively find minimum points needed for right and down paths
    int right = minPoint(i, j + 1, points);
    int down = minPoint(i + 1, j, points);

    // Take minimum of both paths
    int minExitPoints = min(right, down);

    return max(1, minExitPoints - points[i][j]);
}

// Helper function to initiate the recursive solution
int minPoints(vector<vector<int>> points) {
    int m = points.size(), n = points[0].size();

    return minPoint(0, 0, points);
}

int main() {
    vector<vector<int>> points = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    cout << "Minimum initial points needed: " << minPoints(points) << endl;

    return 0;
}