#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode ** dfs(int left, int right, int *cnt){
    int iTmpForestCnt = 0;
    struct TreeNode **pstTmpForest = NULL;
    if(left > right){
        iTmpForestCnt ++;
        pstTmpForest = (struct TreeNode**)realloc(pstTmpForest, sizeof(struct TreeNode*)*iTmpForestCnt);
        pstTmpForest[iTmpForestCnt-1] = NULL;
    }

    for(int i = left ; i <= right ; i ++){
        int iLeftCnt, iRightCnt;
        struct TreeNode **pstLeftForest = dfs(left, i-1, &iLeftCnt);
        struct TreeNode **pstRightForest = dfs(i+1, right, &iRightCnt);
        for(int j = 0 ; j < iLeftCnt ; j ++){
            for(int k = 0 ; k < iRightCnt ; k ++){
                iTmpForestCnt ++;
                pstTmpForest = (struct TreeNode**)realloc(pstTmpForest, sizeof(struct TreeNode*)*iTmpForestCnt);
                pstTmpForest[iTmpForestCnt-1] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                pstTmpForest[iTmpForestCnt-1]->val = i;
                pstTmpForest[iTmpForestCnt-1]->left = pstLeftForest[j];
                pstTmpForest[iTmpForestCnt-1]->right = pstRightForest[k];
            }
        }
    }
    (*cnt) = iTmpForestCnt;
    return pstTmpForest;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize) {
    if(n <= 0){
        (*returnSize) = 0;
        return NULL;
    }
    return dfs(1, n, returnSize);
}

void print(struct TreeNode *node){
    if(NULL == node){
        printf("NULL ");
        return;
    }
    printf("%d ", node->val);
    printf("left : ");print(node->left);
    printf("right : ");print(node->right);
}

int main(){
    int cnt = 0;
    struct TreeNode ** ans = generateTrees(3, &cnt);
    for(int i = 0 ; i < cnt ; i ++){
        print(ans[i]);
        printf("\n");
    }
    return 0;
}
