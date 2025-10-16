// Given a row-wise sorted matrix mat[][] with an odd number of rows and columns, 
// find the median of the matrix.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int countLessEqual(const vector<vector<int>>& matrix, int mid) {
    int count = 0;
    for (const auto& row : matrix) {
        count += upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    return count;
}

int findMedian(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int left = INT_MAX;
    int right = INT_MIN;

    for (const auto& row : matrix) {
        left = min(left, row[0]);
        right = max(right, row[m - 1]);
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countLessEqual(matrix, mid) < (n * m + 1) / 2) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix (row-wise sorted):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int median = findMedian(matrix);
    cout << "The median of the matrix is: " << median << endl;

    return 0;
}