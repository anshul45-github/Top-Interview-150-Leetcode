// https://leetcode.com/problems/valid-sudoku/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            vector<bool> vis1(9, false);
            vector<bool> vis2(9, false);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '0' + 1;
                    if(vis1[idx])
                        return false;
                    vis1[idx] = true;
                }
                if(board[j][i] != '.') {
                    int idx = board[j][i] - '0' + 1;
                    if(vis2[idx])
                        return false;
                    vis2[idx] = true;
                }
            }
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                vector<bool> vis(9, false);
                for(int k = i; k < i + 3; k++) {
                    for(int col = j; col < j + 3; col++) {
                        if(board[k][col] != '.') {
                            int idx = board[k][col] - '0' + 1;
                            if(vis[idx])
                                return false;
                            vis[idx] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};