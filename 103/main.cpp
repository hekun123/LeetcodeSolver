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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int nodeNum = 0;
    struct TreeNode *nodePtr = root;
    if(root == NULL){
        (*columnSizes) = NULL;
        (*returnSize) = 0;
        return NULL;
    }

    //¹¹Ôìqueue£º³¤¶È£¿
    const int queueLen = 10000;
    struct TreeQueue bfsQueue[queueLen];
    int TreeLevelStack[queueLen];
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
            if(iNum != 0 && iCurLevel%2 == 0){
                sAns[iNum-1] = (int *) malloc(sizeof(int)*vCol[iNum-1]);
                for(int i = 0 ; i < vCol[iNum-1]; i ++){
                    sAns[iNum-1][i] = TreeLevelStack[vCol[iNum-1]-1 - i];
                }
            }
            iNum ++;
            sAns = (int **) realloc(sAns, sizeof(int *)*iNum);
            sAns[iNum-1] = NULL;
            vCol = (int *) realloc(vCol, sizeof(int)*iNum);
            vCol[iNum-1] = 0;
            iCurLevel ++;
        }
        vCol[iNum-1] ++;
        if(iCurLevel % 2){
            sAns[iNum-1] = (int *) realloc(sAns[iNum-1], sizeof(int)*(vCol[iNum-1]));
            sAns[iNum-1][vCol[iNum-1]-1] = pstPtr->node->val;
        }else{
            TreeLevelStack[vCol[iNum-1]-1] = pstPtr->node->val;
        }


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
    if(iCurLevel%2 == 0){
        sAns[iNum-1] = (int *) malloc(sizeof(int)*vCol[iNum-1]);
        for(int i = 0 ; i < vCol[iNum-1]; i ++){
            sAns[iNum-1][i] = TreeLevelStack[vCol[iNum-1]-1 - i];
        }
    }
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
    node[4].left = NULL;

    int *col;
    int num;
    int **ans = zigzagLevelOrder(&node[1], &col, &num);
    for(int i = 0 ; i < num ; i ++){
        for(int j = 0 ; j < col[i] ; j ++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
