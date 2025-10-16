// Given a m x n matrix. The problem is to sort the given matrix in strict order. 
// Here strict order means that the matrix is sorted in a way such that all elements 
// in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= m-1, 
// the first element is greater than or equal to the last element of row 'i-1'.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Flatten the matrix into a single vector
    vector<int> flat_matrix;
    for (const auto& row : matrix) {
        flat_matrix.insert(flat_matrix.end(), row.begin(), row.end());
    }

    // Sort the flattened vector
    sort(flat_matrix.begin(), flat_matrix.end());

    // Reconstruct the sorted matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = flat_matrix[i * n + j];
        }
    }

    // Print the sorted matrix
    cout << "Sorted matrix in strict order:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}