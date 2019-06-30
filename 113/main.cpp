#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int **v2ReturnAns;
int *vReturnCol;
int iReturnCnt;

void hasPathSum(struct TreeNode* root, int *vTempAns, int sum, int iStep) {
    sum = sum - root->val;
    vTempAns[iStep-1] = root->val;
    if(root->left == NULL && root->right == NULL){
        if(sum == 0){
            ++ iReturnCnt;
            v2ReturnAns = ( int **) realloc(v2ReturnAns, sizeof(int *)*iReturnCnt);
            v2ReturnAns[iReturnCnt-1] = (int *) malloc(sizeof(int)*iStep);
            vReturnCol = (int *) realloc(vReturnCol, sizeof(int)*iReturnCnt);
            vReturnCol[iReturnCnt-1] = iStep;
            for(int i = 0 ; i < iStep; ++ i){
                v2ReturnAns[iReturnCnt-1][i] = vTempAns[i];
            }
            return ;
        }
    }
    if(root->left) hasPathSum(root->left, vTempAns, sum, iStep+1);
    if(root->right) hasPathSum(root->right, vTempAns, sum, iStep+1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    if(root == NULL){
        (*returnSize) = 0;
        (*returnColumnSizes) = NULL;
        return NULL;
    }
    v2ReturnAns = NULL;
    vReturnCol = NULL;
    iReturnCnt = 0;

    int iTreeHeight = TreeDepth(root);
    int vTmpAns[iTreeHeight+1];
    hasPathSum(root, vTmpAns, sum, 1);
    (*returnSize) = iReturnCnt;
    (*returnColumnSizes) = vReturnCol;
    return v2ReturnAns;
}



int main(){
    struct TreeNode pcTreeNode[6];
    int iNum[] = {7,0,-1,-6,1,-7};
    for(int i = 0 ; i < (int) sizeof(iNum)/sizeof(int) ; ++ i){
        pcTreeNode[i].val = iNum[i];
        pcTreeNode[i].left = NULL;
        pcTreeNode[i].right = NULL;
    }
//    pcTreeNode[0].left = &pcTreeNode[1];
//    pcTreeNode[0].right = &pcTreeNode[2];
//    pcTreeNode[1].left = &pcTreeNode[3];
//    pcTreeNode[2].left = &pcTreeNode[4];
//    pcTreeNode[2].right = &pcTreeNode[5];
//    pcTreeNode[3].left = &pcTreeNode[6];
//    pcTreeNode[3].right = &pcTreeNode[7];
//    pcTreeNode[5].left = &pcTreeNode[8];
//    pcTreeNode[5].right = &pcTreeNode[9];

    pcTreeNode[0].left = &pcTreeNode[1];
    pcTreeNode[1].left = &pcTreeNode[2];
    pcTreeNode[1].right = &pcTreeNode[3];
    pcTreeNode[2].left = &pcTreeNode[4];
    pcTreeNode[4].left = &pcTreeNode[5];
    int **vAns = NULL;
    int *vCol = NULL;
    int iSize = 0;
    vAns = pathSum(&pcTreeNode[0], 0, &iSize, &vCol);
    for(int i = 0 ; i < iSize; ++ i){
        for(int j = 0 ; j < vCol[i]; ++ j){
            printf("%d ", vAns[i][j]);
        }
        printf("\n");
    }
    return 0;
}
