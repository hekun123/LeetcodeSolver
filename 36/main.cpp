#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_square_ok(char **board, int x, int y){
    int i, j;
    int visit[10];
    memset(visit, 0, sizeof(visit));
    for(i = x-2 ; i <= x ; i ++){
        for(j = y-2 ; j <= y ; j ++) {
            if(board[i][j] == '.')continue;
            if(visit[board[i][j] - '0']){
                return false;
            }else {
                visit[board[i][j] - '0'] = 1;
            }
        }
    }
    return true;
}

bool is_vertical_ok(char **board, int x) {
    int i;
    int visit[10];
    memset(visit, 0, sizeof(visit));
    for(i = 0 ; i < 9 ; i ++) {
        if(board[i][x] == '.')continue;
        if(visit[board[i][x] - '0']){
            return false;
        }else {
            visit[board[i][x] - '0'] = 1;
        }
    }
    return true;
}
bool is_horizontal_ok(char **board, int x) {
    int i;
    int visit[10];
    memset(visit, 0, sizeof(visit));
    for(i = 0 ; i < 9 ; i ++) {
        if(board[x][i] == '.')continue;
        if(visit[board[x][i] - '0']){
            return false;
        }else {
            visit[board[x][i] - '0'] = 1;
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j;
    bool flag = true;
    for(i = 2 ; i < 9 ; i += 3) {
        for(j = 2 ; j < 9 ; j += 3) {
            flag = is_square_ok(board, i, j);
            if(!flag)return flag;
        }
    }

    for(i = 0 ; i < 9 ; i ++){
        flag = is_horizontal_ok(board, i);
        if(!flag)return flag;
        flag = is_vertical_ok(board, i);
        if(!flag)return flag;
    }
    return flag;
}

int main() {
    char board[][20] = {
        {"43..7...."},
        {"6..195..."},
        {".98....6."},
        {"8...6...3"},
        {"4..8.3..1"},
        {"7...2...6"},
        {".6....28."},
        {"...419..5"},
        {"....8..79"}
    };
    char **a;
    a = (char **)malloc(sizeof(char *)*10);
    for(int i = 0 ; i < 9 ; i ++){
        a[i] = (char *)malloc(sizeof(char)*10);
        memcpy(a[i], board[i], 10);
    }
    printf("%s\n", isValidSudoku(a, 9, 9)?"true":"false");
    return 0;
}
