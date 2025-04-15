class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            int countPosCell[9][9];
            queue<pair<int, int>> qe;
    
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        countPosCell[i][j] = 0;
                    } else {
                        vector<bool> present(9, false);
                        for (int k = 0; k < 9; k++) {
                            if (k != j && board[i][k] != '.') {
                                present[board[i][k] - '1'] = true;
                            }
                        }
                        for (int k = 0; k < 9; k++) {
                            if (k != i && board[k][j] != '.') {
                                present[board[k][j] - '1'] = true;
                            }
                        }
                        int startY = (i / 3) * 3;
                        int startX = (j / 3) * 3;
                        for (int y = startY; y < startY + 3; y++) {
                            for (int x = startX; x < startX + 3; x++) {
                                if ((y != i || x != j) && board[y][x] != '.') {
                                    present[board[y][x] - '1'] = true;
                                }
                            }
                        }
                        int cnt = 0;
                        for (bool p : present) if (p) cnt++;
                        countPosCell[i][j] = 9 - cnt;
                    }
                    if (countPosCell[i][j] == 1) {
                        qe.push({i, j});
                    }
                }
            }
    
            while (!qe.empty()) {
                auto front = qe.front();
                qe.pop();
                int y = front.first;
                int x = front.second;
                if (board[y][x] != '.') continue;
    
                vector<bool> present(9, false);
                for (int k = 0; k < 9; k++) {
                    if (board[y][k] != '.' && k != x) {
                        present[board[y][k] - '1'] = true;
                    }
                }
                for (int k = 0; k < 9; k++) {
                    if (board[k][x] != '.' && k != y) {
                        present[board[k][x] - '1'] = true;
                    }
                }
                int startY = (y / 3) * 3;
                int startX = (x / 3) * 3;
                for (int i = startY; i < startY + 3; i++) {
                    for (int j = startX; j < startX + 3; j++) {
                        if ((i != y || j != x) && board[i][j] != '.') {
                            present[board[i][j] - '1'] = true;
                        }
                    }
                }
                int numToPlace = -1;
                for (int num = 0; num < 9; num++) {
                    if (!present[num]) {
                        numToPlace = num;
                        break;
                    }
                }
                if (numToPlace == -1) continue;
                board[y][x] = '1' + numToPlace;
    
                for (int j = 0; j < 9; j++) {
                    if (board[y][j] == '.') {
                        vector<bool> present_new(9, false);
                        // Check row
                        for (int k = 0; k < 9; k++) {
                            if (k != j && board[y][k] != '.') {
                                present_new[board[y][k] - '1'] = true;
                            }
                        }
                        for (int k = 0; k < 9; k++) {
                            if (k != y && board[k][j] != '.') {
                                present_new[board[k][j] - '1'] = true;
                            }
                        }
                        int cellStartY = (y / 3) * 3;
                        int cellStartX = (j / 3) * 3;
                        for (int yy = cellStartY; yy < cellStartY + 3; yy++) {
                            for (int xx = cellStartX; xx < cellStartX + 3; xx++) {
                                if ((yy != y || xx != j) && board[yy][xx] != '.') {
                                    present_new[board[yy][xx] - '1'] = true;
                                }
                            }
                        }
                        int cnt = 0;
                        for (bool p : present_new) if (p) cnt++;
                        int oldCount = countPosCell[y][j];
                        countPosCell[y][j] = 9 - cnt;
                        if (oldCount != 1 && countPosCell[y][j] == 1) {
                            qe.push({y, j});
                        }
                    }
                }
                for (int i = 0; i < 9; i++) {
                    if (board[i][x] == '.') {
                        vector<bool> present_new(9, false);
                        for (int k = 0; k < 9; k++) {
                            if (k != x && board[i][k] != '.') {
                                present_new[board[i][k] - '1'] = true;
                            }
                        }
                        for (int k = 0; k < 9; k++) {
                            if (k != i && board[k][x] != '.') {
                                present_new[board[k][x] - '1'] = true;
                            }
                        }
                        int cellStartY = (i / 3) * 3;
                        int cellStartX = (x / 3) * 3;
                        for (int yy = cellStartY; yy < cellStartY + 3; yy++) {
                            for (int xx = cellStartX; xx < cellStartX + 3; xx++) {
                                if ((yy != i || xx != x) && board[yy][xx] != '.') {
                                    present_new[board[yy][xx] - '1'] = true;
                                }
                            }
                        }
                        int cnt = 0;
                        for (bool p : present_new) if (p) cnt++;
                        int oldCount = countPosCell[i][x];
                        countPosCell[i][x] = 9 - cnt;
                        if (oldCount != 1 && countPosCell[i][x] == 1) {
                            qe.push({i, x});
                        }
                    }
                }
                int boxStartY = (y / 3) * 3;
                int boxStartX = (x / 3) * 3;
                for (int i = boxStartY; i < boxStartY + 3; i++) {
                    for (int j = boxStartX; j < boxStartX + 3; j++) {
                        if (board[i][j] == '.') {
                            vector<bool> present_new(9, false);
                            for (int k = 0; k < 9; k++) {
                                if (k != j && board[i][k] != '.') {
                                    present_new[board[i][k] - '1'] = true;
                                }
                            }
                            for (int k = 0; k < 9; k++) {
                                if (k != i && board[k][j] != '.') {
                                    present_new[board[k][j] - '1'] = true;
                                }
                            }
                            int cellStartY = (i / 3) * 3;
                            int cellStartX = (j / 3) * 3;
                            for (int yy = cellStartY; yy < cellStartY + 3; yy++) {
                                for (int xx = cellStartX; xx < cellStartX + 3; xx++) {
                                    if ((yy != i || xx != j) && board[yy][xx] != '.') {
                                        present_new[board[yy][xx] - '1'] = true;
                                    }
                                }
                            }
                            int cnt = 0;
                            for (bool p : present_new) if (p) cnt++;
                            int oldCount = countPosCell[i][j];
                            countPosCell[i][j] = 9 - cnt;
                            if (oldCount != 1 && countPosCell[i][j] == 1) {
                                qe.push({i, j});
                            }
                        }
                    }
                }
            }
    
            backtrack(board);
        }
    
    private:
        bool backtrack(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        vector<bool> possible(9, true);
                        for (int k = 0; k < 9; k++) {
                            if (board[i][k] != '.') possible[board[i][k] - '1'] = false;
                        }
                        for (int k = 0; k < 9; k++) {
                            if (board[k][j] != '.') possible[board[k][j] - '1'] = false;
                        }
                        int startY = (i / 3) * 3;
                        int startX = (j / 3) * 3;
                        for (int y = startY; y < startY + 3; y++) {
                            for (int x = startX; x < startX + 3; x++) {
                                if (board[y][x] != '.') possible[board[y][x] - '1'] = false;
                            }
                        }
                        for (int num = 0; num < 9; num++) {
                            if (possible[num]) {
                                board[i][j] = '1' + num;
                                if (backtrack(board)) {
                                    return true;
                                }
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    };