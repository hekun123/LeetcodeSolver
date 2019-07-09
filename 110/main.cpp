#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int JudgeTreeHeight(struct TreeNode *pcHead){
    if(pcHead == NULL){
        return 0;
    }

    int iLeftLength = JudgeTreeHeight(pcHead->left);
    if(iLeftLength < 0){
        return -1;
    }
    int iRightLength = JudgeTreeHeight(pcHead->right);
    if(iRightLength < 0){
        return -1;
    }
    if(abs(iLeftLength-iRightLength) > 1){
        return -1;
    }
    return iLeftLength>iRightLength?iLeftLength+1:iRightLength+1;
}

bool isBalanced(struct TreeNode* root){
    if(JudgeTreeHeight(root) < 0){
        return false;
    }else{
        return true;
    }
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
//    pcRootTree[4].right = NULL;
//    pcRootTree[8].left = &pcRootTree[9];

    printf("%s\n", isBalanced(&pcRootTree[1])?"YES":"NO");
    return 0;
}
