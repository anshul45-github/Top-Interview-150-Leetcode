// https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Transpose + Reverse each row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Approach 2: Four-way Swap
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }

        // The outer loop iterates through the matrix "layers", from outside to inside.
        for (int i = 0; i < n / 2; ++i) {
            
            // The inner loop iterates through the elements within the current layer.
            // which in C++ integer arithmetic is `(n + 1) / 2`.
            for (int j = 0; j < (n + 1) / 2; ++j) {
                
                // Store the top-left element in a temporary variable.
                int temp = matrix[i][j];
                
                // Perform the 4-way clockwise swap.

                // Bottom-left moves to Top-left
                matrix[i][j] = matrix[n - 1 - j][i];
                
                // Bottom-right moves to Bottom-left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                
                // Top-right moves to Bottom-right
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                
                // Original Top-left (temp) moves to Top-right
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

// Approach 3: Reverse Rows + Transpose
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        int n = matrix.size();

        // Step 1: Reverse the order of the rows.
        reverse(matrix.begin(), matrix.end());

        // Step 2: Transpose the matrix.
        // This swaps elements across the main diagonal.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};