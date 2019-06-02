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

int TreeDepth(struct TreeNode *node){
    if(node == NULL){
        return 0;
    }
    int leftDepth = TreeDepth(node->left);
    int rightDepth = TreeDepth(node->right);

    return (leftDepth>rightDepth?leftDepth:rightDepth)+1;
}

void dfs(struct TreeNode *node, int iStep, int **vAns, int *vCol){
    if(node == NULL){
        return ;
    }
    dfs(node->left, iStep-1, vAns, vCol);
    vCol[iStep] ++;
    vAns[iStep] = (int *)realloc(vAns[iStep], sizeof(int)*vCol[iStep]);
    vAns[iStep][vCol[iStep]-1] = node->val;
    dfs(node->right, iStep-1, vAns, vCol);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(root == NULL){
        (*columnSizes) = NULL;
        (*returnSize) = 0;
        return NULL;
    }
    int iLevelNum = TreeDepth(root);
    int **vAns = (int **)calloc( iLevelNum, sizeof(int *));
    int *vCol = (int *)calloc(iLevelNum, sizeof(int));
    dfs(root, iLevelNum-1, vAns, vCol);

    (*columnSizes) = vCol;
    (*returnSize) = iLevelNum;
    return vAns;
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
    //node[2].right = NULL;
    node[4].left = node[4].right = NULL;
    node[5].left = node[5].right = NULL;

    int *vCol;
    int iNum;
    int **vAns = levelOrderBottom(&node[1], &vCol, &iNum);
    for(int i = 0 ; i < iNum ; i ++){
        for(int j = 0; j < vCol[i]; j ++){
            printf("%d ", vAns[i][j]);
        }
        printf("\n");
    }

    return 0;
}

