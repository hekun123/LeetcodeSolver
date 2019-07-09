#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int min(int a, int b){
    return a>b?b:a;
}

int minDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    if(root->left == NULL){
        return minDepth(root->right)+1;
    }
    if(root->right == NULL){
        return minDepth(root->left)+1;
    }

    int iLeft = minDepth(root->left);
    int iRight = minDepth(root->right);

    return min(iLeft, iRight)+1;
}


int main(){
    struct TreeNode pcRootTree[10];
    for(int i = 0; i < 10; ++ i){
        pcRootTree[i].val = i;
        pcRootTree[i].left = NULL;
        pcRootTree[i].right = NULL;
    }
    for(int i = 1; i <= 4 ; ++ i){
        pcRootTree[i].left = &pcRootTree[i<<1];
        pcRootTree[i].right = &pcRootTree[i<<1|1];
    }
    pcRootTree[1].left = NULL;
    pcRootTree[3].left = NULL;
    pcRootTree[3].right = NULL;
    pcRootTree[2].left = NULL;
    pcRootTree[2].right = NULL;
    printf("%d\n", minDepth(&pcRootTree[1]));

    return 0;
}
