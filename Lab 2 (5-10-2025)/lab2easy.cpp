// Given a m x n matrix. The problem is to sort the given matrix in strict order. 
// Here strict order means that the matrix is sorted in a way such that all elements 
// in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= m-1, 
// the first element is greater than or equal to the last element of row 'i-1'.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortMatrix(vector<vector<int>>& mat) {
    vector<int> temp;
    
    // Flatten the matrix into a single vector
    for (auto& row : mat) {
        for (int x : row) {
            temp.push_back(x);
        }
    }
    
    // Sort the vector
    sort(temp.begin(), temp.end());
    
    // Put sorted values back into the matrix
    int i = 0;
    for (auto& row : mat) {
        for (int& x : row) {
            x = temp[i++];
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    sortMatrix(matrix);

    cout << "Sorted Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}