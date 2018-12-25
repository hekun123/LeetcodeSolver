#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hori_visit[10][10];
int vert_visit[10][10];
int sqar_visit[10][10];
int flag;

void init(char **board) {
    memset(hori_visit, 0, sizeof(hori_visit));
    memset(vert_visit, 0, sizeof(vert_visit));
    memset(sqar_visit, 0, sizeof(sqar_visit));
    int i, j, k, s_i, s_j;
    for(i = 0 ; i < 9 ; i += 3){
        for(j = 0 ; j < 9 ; j += 3) {
            for(s_i = i; s_i < i+3; s_i ++) {
                for(s_j = j; s_j < j+3; s_j ++) {
                    if(board[s_i][s_j] == '.')continue;
                    sqar_visit[((s_i/3)*3)+(s_j/3)][ board[s_i][s_j] - '0'] = 1;
                }
            }
        }
    }
    for(i = 0 ; i < 9 ; i ++){
        for(j =  0; j < 9 ; j ++){
            if(board[i][j] == '.')continue;
            hori_visit[i][board[i][j]-'0'] = 1;
        }
        for(k = 0 ; k < 9 ; k ++) {
            if(board[k][i] == '.')continue;
            vert_visit[i][board[k][i]-'0'] = 1;
        }
    }
}

int *get_intersection(int x, int y){
    int i, sq_num, cnt;
    int *ans = (int *)malloc(sizeof(int)*10);
    for(i = 0 ; i < 10 ; i ++){
        ans[i] = 0;
    }
    sq_num = ((x/3)*3)+(y/3);
    cnt = 1;
    for(i = 1 ; i < 10 ; i ++){
        if(hori_visit[x][i] == 0 &
           vert_visit[y][i] == 0 &
            sqar_visit[sq_num][i] == 0){
            ans[cnt ++] = i;
        }
    }
    ans[0] = cnt;
    return ans;
}

void fill_board(char **board, int x, int y){
    if(flag)return;
    if(board[x][y] != '.'){
        if(x == 8 && y == 8){
            flag = 1;
            return ;
        }
        if(x%2 == 0){
            if(y+1 >= 9){
                fill_board(board, x+1, y);
            }else {
                fill_board(board, x, y+1);
            }
        }else {
            if(y == 0){
                fill_board(board, x+1, y);
            }else {
                fill_board(board, x, y-1);
            }
        }
    }else {
        int *num_candi = get_intersection(x, y);
        int cnt = num_candi[0], i;
        if(cnt == 1)return ;
        for(i = 1; i < cnt; i ++){
            if(flag){
                break;
            }
            hori_visit[x][num_candi[i]] = 1;
            vert_visit[y][num_candi[i]] = 1;
            sqar_visit[(x/3)*3+(y/3)][num_candi[i]] = 1;
            board[x][y] = num_candi[i] + '0';

            if(x == 8 && y == 8){
                flag = 1;
                return ;
            }

            if(x%2 == 0){
                if(y+1 >= 9){
                    fill_board(board, x+1, y);
                }else {
                    fill_board(board, x, y+1);
                }
            }else {
                if(y == 0){
                    fill_board(board, x+1, y);
                }else {
                    fill_board(board, x, y-1);
                }
            }
            if(flag)return;
            hori_visit[x][num_candi[i]] = 0;
            vert_visit[y][num_candi[i]] = 0;
            sqar_visit[(x/3)*3+(y/3)][num_candi[i]] = 0;
            board[x][y] = '.';
        }
    }
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {

    init(board);
    flag = 0;
    fill_board(board, 0, 0);
}

int main() {
    char board[][20] = {
        {"53..7...."},
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

    solveSudoku(a, 9, 9);
    for(int i = 0 ; i < 9 ; i ++) {
        for(int j = 0 ; j < 9 ; j ++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
