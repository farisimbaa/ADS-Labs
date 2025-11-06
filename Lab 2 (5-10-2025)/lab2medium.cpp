// Given a row-wise sorted matrix mat[][] with an odd number of rows and columns, 
// find the median of the matrix.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int median(vector<vector<int>> &mat) {
    
    // Flatten the matrix into a single array
    vector<int> arr;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            arr.push_back(mat[i][j]);
        }
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Find the median element
    int mid = arr.size() / 2;
    return arr[mid];
}


int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30},
        {5, 15, 25},
        {1, 2, 3}
    };

    int med = median(matrix);
    cout << "The median is: " << med << endl;

    return 0;
}