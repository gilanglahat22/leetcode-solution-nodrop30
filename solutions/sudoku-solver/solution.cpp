class Solution {
    public:
    
        void solveSudoku(vector<vector<char>>& board) {
            int countPosCell[9][9];
            for(int i = 0; i<9; i++) for(int j = 0; j<9; j++) countPosCell[i][j] = 9;
            queue<pair<int,int>> qe;
            int posibilityVal[9][9];
            for(int i = 0; i<9; i++) for(int j = 0; j<9; j++) posibilityVal[i][j] = -1;
            for(int i = 0; i<9; i++){
                for(int j = 0; j<9; j++){
                    if(board[i][j]!="."){
                        countPosCell[i][j] = 0;
                    }else{
                        int count = 0;
                        for(int k = i-1; k>=0; k--) if(board[k][j]!=".") count++;
                        for(int k = i+1; k<9; k++)  if(board[k][j]!=".") count++;
                        for(int l = j-1; l>=0; l--)  if(board[i][l]!=".") count++;
                        for(int l = j+1; l<9; l++)  if(board[i][l]!=".") count++;
                        int startY = i/3, startX = j/3;
                        for(int y = 0; y<3; y++){
                            for(int x = 0; x<3; x++){
                                if(board[startY+y][startX+x]!=".") count++;
                            }
                        }
                        countPosCell[9][9] = count;
                    }
    
                    if(countPosCell[i][j]==1){
                        qe.push({i,j});
                        
                    }
                }
            }
    
            while(!qe.empty()){
                pair<int,int> tempDel = qe.pop();
                int x = tempDel.second;
                int y = tempDel.first;
                board[y][x] = 
                int tempDec = -1;
                for(int k = y-1; k>=0; k--) {
                    countPosCell[k][x]--;
                    tempDec = countPosCell[k][x];
                    qe.push(tempDec);
                }
                for(int k = y+1; k<9; k++) {
                    countPosCell[k][x]--;
                    tempDec = countPosCell[k][x];
                    qe.push(tempDec);
                }
                for(int l = x-1; l>=0; l--) {
                    countPosCell[y][l]--;
                    tempDec = countPosCell[y][l];
                    qe.push(tempDec);
                }
                for(int l = x+1; l<9; l++) {
                    countPosCell[y][l]--;
                    tempDec = countPosCell[y][l];
                    qe.push(tempDec);
                }
                int startY = y/3, startX = x/3;
                for(int y = 0; y<3; y++) for(int x = 0; x<3; x++) {
                    countPosCell[startY+y][startX+x]--;
                    tempDec = countPosCell[startY+y][startX+x];
                    qe.push(tempDec);
                }
            }
        }
    };