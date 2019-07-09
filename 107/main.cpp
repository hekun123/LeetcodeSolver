#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeQueue{
    struct TreeNode *node;
    int level;
};

void swap(int **ans, int *col, int num){
    for(int i = 0 ; i < num/2 ; i ++){
        int *temp = ans[i];
        ans[i] = ans[num-1-i];
        ans[num-1-i] = temp;

        int temp2 = col[i];
        col[i] = col[num-1-i];
        col[num-1-i] = temp2;
    }
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(root == NULL){
        (*columnSizes) = NULL;
        (*returnSize) = 0;
        return NULL;
    }

    //¹¹Ôìqueue£º³¤¶È£¿
    const int queueLen = 10000;
    struct TreeQueue bfsQueue[queueLen];
    int top = 0;
    int bottom = 0;

    bfsQueue[bottom].node = root;
    bfsQueue[bottom].level = 1;
    bottom = (bottom+1)%queueLen;

    int **sAns = NULL;
    int *vCol = NULL;
    int iNum = 0;
    int iCurLevel = 0;

    while(top != bottom){
        struct TreeQueue *pstPtr = &bfsQueue[top];
        if(iCurLevel != pstPtr->level){
            iNum ++;
            sAns = (int **) realloc(sAns, sizeof(int *)*iNum);
            sAns[iNum-1] = NULL;
            vCol = (int *) realloc(vCol, sizeof(int)*iNum);
            vCol[iNum-1] = 0;
            iCurLevel ++;
        }
        vCol[iNum-1] ++;
        sAns[iNum-1] = (int *) realloc(sAns[iNum-1], sizeof(int)*(vCol[iNum-1]));
        sAns[iNum-1][vCol[iNum-1]-1] = pstPtr->node->val;
        //printf("%d ", pstPtr->node->val);

        if(pstPtr->node->left){
            bfsQueue[bottom].level = pstPtr->level+1;
            bfsQueue[bottom].node = pstPtr->node->left;
            bottom = (bottom+1)%queueLen;
        }
        if(pstPtr->node->right){
            bfsQueue[bottom].level = pstPtr->level+1;
            bfsQueue[bottom].node = pstPtr->node->right;
            bottom = (bottom+1)%queueLen;
        }
        top = (top + 1) % queueLen;
    }

    swap(sAns, vCol, iNum);

    (*columnSizes) = vCol;
    (*returnSize) = iNum;
    return sAns;
}

int main(){

    struct TreeNode node[11];
    for(int i = 0 ; i < 11 ; i ++){
        node[i].val= i;
        node[i].left = NULL;
        node[i].right = NULL;
    }
    for(int i = 1 ; i <= 4 ; i ++){
        node[i].left = &node[i<<1];
        node[i].right = &node[i<<1|1];
    }
    node[5].left = &node[10];
    node[2].right = NULL;

    int *col;
    int num;
    int **ans = levelOrderBottom(&node[1], &col, &num);
    for(int i = 0 ; i < num ; i ++){
        for(int j = 0 ; j < col[i] ; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
