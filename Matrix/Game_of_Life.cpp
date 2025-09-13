// https://leetcode.com/problems/game-of-life

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int neighbours = 0;
                for(auto& dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2))
                        neighbours++;
                }
                if(board[i][j] == 1 && (neighbours < 2 || neighbours > 3))
                    board[i][j] = 2;
                if(board[i][j] == 0 && neighbours == 3)
                    board[i][j] = -1;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == -1)
                    board[i][j] = 1;
                else if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};