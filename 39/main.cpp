#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** returnAns;
int * colSize;
int cnt;

void dfs(int *candidates, int candidatesSize, int target, int tmpAns, int val, int *num, int num_len, int min) {

    int i;
    num[num_len] = val;
    tmpAns += val;
    if(tmpAns == target) {
        //get 返回正确结果
        cnt ++;
        returnAns = (int **)realloc(returnAns, cnt*sizeof(int *));
        returnAns[cnt-1] = (int *)malloc(sizeof(int)*num_len+1);
        for(i = 0 ; i <= num_len ; i ++) {
            returnAns[cnt-1][i] = num[i];
        }
        colSize = (int *)realloc(colSize, cnt*sizeof(int ));
        colSize[cnt-1] = num_len+1;
        return;
    }else if(tmpAns > target){
        //回溯
        return;
    }

    for(i = min ; i < candidatesSize ; i ++) {
        dfs(candidates, candidatesSize, target, tmpAns, candidates[i], num, num_len+1, i);
    }
}

int compare(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa > *pb;
}

bool is_same(int *a, int *b, int len){
    int i, flag;
    flag = 1;
    for(i = 0 ; i < len ; i ++) {
        if(a[i] != b[i]){
            flag = 0;
        }
    }
    return flag;
}

void rmv_dup(){
    if(cnt <= 1)return;
    int i, j, flag;
    int len = cnt;
    cnt = 1;
    qsort(returnAns[0], colSize[0], sizeof(int), compare);
    for(i = 1 ; i < len; i ++ ) {
        qsort(returnAns[i], colSize[i], sizeof(int), compare);
        flag = 0;
        for(j = 0 ; j < cnt; j ++){
            if(colSize[i] == colSize[j]) {
                if(is_same(returnAns[i], returnAns[j], colSize[i])) {
                    flag = 1;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            returnAns[cnt] = returnAns[i];
            colSize[cnt ++] = colSize[i];
        }
    }

}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int i;
    cnt = 0;
    returnAns = NULL;
    colSize = NULL;
    int *temp_ans = (int *)malloc(sizeof(int)*1000);
    memset(temp_ans, 0, sizeof(int)*1000);
    for(i = 0 ; i < candidatesSize ; i ++) {
        dfs(candidates, candidatesSize, target, 0, candidates[i], temp_ans, 0, i);
    }

    //rmv_dup();

    *returnSize = cnt;
    (*columnSizes) = colSize;
    return returnAns;
}

int main() {
    int a[] = {2,3,5};
    int *b;
    int ans_len;
    int **ans = combinationSum(a, 3, 8, &b, &ans_len);
    //printf("%d\n", ans_len);
    for(int i = 0 ; i < ans_len ; i ++){
      //  printf("%d\n", b[i]);
        for(int j = 0 ; j < b[i]; j ++){
            printf("%d\t", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
