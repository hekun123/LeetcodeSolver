#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dirtX[] = {-1, 1, 0, 0};
int dirtY[] = {0, 0, -1, 1};
int flag;

void dfs(char **board, int boardRowSize, int boardColSize, char *word, int step, int **visit, int x, int y){
    if(step == strlen(word)){
        flag = 1;
        return;
    }
    for(int i = 0 ; i < 4 ; i ++){
        int x_tmp = x+dirtX[i];
        int y_tmp = y+dirtY[i];
        if(x_tmp >= 0 && y_tmp >= 0 && x_tmp < boardRowSize && y_tmp < boardColSize &&
                        visit[x_tmp][y_tmp] != 1 && word[step] == board[x_tmp][y_tmp]){
            visit[x_tmp][y_tmp] = 1;
            dfs(board, boardRowSize, boardColSize, word, step+1, visit, x_tmp, y_tmp);
            if(flag){
                return;
            }
            visit[x_tmp][y_tmp] = 0;
        }
    }
}
int directions[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool go(char **board, int rows, int cols, int x, int y, const char *word) {
    if (!*word) return true;
    if (x < 0 || y < 0 || x >= rows || y >= cols || board[x][y] != *word) return false;

    char tmp = board[x][y];
    board[x][y] = 0;
    for (int i = 0; i < sizeof(directions) / sizeof(*directions); i++)
        if (go(board, rows, cols, x + directions[i][0], y + directions[i][1], word + 1)) return true;
    board[x][y] = tmp;
    return false;
}

bool exist2(char **board, int rows, int cols, const char *word) {
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++)
        if (go(board, rows, cols, i, j, word)) return true;
    return false;
}
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
        return exist2(board, boardRowSize, boardColSize, word);
//    int len = strlen(word);
//    if(len==0 || boardRowSize*boardColSize <len) return false;
//
//    int **visit = (int **)malloc(sizeof(int *)*boardRowSize);
//    for(int i = 0 ; i < boardRowSize ; i ++){
//        visit[i] = (int *)malloc(sizeof(int)*boardColSize);
//        for(int j = 0 ; j < boardColSize ; j ++){
//            visit[i][j] = 0;
//        }
//    }
//    flag = 0;
//    for(int i = 0 ; i < boardRowSize ; i ++){
//        for(int j = 0 ; j < boardColSize ; j ++){
//            if(board[i][j] == word[0]){
//                visit[i][j] = 1;
//                dfs(board, boardRowSize, boardColSize, word, 1, visit, i, j);
//                if(flag){
//                    return true;
//                }
//                visit[i][j] = 0;
//            }
//        }
//    }
//    return flag;
}



int main(){
    char map[][100] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    char *a[100];
    int n = 3;
    int m = 4;
    for( int i = 0 ; i < n ; i ++){
        a[i] = map[i];
    }
    char word[] = {"ABCCED"};
    bool ans = exist(a, n, m, word);
    printf("%s\n", ans?"YES":"NO");

    return 0;
}
